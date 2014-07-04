#include "mypaintwidget.h"
#include <QPainter>
#include <exception>
#include <QDebug>

MyPaintWidget::MyPaintWidget(QWidget *parent) :
    QWidget(parent)
{

}

void MyPaintWidget::paintEvent(QPaintEvent *)
{    
    QImage screen(this->size(), QImage::Format_RGB32);
    screen.fill(m_backgroundColor);
    QPainter p(&screen);

    for (Shape *s : shapes)
        s->draw(p);

    QPainter painter(this);
    painter.drawImage(0, 0, screen);
}

void MyPaintWidget::addShape(Shape *shape)
{
    if (!shape)
        throw std::invalid_argument("Invalid shape argument: null pointer");

    shapes.push_back(shape);
    update();
}

void MyPaintWidget::popShape()
{
    if (shapes.empty())
        throw std::runtime_error("No shapes exists");

    delete shapes.back();
    shapes.pop_back();
    update();
}

Shape &MyPaintWidget::lastShape()
{
    if (shapes.empty())
        throw std::runtime_error("No shapes exists");

    return *shapes.back();
}

MyPaintWidget::~MyPaintWidget()
{
    for (auto s : shapes)
        delete s;
}
