#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//подключение необходимых библиотек
#include <QDebug>
#include <QMainWindow>

#include <QMessageBox>

#include <QSqlDatabase>  //библиотека для хранения связи с БД
#include <QSqlQuery>     //библиотека для создания запросов на языке SQL

#include <QSqlQueryModel>//библиотека для хранения данных из БД и передача их на TableView
#include <QSqlTableModel>

#include "functions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void connectToSql();//метод для подключения, который используется для подключения к БД
    void setTable();    //метод для корректной работы listView и взаимодействия с ним

private slots:

    void on_tableView_clicked(const QModelIndex &index);

    void on_refreshButton_clicked();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_clearButton_clicked();

    void on_queryButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQueryModel *qModel;
    QSqlQuery *query;

    unsigned int currentRow;

};
#endif // MAINWINDOW_H
