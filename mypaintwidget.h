#ifndef MYPAINTWIDGET_H
#define MYPAINTWIDGET_H

// Qt headers
#include <QWidget>

// STL headers
#include <list>

// internal headers
#include "shape.h"

/**
 * @brief The MyPaintWidget class for drawig shapes on QWidget
 * @detailed Implements drawing shapes on QWidget or its derived
 * class, for list of all supported shapes see shape.h header
 */

class MyPaintWidget : public QWidget
{

    Q_OBJECT

    std::list <Shape*> shapes;
    QColor m_backgroundColor = Qt::white;

public:
/**
 * @brief Constructor
 * @detailed Only initializes parent
 * @param parent Parent QWidget of MyPaintWidget, default value is 0
 */
    explicit MyPaintWidget(QWidget *parent = 0);
/**
 * @brief Destuctor (virtual)
 * @detailed Destructs all shapes
 */
    virtual ~MyPaintWidget();
/**
 * @brief paintEvent
 * @detailed Function draws all shapes. This function is called by
 * enviroment (when resizing window or similar events). You can call
 * this function using update() (inherited from QWidget)
 * @param event not used
 */
    void paintEvent(QPaintEvent *);
/**
 * @brief addShape
 * @detailed Adds shape to screen and redraws screen
 * @param shape pointer to an object derived from Shape class, object
 * should be allocated in heap, Destructor of MyPaintWidget will
 * deallocate this object
 * @throw std::invalid_argument if null pointer was passed
 */
    void addShape(Shape *shape);
/**
 * @brief lastShape
 * @return reference to the object that was added last
 * @throw std::runtime_error if list of shapes is empty
 */
    Shape &lastShape();
/**
 * @brief popShape
 * @detailed deletes Shape object that was added last
 * @throw std::runtime_error if list of shapes is empty
 */
    void popShape();
/**
 * @brief empty
 * @return true if painting area is empty, false - if not
 */
    bool empty() const { return shapes.empty(); }
};

#endif // MYPAINTWIDGET_H
