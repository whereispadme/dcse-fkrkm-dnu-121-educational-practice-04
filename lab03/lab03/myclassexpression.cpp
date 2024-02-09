#include "myclassexpression.h"

#include <cmath>

MyClassExpression::MyClassExpression()
{
    this->x_p = 0.;
    this->x_k = 0.;
    this->x_p_k = 0.;
    this->step = 0.;
    this->iter = 0;
    this->nom = 0;
    this->n = 0;
}

MyClassExpression::MyClassExpression(float x_p, float x_k, float x_p_k, float step, int iter, int nom, int n)
{
    this->x_p = x_p;
    this->x_k = x_k;
    this->x_p_k = x_p_k;
    this->step = step;
    this->iter = iter;
    this->nom = nom;
    this->n = n;
}

MyClassExpression::~MyClassExpression()
{
}

float MyClassExpression::calculate(QProgressBar *&progressBar)
{

    float valueForPBarr = 100 / this->iter;
    float temp = 0;
    progressBar->setValue(0);

    float dob = 0.;
    float sum = 0.;

    for(this->n=0; this->n < this->iter; this->n++)
    {
        dob = (pow(-1., this->n) * pow(this->x_p, 2. * this->n + 1.)) / (2. * this->n + 1.);
        sum = sum + dob;
        temp += valueForPBarr;
        progressBar->setValue(temp);
    }

    float res = 100 - temp;
    progressBar->setValue(temp+res);

    return sum;

}
