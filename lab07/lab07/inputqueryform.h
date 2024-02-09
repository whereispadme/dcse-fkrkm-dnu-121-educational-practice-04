#ifndef INPUTQUERYFORM_H
#define INPUTQUERYFORM_H

#include <QWidget>

#include <QRegularExpressionValidator>

namespace Ui {
class inputQueryForm;
}

class inputQueryForm : public QWidget
{
    Q_OBJECT

public:
    explicit inputQueryForm(QWidget *parent = nullptr);
    ~inputQueryForm();

    void setLineEditValidator();

public slots:
    void getSignalToInputQueryForm(int rows);

signals:
    void sendSignalToMainWindow(int selectRow, int selectCol);

private slots:

    void on_rowLineEdit_textChanged(const QString &arg1);

    void on_colLineEdit_textChanged(const QString &arg1);

    void on_setValuesForQueryPushButton_clicked();

private:
    Ui::inputQueryForm *ui;

    int sizeMatrixFromMainWindow;

};

#endif // INPUTQUERYFORM_H
