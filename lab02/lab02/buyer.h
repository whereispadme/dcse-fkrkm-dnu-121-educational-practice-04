#ifndef BUYER_H
#define BUYER_H

#include "purchase.h"
#include "book.h"
#include <string>

struct Initials
{

public:
    std::string lastName;
    std::string firstName;
    std::string middleName;

};

class Buyer
{

public:
    Buyer();
    Buyer(Initials object, Book *&book, int, int, int);
    ~Buyer();

    Initials getInitials();
    void setData(Initials object, Book *&book, int, int, int);

    int  getTotalSum();
    int* getTotalEachSum();
    int  getTotalBookCount();
    int* getTotalEachCount();

private:
    Initials initials;
    Purchase purchase;

};

#endif
