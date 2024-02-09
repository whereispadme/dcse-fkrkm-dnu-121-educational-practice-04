#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("КущевскийАндрей, ПЗ-19-1 | lab04");

    intArray = nullptr;
    doubleArray = nullptr;

    setDefaultValues(false);

}

MainWindow::~MainWindow()
{
    delete ui;

    if(this->intArray != nullptr)
    {
        delete this->intArray;
    }

    if(this->doubleArray != nullptr)
    {
        delete this->doubleArray;
    }

}

void MainWindow::setDefaultValues(bool deleteStatus)
{

    ui->label_2->setText("Номер элемента [] -->");
    this->currentIndex = 0;

    ui->intRadioButton->setChecked(false);
    ui->doubleRadioButton->setChecked(false);

    ui->sizeOfArrayLineEdit->clear();
    ui->indexLineEdit->clear();

    ui->label->setEnabled(false);
    ui->sizeOfArrayLineEdit->setEnabled(false);
    ui->sizeOfArrayPushButton->setEnabled(false);

    ui->label_2->setEnabled(false);
    ui->indexLineEdit->setEnabled(false);
    ui->addNewValueToArrPushButton->setEnabled(false);

    ui->mainArrayListWidget->clear();
    ui->mainArrayListWidget_2->clear();

    if(deleteStatus)
    {

        if(this->intArray != nullptr)
            delete this->intArray;

        if(this->doubleArray != nullptr)
            delete this->doubleArray;

        intVector.clear();
        doubleVector.clear();

    }

}

void MainWindow::setLineEditValidator(bool choice)
{

    QValidator *doubleValidator = new QDoubleValidator(-999999., 999999., 3);
    QValidator *intValidator = new QIntValidator(-999999, 999999, this);

    if(choice == false)
    {
        //инт
        ui->sizeOfArrayLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^([1-9][0-9]*|0)"), this));
        ui->indexLineEdit->setValidator(intValidator);

    }else
    {
        //double
        ui->sizeOfArrayLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^([1-9][0-9]*|0)"), this));
        ui->indexLineEdit->setValidator(doubleValidator);

    }

}

void MainWindow::setListWidget(bool typeOfArray)
{

    switch(typeOfArray)
    {

    case 0:{

        intArray = new MyArray<int>(this->intVector.size());
        intArray->setData(intVector);

        for(unsigned int i = 0; i < this->intArray->getSize(); ++i)
        {

            ui->mainArrayListWidget->insertItem(i, QString::number(this->intArray->getDataIndex(i)));
        }

        break;
    }

    case 1:{

        doubleArray = new MyArray<double>(this->doubleVector.size());
        doubleArray->setData(doubleVector);

        for(unsigned int i = 0; i < this->doubleArray->getSize(); ++i)
        {

            ui->mainArrayListWidget->insertItem(i, QString::number(this->doubleArray->getDataIndex(i)));
        }

        break;
    }

    }

}

void MainWindow::setListWidget_2(bool typeOfArray)
{

    switch(typeOfArray)
    {

    case 0:{

        for(unsigned int i = 0; i < this->intArray->getSize(); ++i)
        {

            ui->mainArrayListWidget_2->insertItem(i, QString::number(this->intArray->getDataIndex(i)));
        }

        break;
    }

    case 1:{

        for(unsigned int i = 0; i < this->doubleArray->getSize(); ++i)
        {

            ui->mainArrayListWidget_2->insertItem(i, QString::number(this->doubleArray->getDataIndex(i)));
        }

        break;
    }

    }

}

void MainWindow::setResultsData()
{

    if(this->status == "int")
    {
        setListWidget(false);
    }

    if(this->status == "double")
    {
        setListWidget(true);
    }

}

void MainWindow::on_intRadioButton_clicked()
{

    setDefaultValues(false);

    if(ui->intRadioButton->isChecked())
    {
        setLineEditValidator(false);
        ui->label->setEnabled(true);
        ui->sizeOfArrayLineEdit->setEnabled(true);
    }

    this->status = "int";

}

void MainWindow::on_doubleRadioButton_clicked()
{

    setDefaultValues(false);

    if(ui->doubleRadioButton->isChecked())
    {
        setLineEditValidator(true);
        ui->label->setEnabled(true);
        ui->sizeOfArrayLineEdit->setEnabled(true);
    }

    this->status = "double";

}

void MainWindow::on_sizeOfArrayLineEdit_textChanged(const QString &arg1)
{

    if(ui->sizeOfArrayLineEdit->text().isEmpty() || ui->sizeOfArrayLineEdit->text().toInt() == 0 || ui->sizeOfArrayLineEdit->text().toInt() > 255)
    {
        ui->sizeOfArrayPushButton->setEnabled(false);
    }
    else
    {
        ui->sizeOfArrayPushButton->setEnabled(true);
    }

}


void MainWindow::on_sizeOfArrayPushButton_clicked()
{

    ui->label->setEnabled(false);
    ui->sizeOfArrayLineEdit->setEnabled(false);
    ui->sizeOfArrayPushButton->setEnabled(false);

    ui->label_2->setEnabled(true);
    ui->indexLineEdit->setEnabled(true);
    ui->addNewValueToArrPushButton->setEnabled(false);

    ui->label_2->setText("Номер элемента [0] -->");

}

void MainWindow::on_addNewValueToArrPushButton_clicked()
{

    if(this->status == "int")
    {

        intVector.push_back(ui->indexLineEdit->text().toInt());

    }

    if(this->status == "double")
    {

        doubleVector.push_back(ui->indexLineEdit->text().toDouble());

    }

    this->currentIndex++;
    ui->label_2->setText("Номер элемента [" + QString::number(currentIndex) + "] -->");

    if(this->currentIndex == ui->sizeOfArrayLineEdit->text().toUInt())
    {
        setDefaultValues(false);
        setResultsData();
    }

}

void MainWindow::on_indexLineEdit_textChanged(const QString &arg1)
{

    if(this->status == "int")
    {

        if(ui->indexLineEdit->text().isEmpty())
        {
            ui->addNewValueToArrPushButton->setEnabled(false);
        }
        else{
            ui->addNewValueToArrPushButton->setEnabled(true);
        }

     }

     if(this->status == "double")
     {

        if(ui->indexLineEdit->text().isEmpty())
        {
            ui->addNewValueToArrPushButton->setEnabled(false);
        }
        else{
            ui->addNewValueToArrPushButton->setEnabled(true);
        }

     }

}

void MainWindow::on_queryRequestPushButton_clicked()
{

    int choice = ui->comboBox->currentIndex();

    switch(choice)
    {

    case 0:{

        if(this->status == "int")
        {
            intArray->setNotMoreAverageThenOthers();
            ui->mainArrayListWidget_2->clear();
            setListWidget_2(false);
        }
        else
        {
            doubleArray->setNotMoreAverageThenOthers();
            ui->mainArrayListWidget_2->clear();
            setListWidget_2(true);
        }

        break;
    }

    case 1:{

        if(this->status == "int")
        {
            int value = intArray->calculateMaxAbsoluteElement();
            ui->mainArrayListWidget_2->clear();
            ui->mainArrayListWidget_2->insertItem(0, "Максимальний по модулю елемент масиву: " + QString::number(value));
        }
        else
        {
            double value = doubleArray->calculateMaxAbsoluteElement();
            ui->mainArrayListWidget_2->clear();
            ui->mainArrayListWidget_2->insertItem(0, "Максимальний по модулю елемент масиву: " + QString::number(value));
        }

        break;
    }

    case 2:{

        if(this->status == "int")
        {
            std::string str = intArray->sumElementsBetweenFirstLastPos();
            ui->mainArrayListWidget_2->clear();
            ui->mainArrayListWidget_2->insertItem(0, QString::fromStdString(str));
        }
        else
        {
            std::string str = doubleArray->sumElementsBetweenFirstLastPos();
            ui->mainArrayListWidget_2->clear();
            ui->mainArrayListWidget_2->insertItem(0, QString::fromStdString(str));
        }

        break;
    }

    case 3:{

        if(this->status == "int")
        {
            intArray->convertNullElementsInEnd();
            ui->mainArrayListWidget_2->clear();
            setListWidget_2(false);
        }
        else
        {
            doubleArray->convertNullElementsInEnd();
            ui->mainArrayListWidget_2->clear();
            setListWidget_2(true);
        }

        break;
    }

    }

}


void MainWindow::on_resetPushButton_clicked()
{
    setDefaultValues(true);
}
