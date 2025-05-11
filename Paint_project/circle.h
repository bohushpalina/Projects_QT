#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"
#include <QPointF>
#include <QColor>
#include <QPainter>

class Circle : public Figure
{
public:
    Circle(const QPointF& center, qreal radius, const QColor& color, int);

    QPointF center() const;
    void setCenter(const QPointF& center);

    qreal radius() const;
    void setRadius(qreal radius);


    void draw(QPainter* painter) override;
    void animate(const QSize& bounds) override;
    bool contains(const QPointF& point) override;
    void move(int dx, int dy) override;
    void resize(double factor) override;
    void rotate(double angle) override;

    void setLineThickness(int thickness) override {
        lineThickness = thickness;
    }

    void setColor(const QColor& newColor) override {
        color = newColor;
    }

    void scale(qreal scaleX, qreal scaleY) override{
        m_center.setX(m_center.x() * scaleX);
        m_center.setY(m_center.y() * scaleY);
        m_radius *= (scaleX + scaleY) / 2; // усреднённое масштабирование
    }

    QString ToString() override
    {
        return QString("Круг");
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

    void draw(QPainter* painter, bool ex) {
        painter->translate(m_center);
        painter->rotate(rotationAngle);
        painter->drawEllipse(QPointF(0, 0), m_radius, m_radius);
    }

    qreal getRadius() const
    {
        return m_radius;
    }

private:
    static int count;
    int id;





private:
    QPointF m_center;
    qreal m_radius;
    QPointF m_velocity = QPointF(3, 3);
};

#endif // CIRCLE_H
