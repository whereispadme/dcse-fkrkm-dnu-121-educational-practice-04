#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("КущевскийАндрей, ПЗ-19-1 | lab04");

    this->model = nullptr;
    this->item = nullptr;

    setEditValidator();
    setDefaultValues();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete item;
}

void MainWindow::setEditValidator()
{

    auto doubleValidator = new QDoubleValidator(0.0, 5.0, 2);

    ui->aLineEdit->setValidator(doubleValidator);

    ui->aLineEdit->setValidator(doubleValidator);
    ui->bLineEdit->setValidator(doubleValidator);
    ui->cLineEdit->setValidator(doubleValidator);

    ui->xStartLineEdit->setValidator(doubleValidator);
    ui->xEndLineEdit->setValidator(doubleValidator);
    ui->dXLineEdit->setValidator(doubleValidator);

    ui->xLineEdit->setValidator(doubleValidator);

}

void MainWindow::setDefaultValues()
{

    ui->aLineEdit->setReadOnly(true);
    ui->bLineEdit->setReadOnly(true);
    ui->cLineEdit->setReadOnly(true);

    ui->xStartLineEdit->setReadOnly(true);
    ui->xEndLineEdit->setReadOnly(true);
    ui->dXLineEdit->setReadOnly(true);

    ui->xLineEdit->setReadOnly(true);

    ui->aLineEdit->clear();
    ui->bLineEdit->clear();
    ui->cLineEdit->clear();

    ui->xStartLineEdit->clear();
    ui->xEndLineEdit->clear();
    ui->dXLineEdit->clear();

    ui->xLineEdit->clear();

    ui->pointRadioButton->setChecked(false);
    ui->intervalRadioButton->setChecked(false);

    ui->listWidget->clear();
    ui->listWidget_2->clear();

}

bool MainWindow::checkEditValid()
{

    if((!ui->pointRadioButton->isChecked() && (!ui->intervalRadioButton->isChecked())))
    {
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setWindowTitle("Ошибка!");
        messageBox->setText("Выберите вариант решения!");
        messageBox->exec();
        delete messageBox;
        return false;
    }

    if(ui->pointRadioButton->isChecked() && (ui->aLineEdit->text().isEmpty() || ui->bLineEdit->text().isEmpty() || ui->cLineEdit->text().isEmpty() || ui->xLineEdit->text().isEmpty()))
    {
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setWindowTitle("Ошибка!");
        messageBox->setText("Все поля должны быть заполнены!");
        messageBox->exec();
        delete messageBox;
        return false;
    }

    if(ui->intervalRadioButton->isChecked() && (ui->aLineEdit->text().isEmpty() || ui->bLineEdit->text().isEmpty() || ui->cLineEdit->text().isEmpty()
                                                || ui->xStartLineEdit->text().isEmpty() || ui->xEndLineEdit->text().isEmpty() || ui->dXLineEdit->text().isEmpty()))
    {
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setWindowTitle("Ошибка!");
        messageBox->setText("Все поля должны быть заполнены!");
        messageBox->exec();
        delete messageBox;
        return false;
    }

    if((ui->intervalRadioButton->isChecked()) && ui->xStartLineEdit->text().toDouble() >= ui->xEndLineEdit->text().toDouble())
    {
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setWindowTitle("Ошибка!");
        messageBox->setText("X начальное не может быть меньше или равно x конечному!");
        messageBox->exec();
        delete messageBox;
        return false;
    }

    return true;

}

void MainWindow::on_pointRadioButton_clicked()
{

    ui->aLineEdit->setReadOnly(false);
    ui->bLineEdit->setReadOnly(false);
    ui->cLineEdit->setReadOnly(false);

    ui->xStartLineEdit->setReadOnly(true);
    ui->xEndLineEdit->setReadOnly(true);
    ui->dXLineEdit->setReadOnly(true);

    ui->xLineEdit->setReadOnly(false);

}

void MainWindow::on_intervalRadioButton_clicked()
{

    ui->aLineEdit->setReadOnly(false);
    ui->bLineEdit->setReadOnly(false);
    ui->cLineEdit->setReadOnly(false);

    ui->xStartLineEdit->setReadOnly(false);
    ui->xEndLineEdit->setReadOnly(false);
    ui->dXLineEdit->setReadOnly(false);

    ui->xLineEdit->setReadOnly(true);

}

void MainWindow::on_resetPushButton_clicked()
{

    setDefaultValues();

    vectorPointObject.clear();
    vectorIntervalObject.clear();

}

void MainWindow::on_calculatePushButton_clicked()
{

    if(checkEditValid() == false)
    {
        return;
    }

    int choice = -1;

    if(ui->pointRadioButton->isChecked())
        choice = 0;

    if(ui->intervalRadioButton->isChecked())
        choice = 1;

    double result = 0;

    switch(choice)
    {

    case 0:
    {

        point *pointFunction = new point(ui->aLineEdit->text().toDouble(), ui->bLineEdit->text().toDouble(), ui->cLineEdit->text().toDouble(), ui->xLineEdit->text().toDouble());
        result = pointFunction->calculate();

        ui->listWidget->insertItem(ui->listWidget->currentRow(), QString::number(result));
        vectorPointObject.push_back(*pointFunction);

        delete pointFunction;

        break;

    }

    case 1:
    {

        interval *intervalFunction = new interval(ui->aLineEdit->text().toDouble(), ui->bLineEdit->text().toDouble(), ui->cLineEdit->text().toDouble(),
                                                  ui->xStartLineEdit->text().toDouble(), ui->xEndLineEdit->text().toDouble(), ui->dXLineEdit->text().toDouble());
        result = intervalFunction->calculate();

        ui->listWidget_2->insertItem(ui->listWidget_2->currentRow(), QString::number(result));
        vectorIntervalObject.push_back(*intervalFunction);

        delete intervalFunction;

        break;

    }

    }

}

void MainWindow::on_saveInFilePushButton_clicked()
{

    std::ofstream out;
    out.open("D:\\resultOfProgramm.txt", std::ios::out);

    if(!out.is_open())
    {
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setWindowTitle("Ошибка!");
        messageBox->setText("Не удалось открыть файл!");
        messageBox->exec();
        delete messageBox;
        return;
    }

    for(int i = 0; i < vectorPointObject.size(); ++i)
    {

        out << "[" << i + 1 << "]:" << std::endl;
        out << "ObjectType: point" << std::endl;
        out << "Result:" << vectorPointObject[i].calculate() << std::endl << std::endl;

    }


    for(int i = 0; i < vectorIntervalObject.size(); ++i)
    {

        out << "[" << i + 1 << "]:" << std::endl;
        out << "ObjectType: interval" << std::endl;
        out << "Result:" << vectorIntervalObject[i].calculate() << std::endl << std::endl;

    }

    out.close();

}

