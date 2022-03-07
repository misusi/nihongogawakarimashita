#include "network.h"

Network::Network(QObject *parent) :
    QObject(parent)
{
    // Create pre-formed managers, requests
    m_managerDeepl = new QNetworkAccessManager();
    m_managerRomajiDesu = new QNetworkAccessManager();

    // Setting up network access manager signals
    QObject::connect(m_managerDeepl, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }
            // Store reply text and send it in a signal
            QJsonParseError err;
            QJsonDocument doc(QJsonDocument::fromJson(reply->readAll(), &err));
            m_replyTextDeepl = doc.object()["translations"].toArray().first()
                    .toObject().value("text").toString();
            sendNetworkSignalDeepl();
        }
    );

    QObject::connect(m_managerRomajiDesu, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }

            // Store reply text and send it in a signal
            m_replyTextRomajiDesu = reply->readAll();
            replyReadyRomajiDesu(m_replyTextRomajiDesu);
        }
    );


}

Network::~Network()
{
    delete m_managerDeepl;
    delete m_managerRomajiDesu;
}

void Network::sendNetworkSignalDeepl()
{
    emit replyReadyDeepl(m_replyTextDeepl);

}

void Network::sendNetworkSignalRomajiDesu()
{
    emit replyReadyRomajiDesu(m_replyTextRomajiDesu);
}


void Network::sendRequestDeepl(
        std::string authKey, std::string textToTranslate, std::string sourceLang, std::string targetLang)
{
    QNetworkRequest req;
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    req.setUrl(m_baseUrlDeepl);

    std::string postDataStr =
            "&auth_key=" + authKey
            + "&text=" + textToTranslate
            + "&source_lang=" + sourceLang
            + "&target_lang=" + targetLang;

    m_managerDeepl->post(req, QByteArray::fromStdString(postDataStr));
}

void Network::sendRequestRomajiDesu(QString text)
{
    QNetworkRequest req(m_baseUrlRomajiDesu + text + ".html");
    m_managerRomajiDesu->get(req);
}

