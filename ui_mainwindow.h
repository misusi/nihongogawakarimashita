/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelectAuthKeyLocation;
    QAction *actionSelectTranscriptionSaveLocation;
    QAction *actionShow_Current_Key_Save_Locations;
    QAction *actionChange_Font_Settings;
    QAction *actionChange_AuthKey;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBoxSourceLanguage;
    QPushButton *pushButtonSwitch;
    QComboBox *comboBoxTargetLanguage;
    QPushButton *pushButtonTranslate;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonSave;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPlainTextEdit *plainTextEditTarget;
    QWidget *tab_2;
    QTextBrowser *textBrowser;
    QPlainTextEdit *plainTextEditSource;
    QMenuBar *menubar;
    QMenu *menuNihongo_to_Eigo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 764));
        actionSelectAuthKeyLocation = new QAction(MainWindow);
        actionSelectAuthKeyLocation->setObjectName(QString::fromUtf8("actionSelectAuthKeyLocation"));
        actionSelectTranscriptionSaveLocation = new QAction(MainWindow);
        actionSelectTranscriptionSaveLocation->setObjectName(QString::fromUtf8("actionSelectTranscriptionSaveLocation"));
        actionShow_Current_Key_Save_Locations = new QAction(MainWindow);
        actionShow_Current_Key_Save_Locations->setObjectName(QString::fromUtf8("actionShow_Current_Key_Save_Locations"));
        actionChange_Font_Settings = new QAction(MainWindow);
        actionChange_Font_Settings->setObjectName(QString::fromUtf8("actionChange_Font_Settings"));
        actionChange_AuthKey = new QAction(MainWindow);
        actionChange_AuthKey->setObjectName(QString::fromUtf8("actionChange_AuthKey"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(1280, 720));
        centralwidget->setMaximumSize(QSize(1280, 720));
        centralwidget->setSizeIncrement(QSize(1, 1));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 641, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBoxSourceLanguage = new QComboBox(horizontalLayoutWidget_2);
        comboBoxSourceLanguage->addItem(QString());
        comboBoxSourceLanguage->addItem(QString());
        comboBoxSourceLanguage->setObjectName(QString::fromUtf8("comboBoxSourceLanguage"));
        sizePolicy.setHeightForWidth(comboBoxSourceLanguage->sizePolicy().hasHeightForWidth());
        comboBoxSourceLanguage->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(comboBoxSourceLanguage);

        pushButtonSwitch = new QPushButton(horizontalLayoutWidget_2);
        pushButtonSwitch->setObjectName(QString::fromUtf8("pushButtonSwitch"));

        horizontalLayout_2->addWidget(pushButtonSwitch);

        comboBoxTargetLanguage = new QComboBox(horizontalLayoutWidget_2);
        comboBoxTargetLanguage->addItem(QString());
        comboBoxTargetLanguage->addItem(QString());
        comboBoxTargetLanguage->setObjectName(QString::fromUtf8("comboBoxTargetLanguage"));
        sizePolicy.setHeightForWidth(comboBoxTargetLanguage->sizePolicy().hasHeightForWidth());
        comboBoxTargetLanguage->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(comboBoxTargetLanguage);

        pushButtonTranslate = new QPushButton(horizontalLayoutWidget_2);
        pushButtonTranslate->setObjectName(QString::fromUtf8("pushButtonTranslate"));

        horizontalLayout_2->addWidget(pushButtonTranslate);

        pushButtonClear = new QPushButton(horizontalLayoutWidget_2);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));

        horizontalLayout_2->addWidget(pushButtonClear);

        pushButtonSave = new QPushButton(horizontalLayoutWidget_2);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayout_2->addWidget(pushButtonSave);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(640, 0, 640, 691));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        plainTextEditTarget = new QPlainTextEdit(tab);
        plainTextEditTarget->setObjectName(QString::fromUtf8("plainTextEditTarget"));
        plainTextEditTarget->setGeometry(QRect(0, 0, 631, 661));
        QFont font;
        font.setPointSize(12);
        plainTextEditTarget->setFont(font);
        plainTextEditTarget->setReadOnly(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 631, 661));
        textBrowser->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->addTab(tab_2, QString());
        plainTextEditSource = new QPlainTextEdit(centralwidget);
        plainTextEditSource->setObjectName(QString::fromUtf8("plainTextEditSource"));
        plainTextEditSource->setGeometry(QRect(0, 29, 640, 661));
        plainTextEditSource->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 22));
        menuNihongo_to_Eigo = new QMenu(menubar);
        menuNihongo_to_Eigo->setObjectName(QString::fromUtf8("menuNihongo_to_Eigo"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuNihongo_to_Eigo->menuAction());
        menuNihongo_to_Eigo->addAction(actionSelectTranscriptionSaveLocation);
        menuNihongo_to_Eigo->addAction(actionShow_Current_Key_Save_Locations);
        menuNihongo_to_Eigo->addAction(actionChange_Font_Settings);
        menuNihongo_to_Eigo->addAction(actionChange_AuthKey);

        retranslateUi(MainWindow);

        comboBoxSourceLanguage->setCurrentIndex(0);
        comboBoxTargetLanguage->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\343\201\253\343\201\273\343\202\223\343\201\224\343\201\214\343\202\217\343\201\213\343\202\212\343\201\276\343\201\227\343\201\237!!!!!!(\343\201\231\343\201\223\343\201\227)", nullptr));
        actionSelectAuthKeyLocation->setText(QCoreApplication::translate("MainWindow", "Select AuthKey Location", nullptr));
        actionSelectTranscriptionSaveLocation->setText(QCoreApplication::translate("MainWindow", "Select Translation Save Location", nullptr));
        actionShow_Current_Key_Save_Locations->setText(QCoreApplication::translate("MainWindow", "Show Current Key/Save Location", nullptr));
        actionChange_Font_Settings->setText(QCoreApplication::translate("MainWindow", "Change Font Settings", nullptr));
        actionChange_AuthKey->setText(QCoreApplication::translate("MainWindow", "Change AuthKey", nullptr));
        comboBoxSourceLanguage->setItemText(0, QCoreApplication::translate("MainWindow", "JA", nullptr));
        comboBoxSourceLanguage->setItemText(1, QCoreApplication::translate("MainWindow", "EN", nullptr));

        comboBoxSourceLanguage->setPlaceholderText(QCoreApplication::translate("MainWindow", "From...", nullptr));
        pushButtonSwitch->setText(QCoreApplication::translate("MainWindow", "Switch", nullptr));
        comboBoxTargetLanguage->setItemText(0, QCoreApplication::translate("MainWindow", "JA", nullptr));
        comboBoxTargetLanguage->setItemText(1, QCoreApplication::translate("MainWindow", "EN", nullptr));

        comboBoxTargetLanguage->setPlaceholderText(QCoreApplication::translate("MainWindow", "To...", nullptr));
        pushButtonTranslate->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        plainTextEditTarget->setPlaceholderText(QCoreApplication::translate("MainWindow", "Translation...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Translation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Definitions/Examples", nullptr));
        plainTextEditSource->setPlaceholderText(QCoreApplication::translate("MainWindow", "Write here...", nullptr));
        menuNihongo_to_Eigo->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
