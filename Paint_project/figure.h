#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>
#include <QLineF>
#include <QDebug>

class Figure
{
public:
    virtual ~Figure() {}

    virtual void draw(QPainter* painter) = 0;
    virtual void draw(QPainter* painter, bool) = 0;
    virtual bool contains(const QPointF& point) = 0;
    virtual void move(int dx, int dy) = 0;
    virtual void resize(double factor) = 0;
    virtual void rotate(double angle) = 0;
    virtual void animate(const QSize&) = 0;
    virtual QString ToString() = 0;
    virtual void setLineThickness(int thickness) = 0;
    virtual void setColor(const QColor& color) = 0;

    virtual int getLineThickness() = 0;
    virtual QColor getColor() = 0;
    virtual double rotationAngles() = 0;


    virtual void scale(qreal scaleX, qreal scaleY) = 0;

    QColor color;
    double rotationAngle;
    int lineThickness;
};

enum class FigureType{
    None,
    Line,
    FreeLine,
    Rectangle,
    Circle
};

#endif
