/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonDownload;
    QLineEdit *lineEdit;
    QLabel *label;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(460, 250);
        MainWindow->setMinimumSize(QSize(460, 250));
        MainWindow->setMaximumSize(QSize(460, 250));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonOK = new QPushButton(centralWidget);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setMinimumSize(QSize(120, 35));
        pushButtonOK->setMaximumSize(QSize(120, 35));
        QFont font;
        font.setFamily(QStringLiteral("Gill Sans Ultra Bold"));
        font.setPointSize(10);
        pushButtonOK->setFont(font);

        gridLayout->addWidget(pushButtonOK, 0, 3, 1, 1);

        pushButtonDownload = new QPushButton(centralWidget);
        pushButtonDownload->setObjectName(QStringLiteral("pushButtonDownload"));
        pushButtonDownload->setMinimumSize(QSize(30, 20));
        pushButtonDownload->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(pushButtonDownload, 1, 3, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(300, 35));
        lineEdit->setMaximumSize(QSize(300, 35));
        QFont font1;
        font1.setFamily(QStringLiteral("Gill Sans Ultra Bold"));
        font1.setPointSize(9);
        lineEdit->setFont(font1);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 3, 2, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMinimumSize(QSize(300, 0));
        textEdit->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(textEdit, 1, 0, 3, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 460, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pocasicko", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        pushButtonDownload->setText(QString());
        lineEdit->setText(QApplication::translate("MainWindow", "city", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "City", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
