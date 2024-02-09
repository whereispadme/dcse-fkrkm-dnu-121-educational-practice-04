#include "inputqueryform.h"
#include "ui_inputqueryform.h"

inputQueryForm::inputQueryForm(QWidget *parent) :  QWidget(parent), ui(new Ui::inputQueryForm)
{
    ui->setupUi(this);
    setWindowTitle("Ввод данных для запроса");
    setLineEditValidator();
    sizeMatrixFromMainWindow = 0;
    ui->setValuesForQueryPushButton->setEnabled(false);
}

inputQueryForm::~inputQueryForm()
{
    delete ui;
}

void inputQueryForm::setLineEditValidator()
{
    ui->rowLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^([1-9][0-9]*|0)"), this));
    ui->colLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^([1-9][0-9]*|0)"), this));
}

void inputQueryForm::getSignalToInputQueryForm(int rows)
{

    sizeMatrixFromMainWindow = rows;

}

void inputQueryForm::on_rowLineEdit_textChanged(const QString &arg1)
{
    if(ui->rowLineEdit->text().isEmpty() || ui->rowLineEdit->text().toInt() > this->sizeMatrixFromMainWindow || ui->rowLineEdit->text().toInt() == 0
       || ui->colLineEdit->text().isEmpty() || ui->colLineEdit->text().toInt() > this->sizeMatrixFromMainWindow || ui->colLineEdit->text().toInt() == 0)
    {
       ui->setValuesForQueryPushButton->setEnabled(false);
    }
    else
    {
      ui->setValuesForQueryPushButton->setEnabled(true);
    }
}


void inputQueryForm::on_colLineEdit_textChanged(const QString &arg1)
{
    if(ui->rowLineEdit->text().isEmpty() || ui->rowLineEdit->text().toInt() > this->sizeMatrixFromMainWindow || ui->rowLineEdit->text().toInt() == 0
       || ui->colLineEdit->text().isEmpty() || ui->colLineEdit->text().toInt() > this->sizeMatrixFromMainWindow || ui->colLineEdit->text().toInt() == 0)
    {
       ui->setValuesForQueryPushButton->setEnabled(false);
    }
    else
    {
      ui->setValuesForQueryPushButton->setEnabled(true);
    }
}


void inputQueryForm::on_setValuesForQueryPushButton_clicked()
{

    emit sendSignalToMainWindow(ui->rowLineEdit->text().toInt(), ui->colLineEdit->text().toInt());

}

