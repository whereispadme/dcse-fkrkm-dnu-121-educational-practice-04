#ifndef REQUESTFORM_H
#define REQUESTFORM_H

#include <QWidget>

namespace Ui {
class requestForm;
}

class requestForm : public QWidget
{
    Q_OBJECT

signals:
    void signalToMainForm(bool attribute, std::string name);

public slots:
    void getSignalFromMainForm();

public:
    explicit requestForm(QWidget *parent = nullptr);
    ~requestForm();

    void setLineEditValidator();

private slots:
    void on_pushButton_clicked();

    void on_lastNameLineEdit_textChanged(const QString &arg1);

    void on_attributeComboBox_currentIndexChanged(int index);

private:
    Ui::requestForm *ui;
};

#endif // REQUESTFORM_H
