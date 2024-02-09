#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "matrix.h"

#include <vector>

#include <QDebug>
#include <QMainWindow>

#include <QIntValidator>

#include "inputqueryform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setDefaultValues(bool deleteStatus);

    void setLineEditValidator();

    void setTableWidgetByMatrix();

private slots:

    void on_rowsCountLineEdit_textChanged(const QString &arg1);

    void on_sizeOfMatrixApplyPushButton_clicked();

    void on_indexLineEdit_textChanged(const QString &arg1);

    void on_addNewValueToArrPushButton_clicked();

    void on_resetPushButton_clicked();

    void on_queryRequestPushButton_clicked();

signals:
    void sendSignalToInputQueryForm(int rows);

private:
    Ui::MainWindow *ui;
    inputQueryForm *form;

    Matrix *matrix;

    QIntValidator *intValidator;
    std::vector<Matrix> vectorForLineEditMatrix;

    unsigned int rows;
    unsigned int cols;

    unsigned int currentRow;
    unsigned int currentCol;

    bool resetStatus;

    int selectRow;
    int selectCol;

public slots:

    void getSignalFromInputQueryForm(int selectRow, int selectCol);

};
#endif // MAINWINDOW_H
