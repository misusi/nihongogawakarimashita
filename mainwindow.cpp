#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up nework access manager
    m_manager = new QNetworkAccessManager();
    QObject::connect(m_manager, &QNetworkAccessManager::finished,
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


    QFileInfo fileInfo("./");
    QString fullPath = fileInfo.canonicalFilePath();
    qDebug() << fullPath;

    // Read config
    if (!readConfig(m_configPath))
    {
        std::string currentDir = QDir().absolutePath().toStdString();
        showPopUp("Config file does not exist.",
                  "No config found in " + currentDir + ". One will be created.\nPlease select your DeepL auth key file.");
        m_authKeyFilePath = promptForFile("Please select your DeepL auth key file","All Files (*)");

        // Check if saved_translations exists
        const QFileInfo outputDir("some-directory-path-name");
        if (!QDir(m_defaultSaveDir).exists()) {
            QDir().mkdir(m_defaultSaveDir);
        }
        m_saveDirectoryPath = m_defaultSaveDir;
        writeConfig(m_configPath);
    }
    // Read auth key
    setAuthKeyFromFile();
    // If can't find auth key file, show prompt
    // Set up request
    m_baseUrl = "https://api-free.deepl.com/v2/translate";
    m_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    m_request.setHeader(QNetworkRequest::UserAgentHeader, "buffaloshittranslator");


}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_manager;
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
    sendRequest(ui->plainTextEditSource->toPlainText().toStdString());
}


void sayShit();
void MainWindow::on_pushButtonClear_clicked()
{
    ui->plainTextEditSource->clear();
    ui->plainTextEditTarget->clear();
}

void MainWindow::setAuthKeyFromFile()
{
    QFile file(m_authKeyFilePath);
    if(!file.open(QIODevice::ReadOnly)) {
        showPopUp("Error Reading Auth Key", file.errorString().toStdString());
    }
    QTextStream in(&file);
    m_authKey=in.readLine().toStdString();
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
            "&auth_key=" + m_authKey
            + "&text=" + textToTranslate
            + "&source_lang=" + getSourceLang()
            + "&target_lang=" + getTargetLang();
    m_request.setUrl(QString::fromStdString(m_baseUrl));
    m_manager->post(m_request, QByteArray::fromStdString(reqStr));
}

void MainWindow::setTranslatedText(std::string textToTranslate)
{
    m_translatedText = textToTranslate;
    ui->plainTextEditTarget->setPlainText(QString::fromStdString(m_translatedText));
}

void MainWindow::on_pushButtonSave_clicked()
{
    // Make unique filename
    const QString timestamp = QDateTime::currentDateTime().toString(QLatin1String("yyyyMMdd-hhmmsszzz"));
    const QString fileName = m_saveDirectoryPath + "/" + "saved_transcript_" + timestamp + ".txt";
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

void MainWindow::on_actionSelectAuthKeyLocation_triggered()
{
    QString fileName = promptForFile("Select Auth Key File","All Files (*)");
    if (fileName.isEmpty()) {
        return;
    }
    else {
        showPopUp("Auth Key Location Set", "DeepL auth key will now be read from " + fileName.toStdString());
        m_authKeyFilePath = fileName;
        writeConfig(m_configPath);
    }
}


void MainWindow::on_actionSelectTranscriptionSaveLocation_triggered()
{
   QString directoryPath = promptForDirectory("Select folder in which to save to:");
   if (directoryPath.isEmpty()) return;
   showPopUp("Save Location Set", "Translations will now be saved in " + directoryPath.toStdString());
   m_saveDirectoryPath = directoryPath;
   writeConfig(m_configPath);
}

bool MainWindow::readConfig(QString configPath)
{
    QFile file(configPath);

    if( file.open( QIODevice::ReadOnly ) )
    {
        QByteArray bytes = file.readAll();
        file.close();

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson( bytes, &jsonError );
        if( jsonError.error != QJsonParseError::NoError )
        {
            qDebug() << "Error: Could not read config file at " << configPath;
            return false;
        }
        QJsonObject jsonObj = document.object();
        m_saveDirectoryPath = jsonObj.value("saveDirectoryPath").toString();
        m_authKeyFilePath = jsonObj.value("authKeyFilePath").toString();
        file.close();
        return true;
    }
}

void MainWindow::writeConfig(QString configPath)
{
    // Try to open file
    QFile file(configPath);
    if( file.open(QIODevice::WriteOnly | QFile::Truncate) )
    {
        // Create json object to write
        QJsonObject recordObject;
        recordObject.insert("saveDirectoryPath", QJsonValue::fromVariant(m_saveDirectoryPath));
        recordObject.insert("authKeyFilePath", QJsonValue::fromVariant(m_authKeyFilePath));
        // Write the new json to the file
        QJsonDocument doc(recordObject);
        file.write(doc.toJson());
        file.close();
    }
}


//void sayShit()
//{
//    // List the available engines.
//   QStringList engines = QTextToSpeech::availableEngines();
//   qDebug() << "Available engines:";
//   for (auto engine : engines) {
//   qDebug() << "  " << engine;
//   }

//   // Create an instance using the default engine/plugin.
//   //QTextToSpeech *speech = new QTextToSpeech();
//   QTextToSpeech *speech = new QTextToSpeech("speechd", 0);

//   // List the available locales.
//   qDebug() << "Available locales:";
//   for (auto locale : speech->availableLocales()) {
//   qDebug() << "  " << locale;
//   }


//   // Set locale.
//   speech->setLocale(QLocale(QLocale::English, QLocale::LatinScript, QLocale::UnitedStates));
//   //speech->setLocale(QLocale(QLocale::Japanese, QLocale::Japanese, QLocale::Japan));
//   // List the available voices.
//   qDebug() << "Available voices:";
//   for (auto voice : speech->availableVoices()) {
//   qDebug() << "  " << voice.name();
//   }
//   // Display properties.
//   qDebug() << "Locale:" << speech->locale();
//   qDebug() << "Pitch:" << speech->pitch();
//   qDebug() << "Rate:" << speech->rate();
//   qDebug() << "Voice:" << speech->voice().name();
//   qDebug() << "Volume:" << speech->volume();
//   qDebug() << "State:" << speech->state();
//   // Say something.
//   speech->say("Hello, world! This is the Qt speech engine.");
//   speech->setVoice(QVoice());
//   speech->say("nihongogawakarimashita");
//   // Wait for sound to play before exiting.
//   QThread::sleep(4);
//}

void MainWindow::on_actionShow_Current_Key_Save_Locations_triggered()
{
    showPopUp("Locations",
              "Auth Key Path: " + m_authKeyFilePath.toStdString()
              + "\n\nSave Folder Path: " + m_saveDirectoryPath.toStdString());
}


void MainWindow::on_actionChange_Font_Settings_triggered()
{
    bool ok;

    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);

    if (ok)
    {
        ui->plainTextEditSource->setFont(font);
        ui->plainTextEditTarget->setFont(font);
    }
}

