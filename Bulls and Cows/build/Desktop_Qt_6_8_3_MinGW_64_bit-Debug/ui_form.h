/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTableWidget *leaderboard;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(596, 578);
        leaderboard = new QTableWidget(Form);
        leaderboard->setObjectName("leaderboard");
        leaderboard->setGeometry(QRect(30, 30, 501, 421));
        leaderboard->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
