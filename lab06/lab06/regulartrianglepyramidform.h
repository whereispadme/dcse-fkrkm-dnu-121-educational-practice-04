#ifndef REGULARTRIANGLEPYRAMIDFORM_H
#define REGULARTRIANGLEPYRAMIDFORM_H

#include <QWidget>
#include <QRegularExpressionValidator>

namespace Ui {
class regularTrianglePyramidForm;
}

class regularTrianglePyramidForm : public QWidget
{
    Q_OBJECT

signals:
    void signalToMainWindow(float length, float height, float side);

public slots:
    void getSignal();

public:
    explicit regularTrianglePyramidForm(QWidget *parent = nullptr);
    ~regularTrianglePyramidForm();

    void setLineEditValidator();
    void checkLineEdit();

private slots:
    void on_applyPushButton_clicked();

    void on_heightLineEdit_textChanged(const QString &arg1);

    void on_lengthLineEdit_textChanged(const QString &arg1);

    void on_sideLineEdit_textChanged(const QString &arg1);

private:
    Ui::regularTrianglePyramidForm *ui;
};

#endif // REGULARTRIANGLEPYRAMIDFORM_H
