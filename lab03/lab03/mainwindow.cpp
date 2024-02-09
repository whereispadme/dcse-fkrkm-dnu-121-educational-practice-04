#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("КущевскийАндрей, ПЗ-19-1");

    setDefaultValues();
    setLineEditValidator();
    mainObject = nullptr;

}

MainWindow::~MainWindow()
{

    delete ui;

    if(this->mainObject != nullptr)
    {
        delete this->mainObject;
    }

}

void MainWindow::checkLineEdit()
{

    if(ui->xpLineEdit->text().isEmpty() || ui->xkLineEdit->text().isEmpty() || ui->iterLineEdit->text().isEmpty() || ui->pointLineEdit->text().isEmpty())
    {
        ui->calculatePushButton->setEnabled(false);
    }
    else
    {
        ui->calculatePushButton->setEnabled(true);
    }

}

void MainWindow::setLineEditValidator()
{
    QValidator *doubleValidator = new QDoubleValidator(0, 999999., 3);
    ui->xpLineEdit->setValidator(doubleValidator);
    ui->xkLineEdit->setValidator(doubleValidator);
    ui->iterLineEdit->setValidator(doubleValidator);
    ui->pointLineEdit->setValidator(doubleValidator);
}

void MainWindow::setDefaultValues()
{

    ui->listWidget->clear();
    ui->clearPushButton->setEnabled(false);

    ui->progressBar->setValue(0);

    ui->xpLineEdit->clear();
    ui->xkLineEdit->clear();
    ui->iterLineEdit->clear();
    ui->pointLineEdit->clear();

    ui->calculatePushButton->setEnabled(false);

}

void MainWindow::on_xpLineEdit_textChanged(const QString &arg1)
{
    checkLineEdit();
}


void MainWindow::on_xkLineEdit_textChanged(const QString &arg1)
{
    checkLineEdit();
}


void MainWindow::on_iterLineEdit_textChanged(const QString &arg1)
{
    checkLineEdit();
}


void MainWindow::on_pointLineEdit_textChanged(const QString &arg1)
{
    checkLineEdit();
}


void MainWindow::on_calculatePushButton_clicked()
{

    ui->clearPushButton->setEnabled(true);
    mainObject = new MyClassExpression(ui->xpLineEdit->text().toFloat(), ui->xkLineEdit->text().toFloat(), 0.,
                                       ui->pointLineEdit->text().toFloat(), this->ui->iterLineEdit->text().toFloat(), 0., 0.);

    ui->listWidget->insertItem(ui->listWidget->count(), QString::number(this->mainObject->calculate(ui->progressBar)));

    //ui->progressBar->setValue();

    ui->xpLineEdit->clear();
    ui->xkLineEdit->clear();
    ui->iterLineEdit->clear();
    ui->pointLineEdit->clear();

    ui->calculatePushButton->setEnabled(false);

}


void MainWindow::on_clearPushButton_clicked()
{

    ui->clearPushButton->setEnabled(false);
    setDefaultValues();

}

