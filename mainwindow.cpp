#include "mainwindow.h"
#include "ui_mainwindow.h"


// TODO:
// [＋] Remove reading auth key from file, just put it in the config
// [-] Get html parser working
// [-] Add section for RomajiDesu dictionary/sentence examples


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Listen for network reply ready signals
    QObject::connect(network, SIGNAL(replyReadyDeepl(QString)), this, SLOT(receiveNetworkSignalDeepl(QString)));
    QObject::connect(network, SIGNAL(replyReadyRomajiDesu(QString)), this, SLOT(receiveNetworkSignalRomajiDesu(QString)));


    QFileInfo fileInfo("./");
    QString fullPath = fileInfo.canonicalFilePath();

    // Read config
    if (!filer.readConfig())
    {
        // Config not found -- make one
        std::string currentDir = QDir().absolutePath().toStdString();
        showPopUp("Config file does not exist.", "No config found in " + currentDir + ". One will be created.");
        setConfigDefaults();

    }

    // Restore font
    m_userFont = QFont(filer.getFontName(), filer.getFontSize());
    ui->plainTextEditSource->setFont(m_userFont);
    ui->plainTextEditTarget->setFont(m_userFont);
}

void MainWindow::setConfigDefaults()
{
    filer.setAuthKey(showInputPopUp("Enter DeepL AuthKey", "DeepL AuthKey:"));
    filer.setSaveDir();
    QFontInfo info = QFontInfo(m_defaultFont);
    filer.setFontName(info.family());
    filer.setFontSize(info.pointSize());
    // Check if saved_translations exists
    if (!QDir(filer.getSaveDir()).exists()) {
        QDir().mkdir(filer.getSaveDir());
    }
    filer.writeConfig();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete network;
}

void MainWindow::receiveNetworkSignalDeepl(const QString &arg)
{
    ui->plainTextEditTarget->setPlainText(arg);

}

void MainWindow::receiveNetworkSignalRomajiDesu(const QString &arg)
{
    ui->textBrowser->setOpenLinks(false);
    ui->textBrowser->setHtml(arg);
    //QTextBrowser::anchorClicked()
}


void MainWindow::on_pushButtonSwitch_clicked()
{

    // Swap langauge dropdowns
    int currentSourceIndex = ui->comboBoxSourceLanguage->currentIndex();
    ui->comboBoxSourceLanguage->setCurrentIndex(ui->comboBoxTargetLanguage->currentIndex());
    ui->comboBoxTargetLanguage->setCurrentIndex(currentSourceIndex);

    // Swap textbox contents
    QString currentSourceText = ui->plainTextEditSource->toPlainText();
    ui->plainTextEditSource->setPlainText(ui->plainTextEditTarget->toPlainText());
    ui->plainTextEditTarget->setPlainText(currentSourceText);
}



void MainWindow::on_pushButtonTranslate_clicked()
{
    network->sendRequestDeepl(
                filer.getAuthKey().toStdString(),
                ui->plainTextEditSource->toPlainText().toStdString(),
                getSourceLang(),
                getTargetLang());
    network->sendRequestRomajiDesu(ui->plainTextEditSource->toPlainText());
}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->plainTextEditSource->clear();
    ui->plainTextEditTarget->clear();
}



std::string MainWindow::getSourceLang()
{
    return ui->comboBoxSourceLanguage->currentText().toStdString();
}

std::string MainWindow::getTargetLang()
{
    return ui->comboBoxTargetLanguage->currentText().toStdString();
}

void MainWindow::on_pushButtonSave_clicked()
{
    // Make unique filename
    const QString timestamp = QDateTime::currentDateTime().toString(QLatin1String("yyyyMMdd-hhmmsszzz"));
    const QString fileName = filer.getSaveDir() + "/" + "saved_transcript_" + timestamp + ".txt";
    // Try to open file
    QFile file(fileName);
    if(file.open(QFile::WriteOnly | QFile::Text)) {
        // Get full path
        QFileInfo fileInfo(file);
        QString fullPath = fileInfo.canonicalFilePath();
        // Write to file
        QTextStream stream(&file);
        stream << QString::fromStdString(getSourceLang()) << "\n";
        stream << ui->plainTextEditSource->toPlainText() << "\n";
        stream << QString::fromStdString(getTargetLang()) << "\n";
        stream << ui->plainTextEditTarget->toPlainText();
        // Show popup
        showPopUp("Saved Translation", "Translation has been saved to " + fullPath.toStdString());
        file.close();
    }
    else{
        showPopUp("Error", "Translation could not be saved.");
    }
}

void MainWindow::showPopUp(const std::string& title, const std::string& information)
{
    QMessageBox::information(0, QString::fromStdString(title), QString::fromStdString(information));
}


QString MainWindow::promptForFile(const QString& caption, const QString& filter)
{
    return QFileDialog::getOpenFileName(0, caption, "", filter);
}

QString MainWindow::promptForDirectory(const QString& caption)
{
    return QFileDialog::getExistingDirectory(0, caption, "");
}



void MainWindow::on_actionSelectTranscriptionSaveLocation_triggered()
{
   QString directoryPath = promptForDirectory("Select folder in which to save to:");
   if (directoryPath.isEmpty()) return;
   showPopUp("Save Location Set", "Translations will now be saved in " + directoryPath.toStdString());
   filer.setSaveDir();
   filer.writeConfig();
}


void MainWindow::on_actionChange_Font_Settings_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, m_userFont, this);

    if (ok)
    {
        m_userFont = font;
        filer.setFontName(QFontInfo(m_userFont).family());
        filer.setFontSize(QFontInfo(m_userFont).pointSize());
        ui->plainTextEditSource->setFont(font);
        ui->plainTextEditTarget->setFont(font);

        filer.writeConfig();
    }
}


void MainWindow::on_actionShow_Current_Key_Save_Locations_triggered()
{
    showPopUp("Auth Key and Save Folder Path",
              "DeepL AuthKey: " + filer.getAuthKey().toStdString()
              + "\nSave Location: " + QFileInfo(filer.getSaveDir()).canonicalFilePath().toStdString());
}


void MainWindow::on_actionChange_AuthKey_triggered()
{
    filer.setAuthKey(showInputPopUp("Enter new DeepL AuthKey", "New DeepL AuthKey:"));
    filer.writeConfig();
}

QString MainWindow::showInputPopUp(const QString title, const QString inputLabel)
{
    return QInputDialog::getText(this, title, inputLabel, QLineEdit::Normal);
}
