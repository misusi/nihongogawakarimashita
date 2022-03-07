#ifndef NETWORK_H
#define NETWORK_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>
#include <iostream>



class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0);
    ~Network();
    void sendNetworkSignalDeepl();
    void sendNetworkSignalRomajiDesu();

    QNetworkAccessManager* getManagerDeepl();
    QNetworkAccessManager* getManagerRomajiDesu();
    void sendRequestDeepl(std::string authKey, std::string textToTranslate, std::string sourceLang, std::string targetLang);
    void sendRequestRomajiDesu(QString message);

signals:
    void replyReadyDeepl(const QString& arg);
    void replyReadyRomajiDesu(const QString& arg);

private:
    QNetworkAccessManager *m_managerDeepl;
    QNetworkAccessManager *m_managerRomajiDesu;
    QString m_replyTextDeepl;
    QString m_replyTextRomajiDesu;
    const QString m_baseUrlDeepl = "https://api-free.deepl.com/v2/translate";
    const QString m_baseUrlRomajiDesu = "https://www.romajidesu.com/dictionary/meaning-of-";  /* Finish with +"ひらがな.html" */
};

#endif // NETWORK_H
