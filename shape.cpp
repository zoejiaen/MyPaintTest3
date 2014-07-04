#include "shape.h"
#include <QDebug>

Line::Line(const QPoint &p1, const QPoint &p2, const QColor &color, int width) :
    m_p1(p1),
    m_p2(p2),
    m_color(color),
    m_width(width)
{
}

void Line::draw(QPainter &painter) const
{
    QPen pen(m_color);
    pen.setWidth(m_width);
    QPen temp = painter.pen();
    painter.setPen(pen);
    painter.drawLine(m_p1, m_p2);
    painter.setPen(temp);
}

Rectangle::Rectangle(const QPoint &p1, const QPoint &p2, const QColor &color, int width) :
    m_p1(p1),
    m_p2(p2),
    m_color(color),
    m_width(width)
{
}

void Rectangle::draw(QPainter &painter) const
{
    QPen pen(m_color);
    pen.setWidth(m_width);
    QPen temp = painter.pen();
    painter.setPen(pen);
    painter.drawRect(QRect(m_p1, m_p2));
    painter.setPen(temp);
}

Ellipse::Ellipse(const QPoint &p1, const QPoint &p2, const QColor &color, int width) :
    m_p1(p1),
    m_p2(p2),
    m_color(color),
    m_width(width)
{
}

void Ellipse::draw(QPainter &painter) const
{
    QPen pen(m_color);
    pen.setWidth(m_width);
    QPen temp = painter.pen();
    painter.setPen(pen);
    painter.drawEllipse(QRect(m_p1, m_p2));
    painter.setPen(temp);
}


Pencil::Pencil(const QColor &color, int width) :
    m_color(color),
    m_width(width)
{
}

Pencil::Pencil(const QPoint &point, const QColor &color, int width) :
    m_color(color),
    m_width(width)
{
    m_pointVector.push_back(point);
}

void Pencil::addPoint(const QPoint &p)
{    
    m_pointVector.push_back(p);        
}

void Pencil::draw(QPainter &painter) const
{
    if (m_pointVector.size() < 2)
        return;

    QPen pen(m_color);
    pen.setWidth(m_width);
    QPen temp = painter.pen();
    painter.setPen(pen);
    for (size_t i = 1; i < m_pointVector.size(); i++)
        painter.drawLine(m_pointVector[i - 1], m_pointVector[i]);

    painter.setPen(temp);
}
