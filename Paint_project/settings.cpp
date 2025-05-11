#include "settings.h"
#include "ui_settings.h"
#include "figure.h" // твой базовый класс Figure
#include <QColorDialog>

Settings::Settings(Figure* figure, QWidget* parent)
    : QWidget(parent), ui(new Ui::Settings), figure(figure) {
    ui->setupUi(this);
    updateUI();
    ui->rotationSlider->setRange(0, 360);

    ui->label->setText(figure->ToString());
    connect(ui->colorButton, &QPushButton::clicked, this, &Settings::onColorButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &Settings::onDeleteButtonClicked);
    connect(ui->thicknessSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &Settings::onThicknessChanged);
    connect(ui->rotationSlider, &QSlider::valueChanged, this, &Settings::onRotationChanged);


}

Settings::~Settings() {
    delete ui;
}

void Settings::updateUI() {
    ui->thicknessSpinBox->setValue(figure->getLineThickness());
    ui->rotationSlider->setValue(figure->rotationAngle);
}

void Settings::onColorButtonClicked() {
    QColor color = QColorDialog::getColor(figure->getColor(), this);
    if (color.isValid()) {
        figure->setColor(color);
        emit figureUpdated();
    }
}

void Settings::onDeleteButtonClicked() {
    emit figureDeleted(figure);
    close();
}

void Settings::onThicknessChanged(int value) {
    figure->setLineThickness(value);
    emit figureUpdated();
}

void Settings::onRotationChanged(int value) {
    figure->rotate(value);
    emit figureUpdated();
}
