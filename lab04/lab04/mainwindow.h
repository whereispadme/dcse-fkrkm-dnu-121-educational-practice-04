#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>

#include <QDoubleValidator>
#include <QMessageBox>

#include <QStandardItemModel>
#include <QStandardItem>

#include <iostream>
#include <vector>
#include <fstream>

#include "function.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setEditValidator();
    void setDefaultValues();
    bool checkEditValid();

private slots:
    void on_pointRadioButton_clicked();

    void on_intervalRadioButton_clicked();

    void on_resetPushButton_clicked();

    void on_calculatePushButton_clicked();

    void on_saveInFilePushButton_clicked();

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model;
    QStandardItem *item;

    std::vector<point>    vectorPointObject;
    std::vector<interval> vectorIntervalObject;

};
#endif // MAINWINDOW_H
