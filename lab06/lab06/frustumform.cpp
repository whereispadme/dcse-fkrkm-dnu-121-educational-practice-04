#include "frustumform.h"
#include "ui_frustumform.h"

void frustumForm::getSignal()
{
    show();
}

frustumForm::frustumForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frustumForm)
{
    ui->setupUi(this);
    setWindowTitle("Урезанный конус");
    setLineEditValidator();
    ui->applyPushButton->setEnabled(false);
}

frustumForm::~frustumForm()
{
    delete ui;
}

void frustumForm::setLineEditValidator()
{
    QValidator *doubleValidator = new QDoubleValidator(0, 999999., 3);
    ui->radiusDownLineEdit->setValidator(doubleValidator);
    ui->radiusHighLineEdit->setValidator(doubleValidator);
    ui->heightLineEdit->setValidator(doubleValidator);
    ui->lBasedLineEdit->setValidator(doubleValidator);
}

void frustumForm::checkLineEdit()
{

    if(ui->radiusDownLineEdit->text().isEmpty() || ui->radiusHighLineEdit->text().isEmpty() || ui->heightLineEdit->text().isEmpty() || ui->lBasedLineEdit->text().isEmpty()
       || ui->radiusDownLineEdit->text().toFloat() == 0. || ui->radiusHighLineEdit->text().toFloat() == 0. || ui->heightLineEdit->text().toFloat() == 0. || ui->lBasedLineEdit->text().toFloat() == 0.)
    {
        ui->applyPushButton->setEnabled(false);
    }
    else
    {
        ui->applyPushButton->setEnabled(true);
    }

}

void frustumForm::on_radiusDownLineEdit_textChanged(const QString &arg1)
{
    checkLineEdit();
}

void frustumForm::on_radiusHighLineEdit_textChanged(const QString &arg1)
{
    checkLineEdit();
}

void frustumForm::on_heightLineEdit_textChanged(const QString &arg1)
{
    checkLineEdit();
}

void frustumForm::on_lBasedLineEdit_textChanged(const QString &arg1)
{
    checkLineEdit();
}

void frustumForm::on_applyPushButton_clicked()
{
    hide();
    emit signalToMainWindow(ui->radiusDownLineEdit->text().toFloat(), ui->radiusHighLineEdit->text().toFloat(), ui->heightLineEdit->text().toFloat(), ui->lBasedLineEdit->text().toFloat());
    ui->radiusDownLineEdit->clear();
    ui->radiusHighLineEdit->clear();
    ui->heightLineEdit->clear();
    ui->lBasedLineEdit->clear();
}

