/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelectAuthKeyLocation;
    QAction *actionSelectTranscriptionSaveLocation;
    QAction *actionShow_Current_Key_Save_Locations;
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEditSource;
    QPlainTextEdit *plainTextEditTarget;
    QComboBox *comboBoxSourceLanguage;
    QComboBox *comboBoxTargetLanguage;
    QPushButton *pushButtonSwitch;
    QPushButton *pushButtonTranslate;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonClear;
    QMenuBar *menubar;
    QMenu *menuNihongo_to_Eigo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        actionSelectAuthKeyLocation = new QAction(MainWindow);
        actionSelectAuthKeyLocation->setObjectName(QString::fromUtf8("actionSelectAuthKeyLocation"));
        actionSelectTranscriptionSaveLocation = new QAction(MainWindow);
        actionSelectTranscriptionSaveLocation->setObjectName(QString::fromUtf8("actionSelectTranscriptionSaveLocation"));
        actionShow_Current_Key_Save_Locations = new QAction(MainWindow);
        actionShow_Current_Key_Save_Locations->setObjectName(QString::fromUtf8("actionShow_Current_Key_Save_Locations"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(800, 557));
        centralwidget->setMaximumSize(QSize(800, 557));
        plainTextEditSource = new QPlainTextEdit(centralwidget);
        plainTextEditSource->setObjectName(QString::fromUtf8("plainTextEditSource"));
        plainTextEditSource->setGeometry(QRect(10, 40, 381, 511));
        QFont font;
        font.setPointSize(12);
        plainTextEditSource->setFont(font);
        plainTextEditTarget = new QPlainTextEdit(centralwidget);
        plainTextEditTarget->setObjectName(QString::fromUtf8("plainTextEditTarget"));
        plainTextEditTarget->setGeometry(QRect(410, 40, 381, 511));
        plainTextEditTarget->setFont(font);
        plainTextEditTarget->setReadOnly(true);
        comboBoxSourceLanguage = new QComboBox(centralwidget);
        comboBoxSourceLanguage->addItem(QString());
        comboBoxSourceLanguage->addItem(QString());
        comboBoxSourceLanguage->setObjectName(QString::fromUtf8("comboBoxSourceLanguage"));
        comboBoxSourceLanguage->setGeometry(QRect(10, 10, 111, 24));
        comboBoxTargetLanguage = new QComboBox(centralwidget);
        comboBoxTargetLanguage->addItem(QString());
        comboBoxTargetLanguage->addItem(QString());
        comboBoxTargetLanguage->setObjectName(QString::fromUtf8("comboBoxTargetLanguage"));
        comboBoxTargetLanguage->setGeometry(QRect(190, 10, 111, 24));
        pushButtonSwitch = new QPushButton(centralwidget);
        pushButtonSwitch->setObjectName(QString::fromUtf8("pushButtonSwitch"));
        pushButtonSwitch->setGeometry(QRect(130, 10, 51, 24));
        pushButtonTranslate = new QPushButton(centralwidget);
        pushButtonTranslate->setObjectName(QString::fromUtf8("pushButtonTranslate"));
        pushButtonTranslate->setGeometry(QRect(340, 10, 80, 24));
        pushButtonSave = new QPushButton(centralwidget);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(520, 10, 161, 24));
        pushButtonClear = new QPushButton(centralwidget);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(430, 10, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuNihongo_to_Eigo = new QMenu(menubar);
        menuNihongo_to_Eigo->setObjectName(QString::fromUtf8("menuNihongo_to_Eigo"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuNihongo_to_Eigo->menuAction());
        menuNihongo_to_Eigo->addAction(actionSelectAuthKeyLocation);
        menuNihongo_to_Eigo->addAction(actionSelectTranscriptionSaveLocation);
        menuNihongo_to_Eigo->addAction(actionShow_Current_Key_Save_Locations);

        retranslateUi(MainWindow);

        comboBoxSourceLanguage->setCurrentIndex(0);
        comboBoxTargetLanguage->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\343\201\253\343\201\273\343\202\223\343\201\224\343\201\214\343\202\217\343\201\213\343\202\212\343\201\276\343\201\227\343\201\237!!!!!!(\343\201\231\343\201\223\343\201\227)", nullptr));
        actionSelectAuthKeyLocation->setText(QApplication::translate("MainWindow", "Select AuthKey Location", nullptr));
        actionSelectTranscriptionSaveLocation->setText(QApplication::translate("MainWindow", "Select Translation Save Location", nullptr));
        actionShow_Current_Key_Save_Locations->setText(QApplication::translate("MainWindow", "Show Current Key/Save Locations", nullptr));
        plainTextEditSource->setPlaceholderText(QApplication::translate("MainWindow", "Write here...", nullptr));
        plainTextEditTarget->setPlaceholderText(QApplication::translate("MainWindow", "Translation...", nullptr));
        comboBoxSourceLanguage->setItemText(0, QApplication::translate("MainWindow", "JA", nullptr));
        comboBoxSourceLanguage->setItemText(1, QApplication::translate("MainWindow", "EN", nullptr));

        comboBoxTargetLanguage->setItemText(0, QApplication::translate("MainWindow", "JA", nullptr));
        comboBoxTargetLanguage->setItemText(1, QApplication::translate("MainWindow", "EN", nullptr));

        pushButtonSwitch->setText(QApplication::translate("MainWindow", "Switch", nullptr));
        pushButtonTranslate->setText(QApplication::translate("MainWindow", "Translate", nullptr));
        pushButtonSave->setText(QApplication::translate("MainWindow", "Save Translation to File...", nullptr));
        pushButtonClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        menuNihongo_to_Eigo->setTitle(QApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
