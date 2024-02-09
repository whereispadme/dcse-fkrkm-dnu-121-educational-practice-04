#include "inputdatatodb.h"
#include "ui_inputdatatodb.h"

void inputDataToDb::getSignalFromMainForm()
{
    show();
}

inputDataToDb::inputDataToDb(QWidget *parent) : QWidget(parent), ui(new Ui::inputDataToDb)
{
    ui->setupUi(this);
    this->person = new Person();
    setWindowTitle("Личные данные");
    ui->lastNameLineEdit->setFocus();
    ui->addDataPushButton->setEnabled(false);
    setLineEditValidator();
}

inputDataToDb::~inputDataToDb()
{
    delete ui;
    if(this->person != nullptr)
    {
        delete this->person;
    }

}

void inputDataToDb::on_addDataPushButton_clicked()
{

    this->person->setDataObject(ui->lastNameLineEdit->text().toStdString(), ui->firstNameLineEdit->text().toStdString(),
                                ui->dateOfBirthdayEdit->text().toStdString(), ui->sexComboBox->currentText().toStdString());

    ui->lastNameLineEdit->clear();
    ui->firstNameLineEdit->clear();
    ui->dateOfBirthdayEdit->clear();
    ui->sexComboBox->currentIndexChanged(0);

    emit signalToMainForm(this->person);

}

void inputDataToDb::checkLineEdit()
{

    if(ui->lastNameLineEdit->text().isEmpty() || ui->firstNameLineEdit->text().isEmpty())
    {
        ui->addDataPushButton->setEnabled(false);
    }
    else
    {
        ui->addDataPushButton->setEnabled(true);
    }

}

void inputDataToDb::setLineEditValidator()
{
    QRegularExpression regexForOnlySym("^[а-яА-яа-яА-яІіЇї]{20}");
    regexForOnlySym.setPatternOptions(QRegularExpression::UseUnicodePropertiesOption);
    QValidator *validatorForOnlySym = new QRegularExpressionValidator(regexForOnlySym, this);
    validatorForOnlySym->setLocale(QLocale::AnyLanguage);

    ui->lastNameLineEdit->setValidator(validatorForOnlySym);
    ui->firstNameLineEdit->setValidator(validatorForOnlySym);
}

void inputDataToDb::on_lastNameLineEdit_textChanged(const QString &arg1)
{

    checkLineEdit();

}


void inputDataToDb::on_firstNameLineEdit_textChanged(const QString &arg1)
{

    checkLineEdit();

}
