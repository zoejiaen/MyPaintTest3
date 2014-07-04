#ifndef SHAPE_H
#define SHAPE_H

// Qt headers
#include <QPoint>
#include <QColor>
#include <QPainter>

/**
 * @brief The Shape base class class
 * @detailed Provides interface for all supported figures
 * Use this base class in order to extend supported shapes
 */
class Shape
{    
public:
/**
 * @brief draw
 * @detailed draws appropriate Shape
 * @param QPainter QPainter which will be used for drawing
 */
    virtual void draw(QPainter &) const = 0;        
 /**
  * @brief ~Shape
  * @detailed Destructor (virtual, empty)
  */
    virtual ~Shape() {}
};

/**
 * @brief The Line class
 * @detailed Class for drawing lines with different colors
 * and widths
 */
class Line : public Shape
{
    QPoint m_p1, m_p2;
    QColor m_color;
    int m_width;

public:
    Line(const QPoint &, const QPoint &, const QColor &, int width);
    void draw(QPainter &) const;
};

/**
 * @brief The Rectangle class
 * @detailed Class for drawing rectangles with different colors
 * and widths
 */
class Rectangle : public Shape
{
    QPoint m_p1, m_p2;
    QColor m_color;
    int m_width;

public:
    Rectangle(const QPoint &, const QPoint &, const QColor &, int width);
    void draw(QPainter &) const;
};

/**
 * @brief The Ellipse class
 * @detailed Class for drawing ellipses with different colors
 * and widths
 */
class Ellipse : public Shape
{
    QPoint m_p1, m_p2;
    QColor m_color;
    int m_width;

public:
    Ellipse(const QPoint &, const QPoint &, const QColor &, int width);
    void draw(QPainter &) const;
};

/**
 * @brief The Pencil class
 * @detailed Class for drawing any shapes with different colors
 * and widths
 */
class Pencil : public Shape
{    
    std::vector<QPoint> m_pointVector;
    QColor m_color;
    int m_width;

public:
    Pencil(const QPoint &, const QColor &, int width);
    Pencil(const QColor &, int width);
 /**
  * @brief addPoit
  * @detailed adds new point to figure, that will be connected
  * by line with previous point
  * @param point new point
  */
    void addPoint(const QPoint &);
    void draw(QPainter &) const;
};

#endif // SHAPE_H
