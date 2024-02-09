#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "myclassexpression.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void checkLineEdit();
    void setLineEditValidator();
    void setDefaultValues();

private slots:
    void on_xpLineEdit_textChanged(const QString &arg1);

    void on_xkLineEdit_textChanged(const QString &arg1);

    void on_iterLineEdit_textChanged(const QString &arg1);

    void on_pointLineEdit_textChanged(const QString &arg1);

    void on_calculatePushButton_clicked();

    void on_clearPushButton_clicked();

private:
    Ui::MainWindow *ui;
    MyClassExpression *mainObject;

};
#endif // MAINWINDOW_H
