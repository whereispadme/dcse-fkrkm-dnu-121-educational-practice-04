#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <QRegularExpressionValidator>
#include <QMessageBox>

#include <QStandardItemModel>
#include <QStandardItem>

#include "buyer.h"
#include "book.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setDefaultObjectValues();
    void setEditValidator();
    void setTable();
    bool checkCorrectInput();

private slots:
    void on_addPurchaseButton_clicked();

    void on_clearListButton_clicked();

    void on_queryPushButton_clicked();

    void on_resetTableButton_clicked();

private:
    Ui::MainWindow *ui;

    QMessageBox *messageBox;
    QStandardItemModel *model;
    QStandardItem *item;

    Buyer *mainBuyers;
    Buyer buyer;

    int row;
    int mainBuyersSizeof;

};
#endif // MAINWINDOW_H
