#ifndef WIDTHDIALOG_H
#define WIDTHDIALOG_H

// Qt headers
#include <QDialog>

namespace Ui {
class WidthDialog;
}

/**
 * @brief The WidthDialog class
 * @detailed class for setting custom line width with dialog window
 */
class WidthDialog : public QDialog
{
    Q_OBJECT

    Ui::WidthDialog *ui;
    int m_width;

public:
/**
 * @brief WidthDialog
 * @param defaultValue default value in spinBox
 * @param parent parent of this QDialog
 */
    explicit WidthDialog(int defaultValue, QWidget *parent = 0);
/**
 * @brief Destructor
 */
    ~WidthDialog();
/**
 * @brief getValue
 * @return new width
 */
    int getValue() {return m_width; }

private slots:
/**
 * @brief on_pushButton_clicked
 * @detailed closes window
 */
    void on_pushButton_clicked();
};

#endif // WIDTHDIALOG_H
