#ifndef FUNCTION_H
#define FUNCTION_H

class function
{

protected:
    double a;
    double b;
    double c;

public:
    virtual double calculate() = 0;

};

class point : public function
{

private:
    double x;

public:
    point(double a, double b, double c, double x);
    virtual ~point();

    double calculate() override;

};

class interval : public function
{

private:
    double min;
    double max;
    double step;

public:
    interval(double a, double b, double c, double min, double max, double step);
    virtual ~interval();

    double calculate() override;

};

#endif
