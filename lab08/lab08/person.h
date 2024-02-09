#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person
{

private:
    std::string lastname;
    std::string firstname;

    std::string dateOfBirthday;
    std::string sex;
    std::string zodiacSign;

public:
    Person();
    Person(std::string, std::string, std::string, std::string);

    void setDataObject(std::string, std::string, std::string, std::string);
    std::vector<std::string> getDataObject();

};

#endif // PERSON_H
