#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("КущевскийАндрей, ПЗ-19-1 | lab07");

    this->matrix = nullptr;
    this->intValidator = nullptr;

    this->rows = 0;
    this->cols = 0;

    setLineEditValidator();
    setDefaultValues(false);

    this->form = new inputQueryForm();

    connect(this, &MainWindow::sendSignalToInputQueryForm, form, &inputQueryForm::getSignalToInputQueryForm);
    connect(form, &inputQueryForm::sendSignalToMainWindow, this, &MainWindow::getSignalFromInputQueryForm);

}

MainWindow::~MainWindow()
{
    delete ui;

    if(this->matrix != nullptr && this->rows != 0)
        delete this->matrix;

    if(this->intValidator != nullptr)
        delete intValidator;

}

void MainWindow::setDefaultValues(bool deleteStatus)
{

    ui->rowsCountLineEdit->clear();
    ui->indexLineEdit->clear();

    ui->label->setEnabled(true);
    ui->rowsCountLineEdit->setEnabled(true);

    ui->sizeOfMatrixApplyPushButton->setEnabled(false);

    ui->label_3->setText("Номер элемента[][]   -->");
    ui->label_3->setEnabled(false);
    ui->indexLineEdit->setEnabled(false);
    ui->addNewValueToArrPushButton->setEnabled(false);

    this->currentRow = 0;
    this->currentCol = 0;

    this->rows = 0;

    this->ui->matrixTableWidget->clear();
    this->ui->matrixTableWidget->setRowCount(0);
    this->ui->matrixTableWidget->setColumnCount(0);

    this->ui->queryTextBrowser->clear();

    ui->resetPushButton->setEnabled(false);

    ui->queryRequestPushButton->setEnabled(false);

    delete this->matrix;

}

void MainWindow::setLineEditValidator()
{

   ui->rowsCountLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^([1-9][0-9]*|0)"), this));

   intValidator = new QIntValidator(-999999, 999999, this);
   ui->indexLineEdit->setValidator(intValidator);

}

void MainWindow::setTableWidgetByMatrix()
{

    ui->queryRequestPushButton->setEnabled(true);
    ui->resetPushButton->setEnabled(true);

    for(int i = 0; i < this->rows; ++i){

        ui->matrixTableWidget->insertRow(i);

    }

    for(int j = 0; j < this->cols; ++j){

        ui->matrixTableWidget->insertColumn(j);

    }

    for(int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->cols; ++j){

            ui->matrixTableWidget->setItem(i, j , new QTableWidgetItem(QString::number(this->matrix->getMatrix(i, j))));

        }
    }

    ui->matrixTableWidget->resizeRowsToContents();
    ui->matrixTableWidget->resizeColumnsToContents();
    ui->matrixTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void MainWindow::on_rowsCountLineEdit_textChanged(const QString &arg1)
{

    if(!ui->rowsCountLineEdit->text().isEmpty() && (ui->rowsCountLineEdit->text().toInt() >= 1 && ui->rowsCountLineEdit->text().toInt() <= 255))
    {

        ui->sizeOfMatrixApplyPushButton->setEnabled(true);
        this->rows = ui->rowsCountLineEdit->text().toUInt();
        this->cols = this->rows;

    }
    else
    {

        ui->sizeOfMatrixApplyPushButton->setEnabled(false);

    }

}


void MainWindow::on_sizeOfMatrixApplyPushButton_clicked()
{

    ui->label->setEnabled(false);

    ui->rowsCountLineEdit->setEnabled(false);

    ui->label_3->setEnabled(true);
    ui->indexLineEdit->setEnabled(true);
    ui->addNewValueToArrPushButton->setEnabled(false);

    ui->label_3->setText("Номер элемента [1][1] -->");

    ui->sizeOfMatrixApplyPushButton->setEnabled(false);

    this->rows = ui->rowsCountLineEdit->text().toUInt();

    matrix = new Matrix(this->rows, this->cols);

}

void MainWindow::on_indexLineEdit_textChanged(const QString &arg1)
{

    if(!ui->indexLineEdit->text().isEmpty())
    {

       ui->addNewValueToArrPushButton->setEnabled(true);

    }
    else
    {

        ui->addNewValueToArrPushButton->setEnabled(false);

    }

}

void MainWindow::on_addNewValueToArrPushButton_clicked()
{

    if(this->currentRow != this->rows)
    {

        if(this->currentCol != this->cols - 1){

            matrix->setIndex(this->currentRow, this->currentCol, ui->indexLineEdit->text().toInt());
            this->currentCol++;

            this->ui->label_3->setText("Номер элемента [" + QString::number(this->currentRow + 1) + "][" + QString::number(this->currentCol + 1) + "]  -->");

        }
        else
        {
            matrix->setIndex(this->currentRow, this->currentCol, ui->indexLineEdit->text().toInt());
            this->currentRow++;
            this->currentCol = 0;

            this->ui->label_3->setText("Номер элемента [" + QString::number(this->currentRow + 1) + "][" + QString::number(this->currentCol + 1) + "]  -->");

        }

    }

    if(this->currentRow == this->rows)
    {

        this->ui->label_3->setText("Номер элемента [][]  -->");
        this->ui->label_3->setEnabled(false);
        this->ui->indexLineEdit->clear();
        this->ui->indexLineEdit->setEnabled(false);
        ui->addNewValueToArrPushButton->setEnabled(false);

        setTableWidgetByMatrix();

    }

}

void MainWindow::on_resetPushButton_clicked()
{

    setDefaultValues(true);

}


void MainWindow::on_queryRequestPushButton_clicked()
{

    int indexComboBox = ui->comboBox->currentIndex();

    switch(indexComboBox)
    {

    case 0:{
        form->show();
        emit sendSignalToInputQueryForm(this->rows);
        break;
    }

    case 1:{
        ui->queryTextBrowser->setText(QString::fromStdString(matrix->getFirstColumnHaveNull()));
        break;
    }

    case 2:{
        std::vector<std::string> temp = matrix->getMinMaxSumNegUnpairedEachRow();

        if(temp.size() == 1)
        {
            ui->queryTextBrowser->setText(QString::fromStdString(temp[0]));
        }
        else
        {
            ui->queryTextBrowser->setText(QString::fromStdString(temp[0]));
            ui->queryTextBrowser->append(QString::fromStdString(temp[1]));
        }

        break;
    }

    }

}

void MainWindow::getSignalFromInputQueryForm(int selectRow, int selectCol)
{

    this->selectRow = selectRow - 1;
    this->selectCol = selectCol - 1;
    form->hide();
    ui->queryTextBrowser->setText(QString::fromStdString(matrix->getAverageArGeoInSelect(this->selectRow, this->selectCol)[0]));
    ui->queryTextBrowser->append(QString::fromStdString(matrix->getAverageArGeoInSelect(this->selectRow, this->selectCol)[1]));

}
