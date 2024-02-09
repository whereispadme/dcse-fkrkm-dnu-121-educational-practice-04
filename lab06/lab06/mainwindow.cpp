#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::getSignalFromPyramidForm(float length, float height, float side)
{
    this->rTrianglePyramid = new RegularTrianglePyramid(length, height, side);

    model->setItem(this->currentRow, 0, new QStandardItem("Правильная треугольная пирамида"));
    model->setItem(this->currentRow, 1, new QStandardItem("Многогранник"));
    model->setItem(this->currentRow, 2, new QStandardItem(QString::number(this->rTrianglePyramid->getVolume())));
    model->setItem(this->currentRow, 3, new QStandardItem(QString::number(this->rTrianglePyramid->getSurfaceArea())));
    currentRow++;

    this->pyramidVector.push_back(*this->rTrianglePyramid);

}

void MainWindow::getSignalFromFrustumForm(float radiusDown, float radiusHigh, float height, float lBased)
{
    this->frustum = new Frustum(radiusDown, radiusHigh, height, lBased);

    model->setItem(this->currentRow, 0, new QStandardItem("Усеченный конус"));
    model->setItem(this->currentRow, 1, new QStandardItem("Круглое тело"));
    model->setItem(this->currentRow, 2, new QStandardItem(QString::number(this->frustum->getVolume())));
    model->setItem(this->currentRow, 3, new QStandardItem(QString::number(this->frustum->getSurfaceArea())));
    currentRow++;

    this->frustumVector.push_back(*this->frustum);

}

void MainWindow::getSignalFromBallForm(float radius)
{
    this->ball = new Ball(radius);

    model->setItem(this->currentRow, 0, new QStandardItem("Шар"));
    model->setItem(this->currentRow, 1, new QStandardItem("Круглое тело"));
    model->setItem(this->currentRow, 2, new QStandardItem(QString::number(this->ball->getVolume())));
    model->setItem(this->currentRow, 3, new QStandardItem(QString::number(this->ball->getSurfaceArea())));
    currentRow++;

    this->ballVector.push_back(*this->ball);

}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("КущевскийАндрей, ПЗ-19-1 | lab06");

    ui->applyTypeFigurePushButton->setEnabled(false);
    ui->resetPushButon->setEnabled(false);
    ui->groupBox_2->setEnabled(false);

    this->model = nullptr;
    this->currentRow = 0;

    this->rTrianglePyramid = nullptr;
    this->frustum = nullptr;
    this->ball = nullptr;

    this->pForm = new regularTrianglePyramidForm;
    this->fForm = new frustumForm;
    this->bForm = new ballForm;

    connect(this, &MainWindow::signalToPyramidForm, this->pForm, &regularTrianglePyramidForm::getSignal);
    connect(this->pForm, &regularTrianglePyramidForm::signalToMainWindow, this, &MainWindow::getSignalFromPyramidForm);

    connect(this, &MainWindow::signalToFrustumForm, this->fForm, &frustumForm::getSignal);
    connect(this->fForm, &frustumForm::signalToMainWindow, this, &MainWindow::getSignalFromFrustumForm);

    connect(this, &MainWindow::signalToBallForm, this->bForm, &ballForm::getSignal);
    connect(this->bForm, &ballForm::signalToMainWindow, this, &MainWindow::getSignalFromBallForm);

    setTable();

}

MainWindow::~MainWindow()
{
    delete ui;

    if(this->rTrianglePyramid != nullptr)
        delete rTrianglePyramid;

    if(this->frustum != nullptr)
        delete frustum;

    if(this->ball != nullptr)
        delete ball;

    if(this->model != nullptr)
        delete model;

}

void MainWindow::setTable()
{

    model = new QStandardItemModel;
    ui->tableView->setModel(model);

    //Заголовки столбцов
    QStringList horizontalHeader;
    horizontalHeader.append("Название фигуры");
    horizontalHeader.append("Тип фигуры");
    horizontalHeader.append("Объем фигуры");
    horizontalHeader.append("Площадь основания фигуры");

    model->setHorizontalHeaderLabels(horizontalHeader);
    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView->setColumnWidth(0, 110);
    ui->tableView->setColumnWidth(1, 100);
    ui->tableView->setColumnWidth(2, 110);
    ui->tableView->setColumnWidth(3, 180);

    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Устанавливаем режим выделения лишь одной строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    //Устанавливаем сортировку по атрибутам
    ui->tableView->setSortingEnabled(true);

}

void MainWindow::on_polyhedronRadioButton_clicked()
{

    if(ui->polyhedronRadioButton->isChecked())
    {
        ui->comboBox->clear();
        ui->comboBox->insertItem(0, "Правильная треугольная пирамида");
        ui->applyTypeFigurePushButton->setEnabled(true);
        ui->groupBox_2->setEnabled(true);
    }
    else
    {
        ui->applyTypeFigurePushButton->setEnabled(false);
        ui->groupBox_2->setEnabled(false);
    }

}


void MainWindow::on_roundRadioButton_clicked()
{

    if(ui->roundRadioButton->isChecked())
    {
        ui->comboBox->clear();
        ui->comboBox->insertItem(0, "Усеченный конус");
        ui->comboBox->insertItem(1, "Шар");
        ui->applyTypeFigurePushButton->setEnabled(true);
        ui->groupBox_2->setEnabled(true);
    }
    else
    {
        ui->applyTypeFigurePushButton->setEnabled(false);
        ui->groupBox_2->setEnabled(false);
    }

}

void MainWindow::on_applyTypeFigurePushButton_clicked()
{

    ui->resetPushButon->setEnabled(true);

    if(ui->polyhedronRadioButton->isChecked())
    {

        emit signalToPyramidForm();

    }
    else
    {

       int comboBoxIndex = ui->comboBox->currentIndex();

       switch(comboBoxIndex)
       {

       case 0:{

           emit signalToFrustumForm();

           break;
       }

       case 1:{

           emit signalToBallForm();

           break;
       }

       }

    }


}


void MainWindow::on_resetPushButon_clicked()
{

    ui->applyTypeFigurePushButton->setEnabled(false);
    ui->resetPushButon->setEnabled(false);

    ui->polyhedronRadioButton->setChecked(true);
    ui->comboBox->clear();
    ui->comboBox->insertItem(0, "Правильная треугольная пирамида");
    ui->applyTypeFigurePushButton->setEnabled(true);
    ui->groupBox_2->setEnabled(true);

    ui->roundRadioButton->setChecked(false);

    this->currentRow = 0;

    model->clear();
    setTable();

    this->pyramidVector.clear();
    this->frustumVector.clear();
    this->ballVector.clear();

}
