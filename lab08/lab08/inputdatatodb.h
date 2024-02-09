#ifndef INPUTDATATODB_H
#define INPUTDATATODB_H

#include "person.h"

#include <QWidget>
#include <QDebug>

namespace Ui {
class inputDataToDb;
}

class inputDataToDb : public QWidget
{
    Q_OBJECT

signals:
    void signalToMainForm(Person *&person);

public slots:
    void getSignalFromMainForm();

public:
    explicit inputDataToDb(QWidget *parent = nullptr);
    ~inputDataToDb();

    void checkLineEdit();
    void setLineEditValidator();

private slots:
    void on_addDataPushButton_clicked();

    void on_lastNameLineEdit_textChanged(const QString &arg1);

    void on_firstNameLineEdit_textChanged(const QString &arg1);

private:
    Ui::inputDataToDb *ui;
    Person *person;

};

#endif // INPUTDATATODB_H
