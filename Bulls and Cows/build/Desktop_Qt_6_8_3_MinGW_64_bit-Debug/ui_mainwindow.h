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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *new_game;
    QLabel *info;
    QPushButton *records;
    QLabel *Entering;
    QLineEdit *lineEdit;
    QPushButton *Check_but;
    QTableWidget *results;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(691, 702);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        new_game = new QPushButton(centralwidget);
        new_game->setObjectName("new_game");
        new_game->setGeometry(QRect(60, 40, 121, 41));
        new_game->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #dfe6e9;\n"
"    border: 2px solid #b2bec3;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #2d3436;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #b2bec3;\n"
"}\n"
""));
        info = new QLabel(centralwidget);
        info->setObjectName("info");
        info->setGeometry(QRect(190, 40, 271, 51));
        info->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: 600;\n"
"    color: #636e72;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #dcdde1;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
""));
        records = new QPushButton(centralwidget);
        records->setObjectName("records");
        records->setGeometry(QRect(490, 40, 111, 41));
        records->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #dcdde1;\n"
"    border: 2px solid #a4b0be;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #2f3542;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #ced6e0;\n"
"}\n"
""));
        Entering = new QLabel(centralwidget);
        Entering->setObjectName("Entering");
        Entering->setGeometry(QRect(60, 120, 231, 41));
        Entering->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: 600;\n"
"    color: #636e72;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #dcdde1;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
""));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(310, 130, 131, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f6fa;\n"
"    border: 2px solid #dcdde1;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    font-size: 16px;\n"
"    color: #2f3640;\n"
"}\n"
""));
        Check_but = new QPushButton(centralwidget);
        Check_but->setObjectName("Check_but");
        Check_but->setGeometry(QRect(480, 110, 121, 51));
        Check_but->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f1f2f6;\n"
"    border: 2px solid #ced6e0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #2f3542;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #dcdde1;\n"
"}\n"
"\n"
""));
        results = new QTableWidget(centralwidget);
        if (results->columnCount() < 3)
            results->setColumnCount(3);
        results->setObjectName("results");
        results->setGeometry(QRect(60, 180, 541, 371));
        results->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #dcdde1;\n"
"    font-size: 14px;\n"
"    color: #2d3436;\n"
"    gridline-color: #dcdde1;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #dfe6e9;\n"
"    color: #2d3436;\n"
"    font-weight: bold;\n"
"    padding: 4px;\n"
"    border: 1px solid #dcdde1;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 6px;\n"
"}\n"
""));
        results->setRowCount(0);
        results->setColumnCount(3);
        results->horizontalHeader()->setVisible(true);
        results->horizontalHeader()->setCascadingSectionResizes(false);
        results->horizontalHeader()->setMinimumSectionSize(40);
        results->horizontalHeader()->setHighlightSections(false);
        results->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        results->horizontalHeader()->setStretchLastSection(false);
        results->verticalHeader()->setVisible(false);
        results->verticalHeader()->setCascadingSectionResizes(false);
        results->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        results->verticalHeader()->setStretchLastSection(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 691, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        new_game->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
        info->setText(QCoreApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260 \320\275\320\265 \320\275\320\260\321\207\320\260\321\202\320\260", nullptr));
        records->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\272\320\276\321\200\320\264\321\213", nullptr));
        Entering->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));
        Check_but->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\221\321\213\320\272\320\270 \320\270 \320\272\320\276\321\200\320\276\320\262\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
