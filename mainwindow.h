#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
#include <iostream>
#include <htmlcxx/html/ParserDom.h>
#include "network.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace htmlcxx;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void receiveNetworkSignalDeepl(const QString& arg);
    void receiveNetworkSignalRomajiDesu(const QString& arg);

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
    Network *network  = new Network();
    HTML::ParserDom *m_htmlParser;
    std::string m_authKey;
    QString m_saveDirectoryPath;
    QString m_authKeyFilePath;
    QFont m_userFont;
    QFont m_defaultFont = QFont("Helvetica", 10);
    const QString m_configPath = "./config.conf";
    const QString m_defaultSaveDir = "./saved_translations";


    QByteArray getJsonFromMessage(std::string message);
    void setAuthKeyFromFile();
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
