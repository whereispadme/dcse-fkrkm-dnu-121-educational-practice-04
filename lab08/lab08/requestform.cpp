#include "requestform.h"
#include "ui_requestform.h"

void requestForm::getSignalFromMainForm()
{
    show();
}

requestForm::requestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::requestForm)
{
    ui->setupUi(this);
    setLineEditValidator();
    ui->groupBox_2->setVisible(true);
    ui->groupBox_3->setVisible(false);
    ui->pushButton->setEnabled(false);
    setWindowTitle("Выполнение запроса");

}

requestForm::~requestForm()
{
    delete ui;
}

void requestForm::setLineEditValidator()
{

    QRegularExpression regexForOnlySym("^[а-яА-яа-яА-яІіЇї]{20}");
    regexForOnlySym.setPatternOptions(QRegularExpression::UseUnicodePropertiesOption);
    QValidator *validatorForOnlySym = new QRegularExpressionValidator(regexForOnlySym, this);
    validatorForOnlySym->setLocale(QLocale::AnyLanguage);

    ui->lastNameLineEdit->setValidator(validatorForOnlySym);

}

void requestForm::on_pushButton_clicked()
{

    bool attribute;
    std::string name;

    if(ui->attributeComboBox->currentIndex() == 0)
    {
        attribute = 0;
        name = ui->lastNameLineEdit->text().toStdString();
    }
    else
    {
        attribute = 1;
        name = ui->zodiacSignComboBox->currentText().toStdString();
    }

    ui->attributeComboBox->setCurrentIndex(0);
    ui->groupBox_2->setVisible(true);
    ui->groupBox_3->setVisible(false);

    ui->lastNameLineEdit->clear();
    ui->zodiacSignComboBox->setCurrentIndex(0);

    emit signalToMainForm(attribute, name);

}


void requestForm::on_lastNameLineEdit_textChanged(const QString &arg1)
{

    if(ui->lastNameLineEdit->text().isEmpty())
    {
        ui->pushButton->setEnabled(false);
    }
    else
    {
        ui->pushButton->setEnabled(true);
    }

}


void requestForm::on_attributeComboBox_currentIndexChanged(int index)
{

    if(ui->attributeComboBox->currentIndex() == 0)
    {

        ui->groupBox_2->setVisible(true);
        ui->groupBox_3->setVisible(false);

    }
    else
    {
        ui->groupBox_2->setVisible(false);
        ui->groupBox_3->setVisible(true);
        ui->pushButton->setEnabled(true);
    }

}

