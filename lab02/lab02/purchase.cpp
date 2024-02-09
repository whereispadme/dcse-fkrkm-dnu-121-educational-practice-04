#include "purchase.h"

Purchase::Purchase()
{

    this->books = nullptr;

    for (int i = 0; i < 3; ++i)
        this->totalEachSum[i] = 0;

    for(int i = 0; i < 3; ++i)
        this->countEachTypeOfBooks[i] = 0;

}

Purchase::Purchase(Book *&books, int countOfPhysics, int countOfPMath, int countOfInfo)
{

    this->books = books;

    this->countEachTypeOfBooks[0] = countOfPhysics;
    this->countEachTypeOfBooks[1] = countOfPMath;
    this->countEachTypeOfBooks[2] = countOfInfo;

}

Purchase::~Purchase()
{
}

void Purchase::setData(Book *&books, int countOfPhysics, int countOfPMath, int countOfInfo)
{

    this->books = books;

    this->countEachTypeOfBooks[0] = countOfPhysics;
    this->countEachTypeOfBooks[1] = countOfPMath;
    this->countEachTypeOfBooks[2] = countOfInfo;

}

int Purchase::getTotalSum()
{

    return ((this->countEachTypeOfBooks[0] * 100) + (this->countEachTypeOfBooks[1] * 200) + (this->countEachTypeOfBooks[2] * 300));

}

int* Purchase::getTotalEachSum()
{

    this->totalEachSum[0] = countEachTypeOfBooks[0] * 100;
    this->totalEachSum[1] = countEachTypeOfBooks[1] * 200;
    this->totalEachSum[2] = countEachTypeOfBooks[2] * 300;

    return this->totalEachSum;

}

int Purchase::getTotalBookCount()
{
    return (this->countEachTypeOfBooks[0] + this->countEachTypeOfBooks[1] + this->countEachTypeOfBooks[2]);
}

int * Purchase::getTotalEachCount()
{
    return this->countEachTypeOfBooks;
}
