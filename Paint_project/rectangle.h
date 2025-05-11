#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"



class Rectangle : public Figure
{
public:
    Rectangle(const QPointF& topLeft, const QPointF& bottomRight, const QColor& color, int);
    Rectangle(const QPointF& topLeft, const QSize& size, const QColor& color, int penWidth);

    void draw(QPainter* painter) override;
    bool contains(const QPointF& point) override;
    void move(int dx, int dy) override;
    void resize(double factor) override;
    void rotate(double angle) override;
    void animate(const QSize&) override;
    void setSize(int size) {
        rect.setWidth(size);  // Устанавливаем новую ширину
        rect.setHeight(size); // Устанавливаем новую высоту
    }
    double distanceToSegment(const QPointF& point, const QPointF& start, const QPointF& end);

    QString ToString() override
    {
        return QString("Прямоугольник");
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

    void draw(QPainter* painter, bool ex) {
        painter->translate(rect.center());
        painter->rotate(rotationAngle);
        painter->translate(-rect.center());

        painter->drawRect(rect);
        painter->drawRect(rect);
    }


    QColor getColor() override
    {
        return color;
    };

    double rotationAngles() override
    {
        return rotationAngle;
    };

    qreal getWidth() const {
        return rect.width();
    }

    qreal getHeight() const {
        return rect.height();
    }



    void scale(qreal scaleX, qreal scaleY) override {
        QPointF topLeft = rect.topLeft();
        QPointF bottomRight = rect.bottomRight();

        topLeft.setX(topLeft.x() * scaleX);
        topLeft.setY(topLeft.y() * scaleY);
        bottomRight.setX(bottomRight.x() * scaleX);
        bottomRight.setY(bottomRight.y() * scaleY);

        rect = QRectF(topLeft, bottomRight);
    }


private:
    QRectF rect;
    bool movingUp = true;
    static int count;     // Статическая переменная-счётчик
    int id;

};

#endif // RECTANGLE_H
