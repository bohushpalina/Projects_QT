#include "line.h"

int Line::count = 0;


Line::Line(const QPointF& startPoint, const QPointF& endPoint, const QColor& color, int penWidth)
    : first(startPoint), last(endPoint)
{
    this->color = color;
    this->lineThickness = penWidth;
    this->rotationAngle = 0.0;
}

void Line::draw(QPainter* painter) {
    QPen pen(color, lineThickness);
    painter->setPen(pen);
    painter->save();

    QPointF center = (first + last) / 2.0;
    painter->translate(center);
    painter->rotate(rotationAngle);
    painter->translate(-center);

    painter->drawLine(first, last);
    painter->restore();
}

bool Line::contains(const QPointF& point)
{
    const int tolerance = 5;
    double dx = last.x() - first.x();
    double dy = last.y() - first.y();

    // Если линия — это точка, проверяем расстояние до неё
    if (dx == 0 && dy == 0)
        return (QLineF(first, point).length() <= tolerance);

    // Центр линии (возможно, для поворота)
    QPointF center = (first + last) / 2;

    // Преобразуем точку в систему координат, где линия не повёрнута
    QTransform transform;
    transform.translate(center.x(), center.y());
    transform.rotate(-rotationAngle);  // Поворот в обратную сторону
    transform.translate(-center.x(), -center.y());

    QPointF rotatedPoint = transform.map(point);

    // Проверка, находится ли эта точка на линии (с учётом погрешности)
    double t = ((rotatedPoint.x() - first.x()) * dx + (rotatedPoint.y() - first.y()) * dy) / (dx * dx + dy * dy);
    t = std::max(0.0, std::min(1.0, t));
    QPointF projection(first.x() + t * dx, first.y() + t * dy);

    return QLineF(rotatedPoint, projection).length() <= tolerance;
}


void Line::move(int dx, int dy) {
    first += QPoint(dx, dy);
    last += QPoint(dx, dy);
}

void Line::resize(double f) {
    QPointF center = (first + last) / 2.0;

    QPointF vecStart = first - center;
    QPointF vecEnd = last - center;

    first = center + vecStart * f;
    last = center + vecEnd * f;
}

void Line::rotate(double angle) {
    rotationAngle = angle;
}

void Line::animate(const QSize& bounds) {
    static int direction = 1;

    move(direction * 5, 0);

    if (first.x() < 0 || last.x() > bounds.width()) {
        direction *= -1;
    }
}
