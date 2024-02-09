#include "ballform.h"
#include "ui_ballform.h"

void ballForm::getSignal()
{
    show();
}

ballForm::ballForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ballForm)
{
    ui->setupUi(this);
    setWindowTitle("Шар");
}

ballForm::~ballForm()
{
    delete ui;
}

void ballForm::setLineEditValidator()
{
    QValidator *doubleValidator = new QDoubleValidator(0, 999999., 3);
    ui->radiusLineEdit->setValidator(doubleValidator);
}

void ballForm::checkLineEdit()
{

    if(ui->radiusLineEdit->text().isEmpty() || ui->radiusLineEdit->text().toFloat() == 0.)
    {
        ui->applyPushButton->setEnabled(false);
    }
    else
    {
        ui->applyPushButton->setEnabled(true);
    }

}

void ballForm::on_radiusLineEdit_textChanged(const QString &arg1)
{
    checkLineEdit();
}


void ballForm::on_applyPushButton_clicked()
{
    hide();
    emit signalToMainWindow(ui->radiusLineEdit->text().toFloat());
    ui->radiusLineEdit->clear();
}

