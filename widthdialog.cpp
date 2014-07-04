#include "widthdialog.h"
#include "ui_widthdialog.h"
#include <QDebug>

WidthDialog::WidthDialog(int defaultValue, QWidget *parent) :
    QDialog(parent),    
    ui(new Ui::WidthDialog),
    m_width(defaultValue)
{    
    ui->setupUi(this);
    ui->spinBox->setValue(m_width);
}

WidthDialog::~WidthDialog()
{
    delete ui;
}

void WidthDialog::on_pushButton_clicked()
{
    m_width = ui->spinBox->value();
    accept();
}
