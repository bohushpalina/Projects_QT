#include "settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Настройки");

    // Создаем элементы для настройки толщины линии
    lineThicknessLabel = new QLabel("Толщина линии:");
    lineThicknessSlider = new QSlider(Qt::Horizontal);
    lineThicknessSlider->setRange(1, 50);
    lineThicknessSlider->setValue(2);

    QSpinBox* lineThicknessSpin = new QSpinBox();
    lineThicknessSpin->setRange(1, 50);
    lineThicknessSpin->setValue(2);

    connect(lineThicknessSlider, &QSlider::valueChanged, lineThicknessSpin, &QSpinBox::setValue);
    connect(lineThicknessSpin, &QSpinBox::valueChanged, lineThicknessSlider, &QSlider::setValue);

    // Объявляем кнопку "Применить"
    applyButton = new QPushButton("Применить");
    connect(applyButton, &QPushButton::clicked, this, &SettingsDialog::on_applyButton_clicked);

    // Создаем layout
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(lineThicknessLabel);
    layout->addWidget(lineThicknessSlider);
    layout->addWidget(lineThicknessSpin);
    layout->addWidget(applyButton);

    setLayout(layout);
}

int SettingsDialog::getLineThickness() const {
    return lineThicknessSlider->value();
}

void SettingsDialog::on_applyButton_clicked() {
    int thickness = lineThicknessSlider->value();
    emit requestLineThickness(thickness);

    accept();  // Закрыть диалог
}
