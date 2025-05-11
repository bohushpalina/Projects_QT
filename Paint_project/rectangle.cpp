#include "rectangle.h"

int Rectangle::count = 0;

Rectangle::Rectangle(const QPointF& topLeft, const QPointF& bottomRight, const QColor& color, int penWidth)
{
    rect = QRectF(topLeft, bottomRight).normalized();
    this->color = color;
    this->lineThickness = penWidth;
    this->rotationAngle = 0.0;
    id = ++count;
}

Rectangle::Rectangle(const QPointF& topLeft, const QSize& size, const QColor& color, int penWidth)
{
    rect = QRectF(topLeft, QSizeF(size));
    this->color = color;
    this->lineThickness = penWidth;
    this->rotationAngle = 0.0;
    id = ++count;
}

void Rectangle::draw(QPainter* painter)
{
    painter->save();

    QPen pen(color, lineThickness);
    painter->setPen(pen);

    painter->translate(rect.center());
    painter->rotate(rotationAngle);
    painter->translate(-rect.center());

    painter->drawRect(rect);

    painter->restore();
}

bool Rectangle::contains(const QPointF& point)
{
    const qreal tolerance = 5.0;

    QPointF center = rect.center();

    QTransform transform;
    transform.translate(center.x(), center.y());
    transform.rotate(-rotationAngle);
    transform.translate(-center.x(), -center.y());

    QPointF rotatedPoint = transform.map(point);

    QLineF top(rect.topLeft(), rect.topRight());
    QLineF right(rect.topRight(), rect.bottomRight());
    QLineF bottom(rect.bottomRight(), rect.bottomLeft());
    QLineF left(rect.bottomLeft(), rect.topLeft());

    auto isNearEdge = [&](const QLineF& edge) {
        double distance = distanceToSegment(rotatedPoint, edge.p1(), edge.p2());
        return distance <= tolerance;
    };

    return isNearEdge(top) || isNearEdge(right) || isNearEdge(bottom) || isNearEdge(left);
}

double Rectangle::distanceToSegment(const QPointF& point, const QPointF& start, const QPointF& end) {
    double dx = end.x() - start.x();
    double dy = end.y() - start.y();
    double lengthSquared = dx * dx + dy * dy;

    if (lengthSquared == 0.0)
        return QLineF(point, start).length();

    double t = ((point.x() - start.x()) * dx + (point.y() - start.y()) * dy) / lengthSquared;
    t = std::max(0.0, std::min(1.0, t));
    QPointF projection(start.x() + t * dx, start.y() + t * dy);
    return QLineF(point, projection).length();
}

void Rectangle::move(int dx, int dy)
{
    rect.translate(dx, dy);
}

void Rectangle::resize(double factor)
{
    QPointF center = rect.center();
    QSizeF newSize = rect.size() * factor;
    rect.setSize(newSize);
    rect.moveCenter(center);
}

void Rectangle::rotate(double angle)
{
    rotationAngle = angle;
}

void Rectangle::animate(const QSize& bounds)
{
    if (movingUp)
        rect.translate(0, -2);
    else
        rect.translate(0, 2);

    if (rect.top() < 0 || rect.bottom() > bounds.height())
        movingUp = !movingUp;
}
