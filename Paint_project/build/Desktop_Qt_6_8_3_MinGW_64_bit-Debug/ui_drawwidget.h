/********************************************************************************
** Form generated from reading UI file 'drawwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWWIDGET_H
#define UI_DRAWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawWidget
{
public:

    void setupUi(QWidget *DrawWidget)
    {
        if (DrawWidget->objectName().isEmpty())
            DrawWidget->setObjectName("DrawWidget");
        DrawWidget->resize(1134, 741);

        retranslateUi(DrawWidget);

        QMetaObject::connectSlotsByName(DrawWidget);
    } // setupUi

    void retranslateUi(QWidget *DrawWidget)
    {
        DrawWidget->setWindowTitle(QCoreApplication::translate("DrawWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawWidget: public Ui_DrawWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWWIDGET_H
