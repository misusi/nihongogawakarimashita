#include "filer.h"

Filer::Filer()
{
}

bool Filer::readConfig(QString configPath)
{
    QFile file(configPath);
    if (!file.exists()) {
        return false;
    }
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

        // Get values from json config
        QJsonObject jsonObj = document.object();
        m_saveDirectoryPath = jsonObj.value("saveDirectoryPath").toString();
        m_authKey = jsonObj.value("authKey").toString();
        m_fontName = jsonObj.value("fontName").toString();
        m_fontSize = jsonObj.value("fontSize").toInt();

        file.close();
        return true;
    }
    return false;
}

bool Filer::writeConfig(QString configPath)
{
    // Try to open file
    QFile file(configPath);
    if( file.open(QIODevice::WriteOnly | QFile::Truncate) )
    {
        // Create json object to write
        QJsonObject recordObject;
        recordObject.insert("saveDirectoryPath", QJsonValue::fromVariant(m_saveDirectoryPath));
        recordObject.insert("authKey", QJsonValue::fromVariant(m_authKey));
        recordObject.insert("fontName", QJsonValue::fromVariant(m_fontName));
        recordObject.insert("fontSize", QJsonValue::fromVariant(m_fontSize));

        // Write the new json to the file
        QJsonDocument doc(recordObject);
        file.write(doc.toJson());
        file.close();
        return true;
    }
    return false;
}
