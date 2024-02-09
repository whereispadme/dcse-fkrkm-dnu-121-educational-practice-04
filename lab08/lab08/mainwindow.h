#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "inputdatatodb.h"
#include "requestform.h"

#include "person.h"

#include <QMainWindow>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlTableModel>

#include <QSqlQueryModel>
#include <QSqlQuery>

#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void signalToInputForm();
    void signalToRequestForm();

public slots:
    void getSignalFromInputForm(Person *&person);
    void getSignalFromRequestForm(bool attribute, std::string name);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void checkEmptyDatabase();

    void connectToSqlServer();

    void setTableView();

    void setTableViewProperties();

private slots:

    void on_tableView_clicked(const QModelIndex &index);

    void on_uploadPushButton_clicked();

    void on_addPushButton_clicked();

    void on_removePushButton_clicked();

    void on_resetPushButton_clicked();

    void on_requestPushButton_clicked();

private:
    Ui::MainWindow *ui;
    inputDataToDb *form;
    requestForm *_requestForm;

    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQuery *query;
    QSqlQueryModel *qModel;

    Person *mainPerson;

    int currentRowInTableView;

};
#endif // MAINWINDOW_H
