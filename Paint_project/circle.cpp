#include "circle.h"
#include <QtMath>

int Circle::count = 0;


Circle::Circle(const QPointF& center, qreal radius, const QColor& color, int penWidth)
{
    m_center = center;
    m_radius = radius;
    this->color = color;
    this->lineThickness = penWidth;
    this->rotationAngle = 0;
}

QPointF Circle::center() const
{
    return m_center;
}

void Circle::setCenter(const QPointF& center)
{
    m_center = center;
}

qreal Circle::radius() const
{
    return m_radius;
}

void Circle::setRadius(qreal radius)
{
    m_radius = radius;
}

void Circle::draw(QPainter* painter)
{
    painter->save();
    QPen pen(color, lineThickness);
    painter->setPen(pen);

    painter->translate(m_center);
    painter->rotate(rotationAngle);
    painter->drawEllipse(QPointF(0, 0), m_radius, m_radius);
    painter->restore();
}

bool Circle::contains(const QPointF& point)
{
    qreal distToCenter = QLineF(m_center, point).length();
    qreal tolerance = 5.0;
    return qAbs(distToCenter - m_radius) <= tolerance;
}


void Circle::move(int dx, int dy)
{
    m_center += QPointF(dx, dy);
}

void Circle::resize(double factor)
{
    m_radius *= factor;
}

void Circle::rotate(double angle)
{
    rotationAngle = angle;
}

void Circle::animate(const QSize& bounds)
{
    m_center += m_velocity;

    if (m_center.x() - m_radius < 0 || m_center.x() + m_radius > bounds.width()) {
        m_velocity.setX(-m_velocity.x());
    }
    if (m_center.y() - m_radius < 0 || m_center.y() + m_radius > bounds.height()) {
        m_velocity.setY(-m_velocity.y());
    }
}
