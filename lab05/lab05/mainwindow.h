#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MyArray.h"

#include <vector>

#include <QDebug>
#include <QMainWindow>

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
    void setLineEditValidator(bool choice);

    void setResultsData();
    void setListWidget(bool typeOfArray);
    void setListWidget_2(bool typeOfArray);

private slots:
    void on_sizeOfArrayLineEdit_textChanged(const QString &arg1);

    void on_intRadioButton_clicked();

    void on_doubleRadioButton_clicked();

    void on_sizeOfArrayPushButton_clicked();

    void on_addNewValueToArrPushButton_clicked();

    void on_indexLineEdit_textChanged(const QString &arg1);

    void on_queryRequestPushButton_clicked();

    void on_resetPushButton_clicked();

private:
    Ui::MainWindow *ui;

    MyArray<int> *intArray;
    MyArray<double> *doubleArray;

    std::vector<int> intVector;
    std::vector<double> doubleVector;

    unsigned int currentIndex;
    std::string status;

};
#endif // MAINWINDOW_H
