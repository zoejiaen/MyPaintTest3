// Qt headers
#include <QColorDialog>

// internal headers
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widthdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myPaintWidget(new MyPaintWidget(this))
{
    ui->setupUi(this);       
    ui->verticalLayout->addWidget(myPaintWidget); // creating painting area
}

void MainWindow::mousePressEvent(QMouseEvent *)
{
    // check whether click was on painting area
    if (!myPaintWidget->rect().contains(myPaintWidget->mapFromGlobal(QCursor::pos())))
        return;

    // indicates that we are to create figure
    m_pressed = true;
    // getting cursos coordinates inside drawing area
    m_press = myPaintWidget->mapFromGlobal(QCursor::pos());

    // creating figure
    if (m_pencil) // for pencil
        myPaintWidget->addShape(new Pencil(m_press, m_color, m_width));
    else // for other figures
        myPaintWidget->addShape(getFigure(m_press, m_press));
}

void MainWindow::mouseMoveEvent(QMouseEvent *)
{
    // check whether we're creating figure
    if (!m_pressed)
        return;

    // getting cursor coordinates inside drawing area
    m_release = myPaintWidget->mapFromGlobal(QCursor::pos());

    if (m_pencil) // for pencil
    {
        // adding new point to pencil shape
        Pencil &pencil = dynamic_cast<Pencil &>(myPaintWidget->lastShape());
        pencil.addPoint(m_release);
        // redrawing
        myPaintWidget->update();
    }
    else // for other figures
    {
        // deletes figure of old size
        myPaintWidget->popShape();
        // adding figure of new size
        myPaintWidget->addShape(getFigure(m_press, m_release));
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    // check whether we're creating new figure
    if (!m_pressed)
        return;

    // indicates that we have finished creating of new figure
    m_pressed = false;
    // getting cursor coordinates inside painting area
    m_release = myPaintWidget->mapFromGlobal(QCursor::pos());
    if (m_pencil) // for pencil
    {
        // adding new point to pencil shape
        Pencil pencil = dynamic_cast<Pencil &>(myPaintWidget->lastShape());
        pencil.addPoint(m_release);
        // redrawing
        myPaintWidget->update();
    }
    else
    {
        // deletes figure of old size
        myPaintWidget->popShape();
        // adding figure of new size
        myPaintWidget->addShape(getFigure(m_press, m_release));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionUndo_triggered()
{
    // undo button - deletes last shape
    if (!myPaintWidget->empty())
        myPaintWidget->popShape();
}

void MainWindow::uncheckWidth() // makes all width options unchecked
{
    QList<QAction *> lst = ui->menuWidth->actions();
    for (QAction *m : lst)    
        m->setChecked(false);    
}

void MainWindow::on_action1_triggered()
{
    uncheckWidth();
    ui->action1->setChecked(true);
    m_width = 1;
}

void MainWindow::on_action2_triggered()
{
    uncheckWidth();
    ui->action2->setChecked(true);
    m_width = 2;
}

void MainWindow::on_action3_triggered()
{
    uncheckWidth();
    ui->action3->setChecked(true);
    m_width = 3;
}

void MainWindow::on_actionOther_triggered()
{
    uncheckWidth();
    ui->actionOther->setChecked(true);
    WidthDialog diag(m_width, this);
    if (diag.exec() == QDialog::Accepted)    
        m_width = diag.getValue();    
}

void MainWindow::on_actionPickColor_triggered()
{
    m_color = QColorDialog::getColor(m_color, this);
}

// creates new figure depending on checked menu item, allacotes memory
// for this objecct
Shape* MainWindow::getFigure(const QPoint &p1, const QPoint &p2) const
{
    if (ui->actionLine->isChecked())
        return new Line(p1, p2, m_color, m_width);
    if (ui->actionRectangle->isChecked())
        return new Rectangle(p1, p2, m_color, m_width);
    if (ui->actionEllipse->isChecked())
        return new Ellipse(p1, p2, m_color, m_width);

    return nullptr;
}

void MainWindow::uncheckFigure() // makes all figure options unchecked
{
    QList<QAction *> lst = ui->menuFigure->actions();
    for (QAction *m : lst)    
        m->setChecked(false);

    ui->pencil->setChecked(false);
    m_pencil = false;
}

void MainWindow::on_actionLine_triggered()
{
    uncheckFigure();
    ui->actionLine->setChecked(true);
}

void MainWindow::on_actionRectangle_triggered()
{
    uncheckFigure();
    ui->actionRectangle->setChecked(true);
}

void MainWindow::on_actionEllipse_triggered()
{
    uncheckFigure();
    ui->actionEllipse->setChecked(true);
}

void MainWindow::on_pencil_triggered()
{
    uncheckFigure();
    ui->pencil->setChecked(true);
    m_pencil = true;
}
