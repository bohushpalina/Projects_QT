/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QPushButton *colorButton;
    QPushButton *deleteButton;
    QSpinBox *thicknessSpinBox;
    QSlider *rotationSlider;
    QLabel *label;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(273, 164);
        Settings->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #1c1c1c;  /* \320\247\320\265\321\200\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 2px solid #FFD700;  /* \320\227\320\276\320\273\320\276\321\202\320\270\321\201\321\202\320\260\321\217 \321\200\320\260\320\274\320\272\320\260 */\n"
"    border-radius: 4px;         /* \320\243\320\274\320\265\321\200\320\265\320\275\320\275\321\213\320\265 \321\201\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\321\217 */\n"
"    padding: 8px;               /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 */\n"
"    color: white;               /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"}\n"
"\n"
"QLabel, QSpinBox, QSlider {\n"
"    color: white;               /* \320\221\320\265\320\273\321\213\320\271 \321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    background-color: #333333;  /* \320\242\320\265\320"
                        "\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \321\202\320\265\320\272\321\201\321\202\320\276\320\262\321\213\321\205 \320\277\320\276\320\273\320\265\320\271 \320\270 \321\201\320\273\320\260\320\271\320\264\320\265\321\200\320\260 */\n"
"    border: 1px solid #FFD700;  /* \320\227\320\276\320\273\320\276\321\202\320\270\321\201\321\202\321\213\320\265 \321\200\320\260\320\274\320\272\320\270 */\n"
"    border-radius: 3px;         /* \320\234\320\265\320\275\320\265\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\275\321\213\320\265 \321\201\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\321\217 */\n"
"}\n"
"\n"
"QPushButton {\n"
"    color: white;               /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\260\321\205 */\n"
"    background-color: #FFD700;  /* \320\227\320\276\320\273\320\276\321\202\320\270\321\201\321\202\321\213\320\271"
                        " \321\204\320\276\320\275 \320\264\320\273\321\217 \320\272\320\275\320\276\320\277\320\276\320\272 */\n"
"    border: 1px solid #FFD700;  /* \320\227\320\276\320\273\320\276\321\202\320\270\321\201\321\202\321\213\320\265 \321\200\320\260\320\274\320\272\320\270 */\n"
"    border-radius: 4px;         /* \320\243\320\274\320\265\321\200\320\265\320\275\320\275\321\213\320\265 \321\201\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\321\217 */\n"
"    padding: 2px 8px;          /* \320\233\320\265\320\263\320\272\320\270\320\265 \320\276\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    font-weight: bold;          /* \320\226\320\270\321\200\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\260\321\205 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #FFCC00;  /* \320\257\321\200\320\272\320\276-\320"
                        "\267\320\276\320\273\320\276\321\202\320\270\321\201\321\202\321\213\320\271 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QSpinBox, QSlider {\n"
"    background-color: #333333;  /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \321\201\320\273\320\260\320\271\320\264\320\265\321\200\320\276\320\262 \320\270 \321\201\320\277\320\270\320\275\320\261\320\276\320\272\321\201\320\276\320\262 */\n"
"    color: white;               /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 1px solid #FFD700;  /* \320\227\320\276\320\273\320\276\321\202\320\270\321\201\321\202\321\213\320\265 \321\200\320\260\320\274\320\272\320\270 */\n"
"    border-radius: 3px;         /* \320\234\320\265\320\275\320\265\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\275\321\213\320\265 \321\201\320\272\321\200\321\203\320\263\320\273\320\265\320"
                        "\275\320\270\321\217 */\n"
"}\n"
"\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    background-color: #FFD700;  /* \320\227\320\276\320\273\320\276\321\202\320\270\321\201\321\202\321\213\320\271 \321\204\320\276\320\275 \320\272\320\275\320\276\320\277\320\276\320\272 \320\264\320\273\321\217 \321\201\320\277\320\270\320\275\320\261\320\276\320\272\321\201\320\260 */\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle {\n"
"    background-color: #FFD700;  /* \320\227\320\276\320\273\320\276\321\202\320\276\320\271 \320\277\320\276\320\273\320\267\321\203\320\275\320\276\320\272 */\n"
"    border-radius: 1px;\n"
"}\n"
"\n"
"QSlider {\n"
"    background-color: #333333;  /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \321\201\320\273\320\260\320\271\320\264\320\265\321\200\320\260 */\n"
"}\n"
""));
        colorButton = new QPushButton(Settings);
        colorButton->setObjectName("colorButton");
        colorButton->setGeometry(QRect(10, 108, 141, 41));
        deleteButton = new QPushButton(Settings);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(162, 108, 101, 41));
        thicknessSpinBox = new QSpinBox(Settings);
        thicknessSpinBox->setObjectName("thicknessSpinBox");
        thicknessSpinBox->setGeometry(QRect(10, 65, 71, 31));
        rotationSlider = new QSlider(Settings);
        rotationSlider->setObjectName("rotationSlider");
        rotationSlider->setGeometry(QRect(100, 70, 161, 21));
        rotationSlider->setOrientation(Qt::Orientation::Horizontal);
        label = new QLabel(Settings);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 9, 251, 41));
        label->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Form", nullptr));
        colorButton->setText(QCoreApplication::translate("Settings", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        deleteButton->setText(QCoreApplication::translate("Settings", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("Settings", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
