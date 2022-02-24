#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }

            QJsonParseError err;
            QJsonDocument doc(QJsonDocument::fromJson(reply->readAll(), &err));
            setTranslatedText(doc.object()["translations"].toArray().first()
                    .toObject().value("text").toString().toStdString());
        }
    );

    setAuthKeyFromFile();
    baseUrl = "https://api-free.deepl.com/v2/translate";
    //    request.setHeader(QNetworkRequest::ContentLengthHeader, textToTranslate.length());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::UserAgentHeader, "buffaloshittranslator");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}



void MainWindow::on_pushButtonSwitch_clicked()
{
    int currentSourceIndex = ui->comboBoxSourceLanguage->currentIndex();
    ui->comboBoxSourceLanguage->setCurrentIndex(ui->comboBoxTargetLanguage->currentIndex());
    ui->comboBoxTargetLanguage->setCurrentIndex(currentSourceIndex);
}

QByteArray getJsonFromMessage(std::string message)
{
    QJsonObject obj;
    obj["key1"] = "value1";
    obj["key2"] = "value2";
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    return data;
}

//QNetworkReply* SendRequest(QNetworkAccessManager* manager, QByteArray json)

void MainWindow::on_pushButtonTranslate_clicked()
{
    sendRequest(ui->plainTextEditSource->toPlainText().toStdString());
}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->plainTextEditSource->clear();
    ui->plainTextEditTarget->clear();
    qDebug() << reply->readAll();
}

void MainWindow::setAuthKeyFromFile()
{
    QFile file("deepl_auth_key.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    authKey=in.readLine().toStdString();
    file.close();
}

std::string MainWindow::getSourceLang()
{
    return ui->comboBoxSourceLanguage->currentText().toStdString();
}
std::string MainWindow::getTargetLang()
{
    return ui->comboBoxTargetLanguage->currentText().toStdString();
}

void MainWindow::sendRequest(std::string textToTranslate)
{
    std::string reqStr =
            "&auth_key=" + authKey
            + "&text=" + textToTranslate
            + "&source_lang=" + getSourceLang()
            + "&target_lang=" + getTargetLang();
    request.setUrl(QString::fromStdString(baseUrl));
    //qDebug() << "REQUEST DATA: " << QString::fromStdString(reqStr);
    manager->post(request, QByteArray::fromStdString(reqStr));
}

void MainWindow::setTranslatedText(std::string textToTranslate)
{
    translatedText = textToTranslate;
    ui->plainTextEditTarget->setPlainText(QString::fromStdString(translatedText));
}
