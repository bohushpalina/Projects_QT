#ifndef FREELINE_H
#define FREELINE_H
#include <QPoint>
#include "figure.h"
#include <QVector>



class FreeLine : public Figure
{
private:
    QVector<QPointF> points;
public:
    FreeLine(const QVector<QPointF>& points, const QColor& color, int);

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


    void draw(QPainter* painter) override;               // Рисование ломаной
    bool contains(const QPointF& point) override;        // Проверка, находится ли точка на ломаной
    void move(int dx, int dy) override;                  // Перемещение ломаной
    void resize(double factor) override;                 // Изменение размера ломаной
    void rotate(double angle) override;
    void animate(const QSize&) override;

    QString ToString() override
    {
        return QString("Линия общей конфигурации");
    }

    void setLineThickness(int thickness) override {
        lineThickness = thickness;
    }

    void setColor(const QColor& newColor) override {
        color = newColor;
    }

    void draw(QPainter* painter, bool ex) {
        if (points.size() > 1) {
            // Рисуем все сегменты ломаной линии
            for (int i = 1; i < points.size(); ++i) {
                painter->drawLine(points[i - 1], points[i]);
            }
        }
    }


    void addPoint(const QPointF& point);    // Добавление новой точки в ломаную

    double distanceToSegment(const QPointF& point, const QPointF& start, const QPointF& end);

    void scale(qreal scaleX, qreal scaleY) override{
        for (QPointF& point : points) {
            point.setX(point.x() * scaleX);
            point.setY(point.y() * scaleY);
        }
    }

signals:
    void figureUpdated();

private:
    static int count;     // Статическая переменная-счётчик
    int id;               // Уникальный номер конкретного прямоугольника

};

#endif // FREELINE_H
