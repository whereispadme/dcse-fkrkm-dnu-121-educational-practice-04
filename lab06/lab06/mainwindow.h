#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "C:\Users\Professional\Desktop\main\main\Figure.h"

#include "C:\Users\Professional\Desktop\main\main\Polyhedron.h"
#include "C:\Users\Professional\Desktop\main\main\Round.h"

#include "C:\Users\Professional\Desktop\main\main\RegularTrianglePyramid.h"

#include "C:\Users\Professional\Desktop\main\main\Frustum.h"
#include "C:\Users\Professional\Desktop\main\main\Ball.h"

#include <QMainWindow>
#include <QStandardItemModel>

#include <vector>

#include "regulartrianglepyramidform.h"
#include "frustumform.h"
#include "ballform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void signalToPyramidForm();
    void signalToFrustumForm();
    void signalToBallForm();

public slots:
    void getSignalFromPyramidForm(float length, float height, float side);
    void getSignalFromFrustumForm(float radiusDown, float radiusHigh, float height, float lBased);
    void getSignalFromBallForm(float radius);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTable();

private slots:
    void on_polyhedronRadioButton_clicked();

    void on_roundRadioButton_clicked();

    void on_applyTypeFigurePushButton_clicked();

    void on_resetPushButon_clicked();

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model;

    regularTrianglePyramidForm *pForm;
    frustumForm *fForm;
    ballForm *bForm;

    RegularTrianglePyramid *rTrianglePyramid;
    std::vector<RegularTrianglePyramid> pyramidVector;

    Frustum *frustum;
    std::vector<Frustum> frustumVector;

    Ball *ball;
    std::vector<Ball> ballVector;

    int currentRow;

};
#endif // MAINWINDOW_H
