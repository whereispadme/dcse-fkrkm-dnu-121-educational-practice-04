#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->model = nullptr;
    this->qModel = nullptr;
    this->query = nullptr;

    setWindowTitle("КущевскийАндрей, ПЗ-19-1 | lab01");

    connectToSql();//вызов метода для подключения к БД
    setTable();    //вызов метода для взаимодействия с listView

}

MainWindow::~MainWindow()
{

    //освобождаем ресурсы
    delete ui;

    db.close();

    if(this->model != nullptr)
        delete this->model;

    if(this->qModel != nullptr)
        delete this->qModel;

    if(this->query != nullptr)
        delete this->query;

}

void MainWindow::connectToSql()
{

    db = QSqlDatabase::addDatabase("QODBC", "MYSQL");//сообщаем драйвер qt для mysql
    query = new QSqlQuery(db);

    QString connect = "DRIVER={MySQL ODBC 8.0 Unicode Driver};";

    //параметры подключения к бд
    connect.append("SERVER=localhost, 3306;");
    connect.append("DATABASE=practicedb;");
    connect.append("USER=root;");
    connect.append("PASSWORD=23kapkap;");
    connect.append("MULTI_HOST=1;");

    db.setDatabaseName(connect);

    if(db.open())
    {
        qDebug("open");
        ui->statusDatabaseConnect->setTextColor(Qt::darkGreen);
        ui->statusDatabaseConnect->setText("Статус подключения: Успешно!");
    }
    else
    {
        qDebug("not open");
        ui->statusDatabaseConnect->setTextColor(Qt::red);
        ui->statusDatabaseConnect->setText("Статус подключения: Неудачно!");
    }

}

void MainWindow::setTable()
{

    model = new QSqlTableModel(this, db);
    model->setTable("employees");

    //Устанавливаем заголовки(название атрибутов)
    model->setHeaderData(0, Qt::Horizontal, tr("Фамилия"));
    model->setHeaderData(1, Qt::Horizontal, tr("Имя"));
    model->setHeaderData(2, Qt::Horizontal, tr("Отчество"));
    model->setHeaderData(3, Qt::Horizontal, tr("Идентиф. код"));
    model->setHeaderData(4, Qt::Horizontal, tr("Дата рождения"));
    model->setHeaderData(5, Qt::Horizontal, tr("Домашний адрес"));
    model->setHeaderData(6, Qt::Horizontal, tr("Телефон"));

    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    //Устанавливаем сортировку по атрибутам
    ui->tableView->setSortingEnabled(true);

    model->select();
    ui->tableView->setModel(model);
    ui->tableView->selectRow(0);

    //Устанавливаем ширину колонок
    ui->tableView->setColumnWidth(0, 100);
    ui->tableView->setColumnWidth(1, 100);
    ui->tableView->setColumnWidth(2, 100);
    ui->tableView->setColumnWidth(3, 90);
    ui->tableView->setColumnWidth(4, 110);
    ui->tableView->setColumnWidth(5, 110);
    ui->tableView->setColumnWidth(6, 110);

}

//текущая выбранная строка в таблице
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    this->currentRow = index.row();
}

//обновить таблицу
void MainWindow::on_refreshButton_clicked()
{
    ui->tableView->setModel(model);
    model->select();
    ui->tableView->selectRow(currentRow);
}

//добавить в таблицу
void MainWindow::on_addButton_clicked()
{
    model->insertRow(model->rowCount());
}

//удалить запись из таблицы
void MainWindow::on_removeButton_clicked()
{
    model->removeRow(this->currentRow);
    model->select();
}

//очистить все записи
void MainWindow::on_clearButton_clicked()
{
    query = new QSqlQuery("DELETE FROM employees;", db);
    model->select();
}

//выполнение запроса(Видавати перелік та кількість співробітників, вік яких менший, ніж вказаний)
void MainWindow::on_queryButton_clicked()
{

    std::string correctInt = ui->ageEdit->text().toStdString();
    bool validStatus = correctUnsignedIntegerValue(correctInt);

    if(validStatus != true)
    {

        QMessageBox *incorrectInputMsg = new QMessageBox(this);

        incorrectInputMsg->setWindowTitle("Ошибка ввода!");
        incorrectInputMsg->setText("Неккоректный ввод значения");
        incorrectInputMsg->show();

        ui->ageEdit->clear();

        delete incorrectInputMsg;

        return;

    }

    int ageEdit = stoi(correctInt);   
    QString query = "SELECT * From employees where (YEAR(CURRENT_DATE) - YEAR(dateofbirthday)) - (DATE_FORMAT(CURRENT_DATE, '%m%d') < DATE_FORMAT(dateofbirthday, '%m%d')) < " + QString::number(ageEdit) + ";";

    qModel = new QSqlQueryModel(this);
    qModel->setQuery(query, db);

    ui->tableView->setModel(qModel);

    //Устанавливаем заголовки(название атрибутов)
    qModel->setHeaderData(0, Qt::Horizontal, tr("Фамилия"));
    qModel->setHeaderData(1, Qt::Horizontal, tr("Имя"));
    qModel->setHeaderData(2, Qt::Horizontal, tr("Отчество"));
    qModel->setHeaderData(3, Qt::Horizontal, tr("Идентиф. код"));
    qModel->setHeaderData(4, Qt::Horizontal, tr("Дата рождения"));
    qModel->setHeaderData(5, Qt::Horizontal, tr("Домашний адрес"));
    qModel->setHeaderData(6, Qt::Horizontal, tr("Телефон"));

}
