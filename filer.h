#ifndef FILER_H
#define FILER_H

#include <iostream>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>

class Filer
{
public:
    Filer();
    bool readConfig(QString configPath = "./config.conf");
    bool writeConfig(QString configPath = "./config.conf");
    QString getFontName() {return m_fontName;}
    int& getFontSize() {return m_fontSize;}
    QString& getAuthKey() {return m_authKey;}
    QString& getSaveDir() {return m_saveDirectoryPath;}
    void setFontName(QString fontName) {m_fontName = fontName;}
    void setFontSize(int fontSize) {m_fontSize = fontSize;}
    void setSaveDir(QString saveDir = "./saved-translations") {m_saveDirectoryPath = saveDir;}
    void setAuthKey(QString authKey) {m_authKey = authKey;}

private:
    QString m_saveDirectoryPath;
    QString m_authKey;
    QString m_fontName;
    int     m_fontSize;

};

#endif // FILER_H
