#ifndef MYCLASSEXPRESSION_H
#define MYCLASSEXPRESSION_H

#include <QProgressBar>

class MyClassExpression
{

private:
    float x_p;
    float x_k;
    float x_p_k;
    float step;
    int iter;
    int nom;
    int n;

public :
    MyClassExpression();
    MyClassExpression(float, float, float, float, int, int, int);
    ~MyClassExpression();

    float calculate(QProgressBar *&progressBar);

};

#endif // MYCLASSEXPRESSION_H
