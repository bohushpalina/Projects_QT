#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QList>
#include <QColor>
#include <QPointF>
#include "figure.h"
#include "freeline.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include <QMouseEvent>
#include "drawWidget.h"


class Figure;  // Объявление класса Figure, если он есть
class Line;    // Объявление класса Line, если он есть

namespace Ui {
class DrawWidget;
}

class DrawWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DrawWidget(QWidget *parent = nullptr);
    ~DrawWidget();

    void setData(QList<Figure*>& figures,
                 FigureType currentFigure,
                 Line* tempLine,
                 Rectangle* tempRectangle,
                 Circle* tempCircle,
                 QVector<QPointF> freeLinePoints,
                 QColor currentColor,
                 QPixmap backgroundImage);
    int getetCurrentThickness() { return lineThickness; };
    void clearCanvas();
    void setCurrentColor(const QColor& color);
    void saveImage(const QString& filePath);
    void setCurrentFigureType(FigureType type);
    QList<Figure*> getFigures();
    void deleteFigure(Figure* figure);
    void paintEvent(QPaintEvent *event) override;


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    Ui::DrawWidget *ui;
    QList<Figure*> figures;
    QColor currentColor;
    QPixmap backgroundImage;
    int lineThickness;
    QSize previousSize;

    FigureType currentFigure;

    Line* tempLine;
    Rectangle* tempRectangle;
    Circle* tempCircle;
    QVector<QPointF> freeLinePoints;
    QPointF rectStartPoint;

    Figure* selectedFigure = nullptr;


public:
    void setLineThickness(int thickness) { lineThickness = thickness; }


public slots:
    void onFigureDeleted(Figure* figure) {
        deleteFigure(figure);
    }

signals:
    void figureAdded(Figure* figure);
    void figureDeleted(Figure* figure);
    void canvasCleared();
    void figure_Selected(Figure* figure);


};

#endif // DRAWWIDGET_H
