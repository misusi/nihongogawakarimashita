#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QByteArray>
#include <QTimer>
#include <QFileInfo>
#include <QFileDialog>
#include <QInputDialog>
//#include <QTextToSpeech>
//#include <QVoice>
#include <QThread>
#include <QFontDialog>
#include <QFont>
#include <iostream>
#include "network.h"
#include "filer.h"
#include <QTextBrowser>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


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

    void on_actionSelectTranscriptionSaveLocation_triggered();

    void on_actionChange_Font_Settings_triggered();

    void on_actionShow_Current_Key_Save_Locations_triggered();

    void on_actionChange_AuthKey_triggered();

private:
    Ui::MainWindow *ui;
    Network *network  = new Network();
    Filer filer;

    QFont m_userFont;
    QFont m_defaultFont = QFont("Helvetica", 10);

    void setConfigDefaults();
    void setAuthKeyFromFile();
    std::string getTargetLang();
    std::string getSourceLang();
    QString promptForFile(const QString& caption, const QString& filter);
    QString promptForDirectory(const QString& caption);
    void showPopUp(const std::string& title, const std::string& information);
    QString showInputPopUp(const QString title, const QString inputLabel);
    void restoreFocus();


};
#endif // MAINWINDOW_H
