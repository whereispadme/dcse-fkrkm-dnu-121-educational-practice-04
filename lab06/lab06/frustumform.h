#ifndef FRUSTUMFORM_H
#define FRUSTUMFORM_H

#include <QWidget>
#include <QDoubleValidator>

namespace Ui {
class frustumForm;
}

class frustumForm : public QWidget
{
    Q_OBJECT

signals:
    void signalToMainWindow(float radiusDown, float radiusHigh, float height, float lBased);

public slots:
    void getSignal();

public:
    explicit frustumForm(QWidget *parent = nullptr);
    ~frustumForm();

    void setLineEditValidator();
    void checkLineEdit();

private slots:
    void on_radiusDownLineEdit_textChanged(const QString &arg1);

    void on_radiusHighLineEdit_textChanged(const QString &arg1);

    void on_heightLineEdit_textChanged(const QString &arg1);

    void on_lBasedLineEdit_textChanged(const QString &arg1);

    void on_applyPushButton_clicked();

private:
    Ui::frustumForm *ui;
};

#endif // FRUSTUMFORM_H
