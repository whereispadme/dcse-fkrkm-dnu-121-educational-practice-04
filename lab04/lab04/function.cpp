#include "function.h"
#include <cmath>

//point.cpp
point::point(double a, double b, double c, double x)
{
    this->a = a;
    this->b = b;
    this->c = c;

    this->x = x;
}

point::~point()
{
}

double point::calculate()
{

    if(a < 0 && x != 0)
        return a * pow(x, 2.0) + pow(b, 2.0) * x;

    if(a > 0 && x == 0)
        return x - (a / x - c);

    return 1 + (x/c);

}

//interval.cpp
interval::interval(double a, double b, double c, double min, double max, double step)
{
    this->a = a;
    this->b = b;
    this->c = c;

    this->min = min;
    this->max = max;
    this->step = step;
}

interval::~interval()
{

}

double tempFunctionCalculate(double a, double b, double c, double x)
{

    if(a < 0 && x != 0)
        return a * pow(x, 2.0) + pow(b, 2.0) * x;

    if(a > 0 && x == 0)
        return x - (a / x - c);

    return 1 + (x/c);

}

double interval::calculate()
{

    for(double i = this->min; i <= this->max; i + this->step){
        return tempFunctionCalculate(a, b, c, i);
    }

}
