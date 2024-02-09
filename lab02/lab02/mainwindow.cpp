#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("КущевскийАндрей, ПЗ-19-1 | lab02");

    this->mainBuyers = nullptr;

    this->messageBox = nullptr;

    this->model = nullptr;
    this->item = nullptr;

    this->row = 0;
    this->mainBuyersSizeof = 0;

    setDefaultObjectValues();
    setEditValidator();
    setTable();

}

MainWindow::~MainWindow()
{

    delete ui;

    if(this->mainBuyers != nullptr)
        delete this->mainBuyers;

    if(this->messageBox != nullptr)
        delete this->messageBox;

    if(this->model != nullptr)
        delete this->model;

    if(this->item != nullptr)
        delete this->item;

}

void MainWindow::setDefaultObjectValues()
{

    ui->physicsCheckBox->setChecked(false);
    ui->mathCheckBox->setChecked(false);
    ui->infoCheckBox->setChecked(false);

    ui->countOfPhysicsEdit->clear();
    ui->countOfMathEdit->clear();
    ui->countOfInfoEdit->clear();

    ui->countOfPhysicsEdit->setText("0");
    ui->countOfMathEdit->setText("0");
    ui->countOfInfoEdit->setText("0");

    ui->lastNameEdit->clear();
    ui->firstNameEdit->clear();
    ui->middleNameEdit->clear();

}

void MainWindow::setEditValidator()
{

    QRegularExpression regexForOnlySym("^[а-яА-яа-яА-яІіЇї]{20}");
    regexForOnlySym.setPatternOptions(QRegularExpression::UseUnicodePropertiesOption);
    QValidator *validatorForOnlySym = new QRegularExpressionValidator(regexForOnlySym, this);
    validatorForOnlySym->setLocale(QLocale::AnyLanguage);

    ui->lastNameEdit->setValidator(validatorForOnlySym);
    ui->firstNameEdit->setValidator(validatorForOnlySym);
    ui->middleNameEdit->setValidator(validatorForOnlySym);

    ui->countOfPhysicsEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^([1-9][0-9]*|0)"), this));
    ui->countOfMathEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^([1-9][0-9]*|0)"), this));
    ui->countOfInfoEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^([1-9][0-9]*|0)"), this));

}

void MainWindow::setTable()
{

    model = new QStandardItemModel;
    ui->tableView->setModel(model);

    //Заголовки столбцов
    QStringList horizontalHeader;
    horizontalHeader.append("Фамилия");
    horizontalHeader.append("Имя");
    horizontalHeader.append("Отчество");
    horizontalHeader.append("Физика");
    horizontalHeader.append("Математика");
    horizontalHeader.append("Информатика");
    horizontalHeader.append("Общая стоимость");

    model->setHorizontalHeaderLabels(horizontalHeader);
    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView->setColumnWidth(0, 100);
    ui->tableView->setColumnWidth(1, 100);
    ui->tableView->setColumnWidth(2, 100);
    ui->tableView->setColumnWidth(3, 90);
    ui->tableView->setColumnWidth(4, 110);
    ui->tableView->setColumnWidth(5, 110);
    ui->tableView->setColumnWidth(6, 130);

    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    //Устанавливаем сортировку по атрибутам
    ui->tableView->setSortingEnabled(true);

}

bool MainWindow::checkCorrectInput()
{

    bool validStatus = false;

    if(!ui->physicsCheckBox->isChecked() && !ui->mathCheckBox->isChecked() && !ui->infoCheckBox->isChecked())
    {

        messageBox = new QMessageBox(this);
        messageBox->setWindowTitle("Ошибка!");
        messageBox->setText("Выберите минимум один тип учебника!");
        messageBox->exec();
        validStatus = false;
        return validStatus;

    }

    if((ui->lastNameEdit->text() == "" || ui->firstNameEdit->text() == "" || ui->middleNameEdit->text() == "")
       || (ui->physicsCheckBox->isChecked() && ui->countOfPhysicsEdit->text().toUInt() == 0)
       || (ui->mathCheckBox->isChecked() && ui->countOfMathEdit->text().toUInt() == 0)
       || (ui->infoCheckBox->isChecked() && ui->countOfInfoEdit->text().toUInt() == 0))
    {

        messageBox = new QMessageBox(this);
        messageBox->setWindowTitle("Ошибка!");
        messageBox->setText("Все поля должны быть заполнены!");
        messageBox->exec();
        validStatus = false;
        return validStatus;
    }
    else
    {
        if(!(ui->physicsCheckBox->isChecked()))
        {
            ui->countOfPhysicsEdit->setText("0");
        }

        if(!(ui->mathCheckBox->isChecked()))
        {
            ui->countOfMathEdit->setText("0");
        }

        if(!(ui->infoCheckBox->isChecked()))
        {
            ui->countOfInfoEdit->setText("0");
        }
        validStatus = true;
    }

    return validStatus;

}

void MainWindow::on_addPurchaseButton_clicked()
{

    bool validStatus = checkCorrectInput();

    if(validStatus == false)
    {
        return;
    }

    unsigned int totalCount = 0;

    int totalCountOfPhysics = 0;
    int totalCountOfMath = 0;
    int totalCountOfInfo = 0;

    if(ui->physicsCheckBox->isChecked())
    {
        totalCount += ui->countOfPhysicsEdit->text().toUInt();
        totalCountOfPhysics = ui->countOfPhysicsEdit->text().toInt();
    }

    if(ui->mathCheckBox->isChecked())
    {
        totalCount += ui->countOfMathEdit->text().toUInt();
        totalCountOfMath = ui->countOfMathEdit->text().toInt();
    }

    if(ui->infoCheckBox->isChecked())
    {
        totalCount += ui->countOfInfoEdit->text().toUInt();
        totalCountOfInfo = ui->countOfInfoEdit->text().toInt();
    }

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

    Book *book = new Book[totalCount];

    int currentRow = 0;

    for(int i = 0; i < ui->countOfPhysicsEdit->text().toInt(); ++i)
    {

        book[i].setDataBook(ui->physicsCheckBox->text().toStdString());

    }

    currentRow += ui->countOfPhysicsEdit->text().toInt();

    for(int i = currentRow; i < ui->countOfMathEdit->text().toInt(); ++i)
    {

        book[i].setDataBook(ui->countOfMathEdit->text().toStdString());

    }

    currentRow += ui->countOfMathEdit->text().toInt();

    for(int i = currentRow; i < ui->countOfInfoEdit->text().toInt(); ++i)
    {

        book[i].setDataBook(ui->countOfPhysicsEdit->text().toStdString());

    }

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

    Initials localInitials;

    localInitials.lastName = ui->lastNameEdit->text().toStdString();
    localInitials.middleName = ui->firstNameEdit->text().toStdString();
    localInitials.firstName = ui->middleNameEdit->text().toStdString();

    this->buyer.setData(localInitials, book, totalCountOfPhysics, totalCountOfMath, totalCountOfInfo);

    item = new QStandardItem(QString::fromStdString(buyer.getInitials().lastName));
    model->setItem(this->row, 0, item);

    item = new QStandardItem(QString::fromStdString(buyer.getInitials().middleName));
    model->setItem(this->row, 1, item);

    item = new QStandardItem(QString::fromStdString(buyer.getInitials().firstName));
    model->setItem(this->row, 2, item);

    item = new QStandardItem(QString::number(buyer.getTotalEachSum()[0]));
    model->setItem(this->row, 3, item);

    item = new QStandardItem(QString::number(buyer.getTotalEachSum()[1]));
    model->setItem(this->row, 4, item);

    item = new QStandardItem(QString::number(buyer.getTotalEachSum()[2]));
    model->setItem(this->row, 5, item);

    item = new QStandardItem(QString::number(buyer.getTotalSum()));
    model->setItem(this->row, 6, item);

    if(this->row == 0)
    {
        this->mainBuyers = new Buyer[1];
        this->mainBuyersSizeof = 1;
        this->mainBuyers[0] = buyer;
    }
    else
    {

        Buyer *mainBuyersCopy = new Buyer[mainBuyersSizeof];

            for (int i = 0; i < mainBuyersSizeof; ++i)
            {

                mainBuyersCopy[i] = mainBuyers[i];

            }

            mainBuyersSizeof++;

            delete[] mainBuyers;
            mainBuyers = new Buyer[mainBuyersSizeof];

            for (int i = 0; i < mainBuyersSizeof - 1; ++i)
            {

                mainBuyers[i] = mainBuyersCopy[i];

            }

            int index = mainBuyersSizeof - 1;

            mainBuyers[index] = buyer;

            delete[] mainBuyersCopy;
    }

    this->row++;

    setDefaultObjectValues();

    for(int i = 0; i < this->mainBuyersSizeof; ++i)
    {

        item = new QStandardItem(QString::fromStdString(this->mainBuyers[i].getInitials().lastName));
        model->setItem(i, 0, item);

        item = new QStandardItem(QString::fromStdString(this->mainBuyers[i].getInitials().middleName));
        model->setItem(i, 1, item);

        item = new QStandardItem(QString::fromStdString(this->mainBuyers[i].getInitials().firstName));
        model->setItem(i, 2, item);

        item = new QStandardItem(QString::number(this->mainBuyers[i].getTotalEachSum()[0]));
        model->setItem(i, 3, item);

        item = new QStandardItem(QString::number(this->mainBuyers[i].getTotalEachSum()[1]));
        model->setItem(i, 4, item);

        item = new QStandardItem(QString::number(this->mainBuyers[i].getTotalEachSum()[2]));
        model->setItem(i, 5, item);

        item = new QStandardItem(QString::number(this->mainBuyers[i].getTotalSum()));
        model->setItem(i, 6, item);

    }

}

void MainWindow::on_clearListButton_clicked()
{

    if(this->mainBuyersSizeof == 0)
    {
        messageBox = new QMessageBox(this);
        messageBox->setWindowTitle("Ошибка!");
        messageBox->setText("Данные отсутствуют!");
        messageBox->exec();

        return;
    }

    if(model != nullptr){
        model->clear();
        ui->tableView->setModel(0);
        this->row = 0;
        this->mainBuyersSizeof = 0;
        setTable();
    }

    if(this->mainBuyersSizeof != 0)
    {
        delete[] this->mainBuyers;
    }

}

//закупника, який купив більше всіх підручників з вказаної дисципліни
void MainWindow::on_queryPushButton_clicked()
{

    if(this->mainBuyersSizeof == 0 || this->mainBuyers == nullptr)
    {
        messageBox = new QMessageBox(this);
        messageBox->setWindowTitle("Ошибка!");
        messageBox->setText("Данные отсутствуют!");
        messageBox->exec();

        return;
    }

    //readDataTable
    model->clear();
    setTable();

    std::string choiceType = ui->comboBox->currentText().toStdString();
    int type = 0;
    if(choiceType == "Физика") type = 0;
    if(choiceType == "Математика") type = 1;
    if(choiceType == "Информатика") type = 2;

    Buyer maxBuyer = this->mainBuyers[0];

    for(int i = 0; i < mainBuyersSizeof; ++i)
    {

        if(this->mainBuyers[i].getTotalEachCount()[type] > maxBuyer.getTotalEachCount()[type])
        {
            maxBuyer = this->mainBuyers[i];
        }

    }

    if(maxBuyer.getTotalEachCount()[type] == 0)
    {
        messageBox = new QMessageBox(this);
        messageBox->setWindowTitle("Ошибка!");
        messageBox->setText("Не было найдено покупателей, которые купили бы минимум 1 книгу указанного типа!");
        messageBox->exec();

        model->clear();
        setTable();

        return;
    }

    item = new QStandardItem(QString::fromStdString(maxBuyer.getInitials().lastName));
    model->setItem(0, 0, item);

    item = new QStandardItem(QString::fromStdString(maxBuyer.getInitials().middleName));
    model->setItem(0, 1, item);

    item = new QStandardItem(QString::fromStdString(maxBuyer.getInitials().firstName));
    model->setItem(0, 2, item);

    item = new QStandardItem(QString::number(maxBuyer.getTotalEachSum()[0]));
    model->setItem(0, 3, item);

    item = new QStandardItem(QString::number(maxBuyer.getTotalEachSum()[1]));
    model->setItem(0, 4, item);

    item = new QStandardItem(QString::number(maxBuyer.getTotalEachSum()[2]));
    model->setItem(0, 5, item);

    item = new QStandardItem(QString::number(maxBuyer.getTotalSum()));
    model->setItem(0, 6, item);

}

void MainWindow::on_resetTableButton_clicked()
{

    //readDataTable
    model->clear();
    setTable();

    for(int i = 0; i < this->mainBuyersSizeof; ++i)
    {

        item = new QStandardItem(QString::fromStdString(this->mainBuyers[i].getInitials().lastName));
        model->setItem(i, 0, item);

        item = new QStandardItem(QString::fromStdString(this->mainBuyers[i].getInitials().middleName));
        model->setItem(i, 1, item);

        item = new QStandardItem(QString::fromStdString(this->mainBuyers[i].getInitials().firstName));
        model->setItem(i, 2, item);

        item = new QStandardItem(QString::number(this->mainBuyers[i].getTotalEachSum()[0]));
        model->setItem(i, 3, item);

        item = new QStandardItem(QString::number(this->mainBuyers[i].getTotalEachSum()[1]));
        model->setItem(i, 4, item);

        item = new QStandardItem(QString::number(this->mainBuyers[i].getTotalEachSum()[2]));
        model->setItem(i, 5, item);

        item = new QStandardItem(QString::number(this->mainBuyers[i].getTotalSum()));
        model->setItem(i, 6, item);

    }

}

