/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Player;
    QPushButton *Clear;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(663, 743);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Player = new QLabel(centralwidget);
        Player->setObjectName("Player");
        Player->setGeometry(QRect(60, 50, 531, 61));
        Player->setStyleSheet(QString::fromUtf8("font-size: 100px;\n"
"font: 30pt \"SimSun\";\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"    padding: 5px;\n"
"    qproperty-alignment: 'AlignCenter';"));
        Clear = new QPushButton(centralwidget);
        Clear->setObjectName("Clear");
        Clear->setGeometry(QRect(490, 580, 101, 71));
        Clear->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"    font-family: \"Courier New\", monospace;\n"
"    font-weight: normal;\n"
"    color: #2c3e50;\n"
"    background-color: #dfe6e9;\n"
"    border: 1px solid #b2bec3;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
""));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(60, 120, 531, 431));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(60, 600, 251, 51));
        checkBox->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"    font-family: \"Courier New\", monospace;\n"
"    font-weight: normal;\n"
"    color: #2c3e50;\n"
"    background-color: #dfe6e9;\n"
"    border: 1px solid #b2bec3;\n"
"    border-radius: 6px;\n"
"    padding: 8px 18px;\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 663, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Player->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Game_with_computer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
