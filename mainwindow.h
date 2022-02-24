#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>
#include <QByteArray>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButtonSwitch_clicked();

    void on_pushButtonTranslate_clicked();

    void on_pushButtonClear_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply* reply;
    std::string replyStr;
    std::string authKey;
    std::string baseUrl;
    std::string translatedText;

    QByteArray getJsonFromMessage(std::string message);
    void setAuthKeyFromFile();
    void sendRequest(std::string textToTranslate);
    std::string getTargetLang();
    std::string getSourceLang();
    void setTranslatedText(std::string textToTranslate);
};
#endif // MAINWINDOW_H
