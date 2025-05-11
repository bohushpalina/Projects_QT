#include "freeline.h"
#include <QLineF>


int FreeLine::count = 0;

FreeLine::FreeLine(const QVector<QPointF>& points, const QColor& color, int penWidth)
    : points(points)
{
    this->color = color;
    this->lineThickness = penWidth;
    this->rotationAngle = 0.0;
}

void FreeLine::draw(QPainter* painter) {
    QPen pen(color, lineThickness);
    painter->setPen(pen);
    painter->save();

    if (points.size() > 1) {
        // Рисуем все сегменты ломаной линии
        for (int i = 1; i < points.size(); ++i) {
            painter->drawLine(points[i - 1], points[i]);
        }
    }

    painter->restore();
}

bool FreeLine::contains(const QPointF& point) {
    const int tolerance = 5;  // Допустимая погрешность

    // Проверяем, находится ли точка на одном из сегментов ломаной линии
    for (int i = 1; i < points.size(); ++i) {
        QLineF line(points[i - 1], points[i]);

        // Вычисляем расстояние от точки до отрезка
        double distance = distanceToSegment(point, line.p1(), line.p2());

        if (distance <= tolerance) {
            return true;
        }
    }

    return false;
}

void FreeLine::move(int dx, int dy) {
    // Перемещаем все точки ломаной
    for (QPointF& point : points) {
        point += QPoint(dx, dy);
    }
}

void FreeLine::resize(double factor) {
    // Масштабируем все точки относительно первой
    QPointF center = points.first();
    for (QPointF& point : points) {
        point = center + (point - center) * factor;
    }
}

void FreeLine::rotate(double angle) {
    rotationAngle = angle;


    // Вычисляем центр массы ломаной линии
    QPointF center(0, 0);
    for (const QPointF& point : points) {
        center += point;
    }
    center /= points.size();

    // Поворот всех точек относительно центра
    double radianAngle = qDegreesToRadians(rotationAngle);
    for (QPointF& point : points) {
        double x = point.x() - center.x();
        double y = point.y() - center.y();
        double newX = center.x() + (x * cos(radianAngle) - y * sin(radianAngle));
        double newY = center.y() + (x * sin(radianAngle) + y * cos(radianAngle));
        point = QPointF(newX, newY);
    }

}


void FreeLine::animate(const QSize& bounds) {
    static int angle = 0;  // Угол поворота в градусах
    rotate(1);

}

void FreeLine::addPoint(const QPointF& point) {
    points.append(point);
}

double FreeLine::distanceToSegment(const QPointF& point, const QPointF& start, const QPointF& end) {
    double dx = end.x() - start.x();
    double dy = end.y() - start.y();
    double segmentLengthSquared = dx * dx + dy * dy;

    if (segmentLengthSquared == 0) {
        // Если сегмент является точкой
        return QLineF(point, start).length();
    }

    double t = ((point.x() - start.x()) * dx + (point.y() - start.y()) * dy) / segmentLengthSquared;
    t = std::max(0.0, std::min(1.0, t));  // Ограничиваем t в пределах [0, 1]

    QPointF projection(start.x() + t * dx, start.y() + t * dy);  // Проекция точки на отрезок
    return QLineF(point, projection).length();  // Расстояние от точки до проекции на отрезке
}
