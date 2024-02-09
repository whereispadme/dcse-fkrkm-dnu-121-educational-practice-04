#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::getSignalFromInputForm(Person *&person)
{

    form->hide();
    this->mainPerson = person;

    query = new QSqlQuery(db);

    query->prepare("INSERT INTO person (lastname, firstname, dateOfBirthday, sex) "
                             "VALUES (:lastname, :firstname, :dateOfBirthday, :sex)");

    query->bindValue(":lastname", QString::fromStdString(person->getDataObject()[0]));
    query->bindValue(":firstname", QString::fromStdString(person->getDataObject()[1]));
    query->bindValue(":dateOfBirthday", QString::fromStdString(person->getDataObject()[2]));
    query->bindValue(":sex", QString::fromStdString(person->getDataObject()[3]));
    query->exec();

    query = new QSqlQuery(db);

    query->prepare("INSERT INTO zodiac (sign) "
                   "VALUES (:sign)");

    query->bindValue(":sign", QString::fromStdString(person->getDataObject()[4]));
    query->exec();

    setTableView();
    checkEmptyDatabase();

}

void MainWindow::getSignalFromRequestForm(bool attribute, std::string name)
{

    _requestForm->hide();

   switch(attribute)
   {

   case 0:{

       QString queryStr("SELECT person.lastname, person.firstname, person.dateofbirthday, person.sex, zodiac.sign, person.id FROM person, zodiac WHERE person.lastname = '" + QString::fromStdString(name) + "' and person.id = zodiac.zodiac_id;");
       qModel->setQuery(queryStr, db);

       ui->tableView->setModel(qModel);
       setTableViewProperties();
       break;
   }

   case 1:{

       QString queryStr("SELECT person.lastname, person.firstname, person.dateofbirthday, person.sex, zodiac.sign, person.id FROM person, zodiac WHERE zodiac.sign = '" + QString::fromStdString(name) + "' and person.id = zodiac.zodiac_id;");
       qModel->setQuery(queryStr, db);

       ui->tableView->setModel(qModel);
       setTableViewProperties();
       break;
   }

   }

}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("КущевскийАндрей, ПЗ-19-1 | lab 08");

    this->form = new inputDataToDb;

    connect(this, &MainWindow::signalToInputForm, form, &inputDataToDb::getSignalFromMainForm);
    connect(form, &inputDataToDb::signalToMainForm, this, &MainWindow::getSignalFromInputForm);

    this->_requestForm = new requestForm;

    connect(this, &MainWindow::signalToRequestForm, _requestForm, &requestForm::getSignalFromMainForm);
    connect(_requestForm, &requestForm::signalToMainForm, this, &MainWindow::getSignalFromRequestForm);

    this->model = nullptr;
    this->query = nullptr;
    this->qModel = nullptr;

    connectToSqlServer();
    setTableView();
    setTableView();

    this->currentRowInTableView = 0;

    checkEmptyDatabase();

}

MainWindow::~MainWindow()
{

    delete this->ui;
    delete this->form;
    delete this->_requestForm;

    delete this->model;
    delete this->query;
    delete this->qModel;

}

void MainWindow::checkEmptyDatabase()
{

    QVariant myData;
    QModelIndex myIndex;

    myIndex = ui->tableView->model()->index(0, 0, QModelIndex());
    myData = ui->tableView->model()->data(myIndex, Qt::ItemDataRole());
    QString lastname = myData.toString();

    if(lastname.isEmpty())
    {
        ui->resetPushButton->setEnabled(false);
        ui->removePushButton->setEnabled(false);
        ui->uploadPushButton->setEnabled(false);
        ui->requestPushButton->setEnabled(false);
    }
    else
    {
        ui->resetPushButton->setEnabled(true);
        ui->removePushButton->setEnabled(true);
        ui->uploadPushButton->setEnabled(true);
        ui->requestPushButton->setEnabled(true);
    }

}

void MainWindow::connectToSqlServer()
{

    db = QSqlDatabase::addDatabase("QODBC", "MYSQL");//сообщаем драйвер qt для mysql
    query = new QSqlQuery(db);

    QString connect = "DRIVER={MySQL ODBC 8.0 Unicode Driver};";

    //параметры подключения к бд
    connect.append("SERVER=localhost, 3306;");
    connect.append("DATABASE=lab08;");
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

void MainWindow::setTableViewProperties()
{

    qModel->setHeaderData(0, Qt::Horizontal, tr("Фамилия"));
    qModel->setHeaderData(1, Qt::Horizontal, tr("Имя"));
    qModel->setHeaderData(2, Qt::Horizontal, tr("Дата рождения"));
    qModel->setHeaderData(3, Qt::Horizontal, tr("Пол"));
    qModel->setHeaderData(4, Qt::Horizontal, tr("Знак зодиака"));
    qModel->setHeaderData(5, Qt::Horizontal, tr(""));

    ui->tableView->resizeColumnsToContents();

    //Устанавливаем ширину колонок
    ui->tableView->setColumnWidth(0, 100);
    ui->tableView->setColumnWidth(1, 100);
    ui->tableView->setColumnWidth(2, 100);
    ui->tableView->setColumnWidth(3, 120);
    ui->tableView->setColumnWidth(4, 120);
    ui->tableView->setColumnWidth(5, 0);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->setModel(qModel);
    ui->tableView->selectRow(0);

}

void MainWindow::setTableView()
{

    QString queryStr("SELECT person.lastname, person.firstname, person.dateofbirthday, person.sex, zodiac.sign, person.id FROM person, zodiac WHERE person.id = zodiac.zodiac_id;");
    qModel = new QSqlQueryModel(this);
    qModel->setQuery(queryStr, db);

    setTableViewProperties();

}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

    this->currentRowInTableView = index.row();

}

void MainWindow::on_uploadPushButton_clicked()
{
    setTableView();
    checkEmptyDatabase();
}

void MainWindow::on_addPushButton_clicked()
{

    emit signalToInputForm();

}

void MainWindow::on_removePushButton_clicked()
{

    QVariant myData;
    QModelIndex myIndex;

    myIndex = ui->tableView->model()->index(this->currentRowInTableView, 5, QModelIndex());
    myData = ui->tableView->model()->data(myIndex, Qt::ItemDataRole());
    QString id = myData.toString();

    QString query;

    query = ("DELETE FROM person WHERE person.id = " + id + ";");
    qModel->setQuery(query, db);

    query = ("DELETE FROM zodiac WHERE zodiac.zodiac_id = " + id + ";");
    qModel->setQuery(query, db);

    setTableView();
    checkEmptyDatabase();

}

void MainWindow::on_resetPushButton_clicked()
{

    query->prepare("DELETE FROM person;");
    query->exec();

    query->prepare("DELETE FROM zodiac;");
    query->exec();

    setTableView();

    checkEmptyDatabase();

}

void MainWindow::on_requestPushButton_clicked()
{

    emit signalToRequestForm();

}

