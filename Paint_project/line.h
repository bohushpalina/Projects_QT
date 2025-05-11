#ifndef LINE_H
#define LINE_H
#include "figure.h"
#include <QPoint>

class Line : public Figure
{

public:
    QPointF first;
    QPointF last;

    Line(const QPointF& startPoint, const QPointF& endPoint, const QColor& color, int);
    QPointF getfirst() {return first;};
    QPointF getlast() {return last;};

    void draw(QPainter* painter) override;
    bool contains(const QPointF& point) override;
    void move(int dx, int dy) override;
    void resize(double factor) override;
    void rotate(double angle) override;
    void animate(const QSize&) override;

    void draw(QPainter* painter, bool ex) override
    {
        QPointF center = (first + last) / 2.0;
        painter->translate(center);
        painter->rotate(rotationAngle);
        painter->translate(-center);

        painter->drawLine(first, last);
    };

    QString ToString() override
    {
        return QString("Прямая линия");
    }

    void setLineThickness(int thickness) override {
        lineThickness = thickness;
    }

    void setColor(const QColor& newColor) override {
        color = newColor;
    }

    int getLineThickness() override
    {
        return lineThickness;
    };

    QColor getColor() override
    {
        return color;
    };

    double rotationAngles() override
    {
        return rotationAngle;
    };


    void scale(qreal scaleX, qreal scaleY) override {
        first.setX(first.x() * scaleX);
        first.setY(first.y() * scaleY);
        last.setX(last.x() * scaleX);
        last.setY(last.y() * scaleY);
    }

private:
    static int count;     // Статическая переменная-счётчик
    int id;               // Уникальный номер конкретного прямоугольника


};

#endif // LINE_H
