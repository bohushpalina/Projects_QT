#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "circle.h"
#include "freeline.h"
#include "drawwidget.h"
#include "line.h"
#include "rectangle.h"
#include <QListWidget>
#include <QScrollArea>
#include <QInputDialog>
#include <QMessageBox>
#include "settings.h"
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QColor getcolor() {return currentColor;};
    void loadFromFile();
    void saveToFile();
    void setLineThickness(int thickness);
    void openThicknessDialog();
    void openFigureSettingsDialog(Figure* figure);
    void onFigureAdded(Figure* figure);

    void onFigureUpdated() {
        drawWidget->update();
    }

    void clearSettingsPanels();
    void toggleAnimation();
    void animateFigures();
    void onFigureSelected(Figure* selectedFigure);


private:
    Ui::MainWindow *ui;
    FigureType currentFigure = FigureType::None;
    QColor currentColor = Qt::black;
    QVector<Figure*> figures;
    QVector<QPointF> freeLinePoints;
    Line* tempLine = nullptr;
    Rectangle* tempRectangle = nullptr;
    QPointF rectStartPoint;
    Circle* tempCircle = nullptr;
    DrawWidget *drawWidget;
    QPixmap backgroundImage;
    QListWidget* listWidget;
    QAction* toggleAnimationAction;

    QVBoxLayout* settingsPanelLayout;

    QTimer* animationTimer;
    bool animationRunning = 0;



    void resizeEvent(QResizeEvent* event) override;

};

#endif // MAINWINDOW_H
