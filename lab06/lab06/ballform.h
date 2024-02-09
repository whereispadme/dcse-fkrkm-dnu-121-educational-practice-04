#ifndef BALLFORM_H
#define BALLFORM_H

#include <QWidget>
#include <QDoubleValidator>

namespace Ui {
class ballForm;
}

class ballForm : public QWidget
{
    Q_OBJECT

signals:
    void signalToMainWindow(float radius);

public slots:
    void getSignal();

public:
    explicit ballForm(QWidget *parent = nullptr);
    ~ballForm();

    void setLineEditValidator();
    void checkLineEdit();

private slots:
    void on_radiusLineEdit_textChanged(const QString &arg1);

    void on_applyPushButton_clicked();

private:
    Ui::ballForm *ui;
};

#endif // BALLFORM_H
