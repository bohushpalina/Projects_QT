#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QColor>
#include <QPointer>

class Figure;

namespace Ui {
class Settings;
}

class Settings : public QWidget {
    Q_OBJECT

public:
    explicit Settings(Figure* figure, QWidget* parent = nullptr);
    ~Settings();

signals:
    void figureUpdated();
    void figureDeleted(Figure* figure);

private slots:
    void onColorButtonClicked();
    void onDeleteButtonClicked();
    void onThicknessChanged(int value);
    void onRotationChanged(int value);


private:
    Ui::Settings* ui;
    Figure* figure;
    void updateUI();
};

#endif // SETTINGS_H
