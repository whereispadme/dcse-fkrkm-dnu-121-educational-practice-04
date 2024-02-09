#include "buyer.h"

Buyer::Buyer()
{

    this->initials.lastName = "";
    this->initials.firstName = "";
    this->initials.middleName = "";

}

Buyer::~Buyer()
{
}

Buyer::Buyer(Initials object, Book *&book, int countOfPhysics, int countOfMath, int countOfInfo)
{

    this->initials.lastName = object.lastName;
    this->initials.firstName = object.firstName;
    this->initials.middleName = object.middleName;

    purchase.setData(book, countOfPhysics, countOfMath, countOfInfo);

}

Initials Buyer::getInitials()
{

    return this->initials;

}

void Buyer::setData(Initials object, Book *&book, int countOfPhysics, int countOfMath, int countOfInfo)
{
    this->initials.lastName = object.lastName;
    this->initials.firstName = object.firstName;
    this->initials.middleName = object.middleName;

    purchase.setData(book, countOfPhysics, countOfMath, countOfInfo);
}

int Buyer::getTotalSum()
{

    return this->purchase.getTotalSum();

}

int* Buyer::getTotalEachSum()
{

    return this->purchase.getTotalEachSum();

}

int Buyer::getTotalBookCount()
{
    return this->purchase.getTotalBookCount();
}

int * Buyer::getTotalEachCount()
{
    return this->purchase.getTotalEachCount();
}
