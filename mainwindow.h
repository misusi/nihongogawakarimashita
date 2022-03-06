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
#include <QFileInfo>
#include <QFileDialog>
//#include <QTextToSpeech>
//#include <QVoice>
#include <QThread>
#include <QFontDialog>

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

    void on_pushButtonSave_clicked();

    void on_actionSelectAuthKeyLocation_triggered();

    void on_actionSelectTranscriptionSaveLocation_triggered();

    void on_actionShow_Current_Key_Save_Locations_triggered();

    void on_actionChange_Font_Settings_triggered();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *m_manager;
    QNetworkRequest m_request;
    std::string m_replyStr;
    std::string m_authKey;
    std::string m_baseUrl;
    std::string m_translatedText;
    QString m_saveDirectoryPath;
    QString m_authKeyFilePath;
    QFont m_userFont;
    QFont m_defaultFont = QFont("Helvetica", 10);
    const QString m_configPath = "./config.conf";
    const QString m_defaultSaveDir = "./saved_translations";


    QByteArray getJsonFromMessage(std::string message);
    void setAuthKeyFromFile();
    void sendRequest(std::string textToTranslate);
    std::string getTargetLang();
    std::string getSourceLang();
    void setTranslatedText(std::string textToTranslate);
    bool readConfig(QString configPath);
    void writeConfig(QString configPath);
    QString promptForFile(const QString& caption, const QString& filter);
    QString promptForDirectory(const QString& caption);
    void showPopUp(const std::string& title, const std::string& information);

};
#endif // MAINWINDOW_H
