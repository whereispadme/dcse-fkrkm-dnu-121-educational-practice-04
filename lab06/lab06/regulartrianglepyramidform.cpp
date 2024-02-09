#include "regulartrianglepyramidform.h"
#include "ui_regulartrianglepyramidform.h"

void regularTrianglePyramidForm::getSignal()
{
    show();
}

regularTrianglePyramidForm::regularTrianglePyramidForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regularTrianglePyramidForm)
{
    ui->setupUi(this);

    setWindowTitle("Правильная треугольная пирамида");
    setLineEditValidator();
    ui->applyPushButton->setEnabled(false);
}

regularTrianglePyramidForm::~regularTrianglePyramidForm()
{
    delete ui;
}

void regularTrianglePyramidForm::setLineEditValidator()
{
    QValidator *doubleValidator = new QDoubleValidator(0, 999999., 3);
    ui->lengthLineEdit->setValidator(doubleValidator);
    ui->heightLineEdit->setValidator(doubleValidator);
    ui->sideLineEdit->setValidator(doubleValidator);
}

void regularTrianglePyramidForm::on_applyPushButton_clicked()
{

    hide();
    emit signalToMainWindow(ui->lengthLineEdit->text().toFloat(), ui->heightLineEdit->text().toFloat(), ui->sideLineEdit->text().toFloat());
    ui->lengthLineEdit->clear();
    ui->heightLineEdit->clear();
    ui->sideLineEdit->clear();

}

void regularTrianglePyramidForm::checkLineEdit()
{
    if(ui->lengthLineEdit->text().isEmpty() || ui->heightLineEdit->text().isEmpty() || ui->sideLineEdit->text().isEmpty()
       || ui->lengthLineEdit->text().toFloat() == 0. || ui->heightLineEdit->text().toFloat() == 0. || ui->sideLineEdit->text().toFloat() == 0.)
    {
        ui->applyPushButton->setEnabled(false);
    }
    else
    {
        ui->applyPushButton->setEnabled(true);
    }
}

void regularTrianglePyramidForm::on_heightLineEdit_textChanged(const QString &arg1)
{

    checkLineEdit();

}

void regularTrianglePyramidForm::on_lengthLineEdit_textChanged(const QString &arg1)
{

    checkLineEdit();

}

void regularTrianglePyramidForm::on_sideLineEdit_textChanged(const QString &arg1)
{

    checkLineEdit();

}
