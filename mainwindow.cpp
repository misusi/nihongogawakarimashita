#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up nework access manager
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

    // Read config
    readConfig("./config.conf");
    // Read auth key
    setAuthKeyFromFile();
    // Set up request
    baseUrl = "https://api-free.deepl.com/v2/translate";
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


void MainWindow::on_pushButtonTranslate_clicked()
{
    sendRequest(ui->plainTextEditSource->toPlainText().toStdString());
}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->plainTextEditSource->clear();
    ui->plainTextEditTarget->clear();
}

void MainWindow::setAuthKeyFromFile()
{
    QFile file(authKeyFilePath);
    if(!file.open(QIODevice::ReadOnly)) {
        showPopUp("Error Reading Auth Key", file.errorString().toStdString());
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
    manager->post(request, QByteArray::fromStdString(reqStr));
}

void MainWindow::setTranslatedText(std::string textToTranslate)
{
    translatedText = textToTranslate;
    ui->plainTextEditTarget->setPlainText(QString::fromStdString(translatedText));
}

void MainWindow::on_pushButtonSave_clicked()
{
    // Make unique filename
    const QString timestamp = QDateTime::currentDateTime().toString(QLatin1String("yyyyMMdd-hhmmsszzz"));
    const QString fileName = saveDirectoryPath + "/" + "saved_transcript_" + timestamp + ".txt";
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


void MainWindow::on_actionSelectAuthKeyLocation_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Select Auth Key File", "", "All Files (*)");
    if (fileName.isEmpty()) return;
    showPopUp("Auth Key Location Set", "DeepL auth key will now be read from " + fileName.toStdString());
    authKeyFilePath = fileName;
    writeConfig("./config.conf");
}


void MainWindow::on_actionSelectTranscriptionSaveLocation_triggered()
{
   QString directoryPath = QFileDialog::getExistingDirectory(0, "Select folder in which to save to:", "./");
   if (directoryPath.isEmpty()) return;
   showPopUp("Save Location Set", "Translations will now be saved in " + directoryPath.toStdString());
   saveDirectoryPath = directoryPath;
   writeConfig("./config.conf");
}

void MainWindow::readConfig(QString configPath)
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
            showPopUp("Error", "Could not read config file at " + configPath.toStdString());
        }
        QJsonObject jsonObj = document.object();
        saveDirectoryPath = jsonObj.value("saveDirectoryPath").toString();
        authKeyFilePath = jsonObj.value("authKeyFilePath").toString();
        file.close();
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
        recordObject.insert("saveDirectoryPath", QJsonValue::fromVariant(saveDirectoryPath));
        recordObject.insert("authKeyFilePath", QJsonValue::fromVariant(authKeyFilePath));
        // Write the new json to the file
        QJsonDocument doc(recordObject);
        file.write(doc.toJson());
        file.close();
    }
}
