#include "person.h"

Person::Person()
{

    this->lastname = "";
    this->firstname = "";

    this->dateOfBirthday = "";
    this->sex = "";
    this->zodiacSign = "";

}

Person::Person(std::string lastname, std::string firstname, std::string dateOfBirthday, std::string sex)
{

    this->lastname = lastname;
    this->firstname = firstname;

    this->dateOfBirthday = dateOfBirthday;
    this->sex = sex;

    int index = 0;

    std::string _day;
    std::string _month;

    std::string temp;

    for(int i = 0; this->dateOfBirthday.length(); ++i)
    {

        if(dateOfBirthday[i] != '.')
        {
            temp = dateOfBirthday[i];
            _day.append(temp);
        }
        else
        {
            index = i;
            break;
        }

    }

    for(int i = index + 1; this->dateOfBirthday.length(); ++i)
    {

        if(dateOfBirthday[i] != '.')
        {
            temp = dateOfBirthday[i];
            _month.append(temp);
        }
        else
        {
            break;
        }

    }

    int day = std::stoi(_day);
    int month = std::stoi(_month);

    if ( (month == 3 && day >= 21) || (month == 4 && day <= 20) )
        this->zodiacSign = "Овен";	// Овен
    else
    if ( (month == 4 && day >= 21) || (month == 5 && day <= 20) )
        this->zodiacSign = "Телец";	// Телец
    else
    if ( (month == 5 && day >= 21) || (month == 6 && day <= 21) )
        this->zodiacSign = "Близнецы";	// Близнецы
    else
    if ( (month == 6 && day >= 22) || (month == 7 && day <= 22) )
        this->zodiacSign = "Рак";	// Рак
    else
    if ( (month == 7 && day >= 23) || (month == 8 && day <= 23) )
        this->zodiacSign = "Лев";	// Лев
    else
    if ( (month == 8 && day >= 24) || (month == 9 && day <= 23) )
        this->zodiacSign = "Дева";	// Дева
    else
    if ( (month == 9 && day >= 24) || (month == 10 && day <= 22) )
        this->zodiacSign = "Весы";	// Весы
    else
    if ( (month == 10 && day >= 23) || (month == 11 && day <= 22) )
        this->zodiacSign = "Скорпион";	// Скорпион
    else
    if ( (month == 11 && day >= 23) || (month == 12 && day <= 21) )
        this->zodiacSign = "Стрелец";	// Стрелец
    else
    if ( (month == 12 && day >= 22) || (month == 1 && day <= 20) )
        this->zodiacSign = "Козерог";	// Козерог
    else
    if ( (month == 1 && day >= 21) || (month == 2 && day <= 19) )
        this->zodiacSign = "Водолей";	// Водолей
    else
    if ( (month == 2 && day >= 20) || (month == 3 && day <= 20) )
        this->zodiacSign = "Рыбы";	// Рыбы

}

void Person::setDataObject(std::string lastname, std::string firstname, std::string dateOfBirthday, std::string sex)
{

    this->lastname = lastname;
    this->firstname = firstname;

    this->dateOfBirthday = dateOfBirthday;
    this->sex = sex;

    int index = 0;

    std::string _day;
    std::string _month;

    std::string temp;

    for(int i = 0; this->dateOfBirthday.length(); ++i)
    {

        if(dateOfBirthday[i] != '.')
        {
            temp = dateOfBirthday[i];
            _day.append(temp);
        }
        else
        {
            index = i;
            break;
        }

    }

    for(int i = index + 1; this->dateOfBirthday.length(); ++i)
    {

        if(dateOfBirthday[i] != '.')
        {
            temp = dateOfBirthday[i];
            _month.append(temp);
        }
        else
        {
            break;
        }

    }

    int day = std::stoi(_day);
    int month = std::stoi(_month);

    if ( (month == 3 && day >= 21) || (month == 4 && day <= 20) )
        this->zodiacSign = "Овен";	// Овен
    else
    if ( (month == 4 && day >= 21) || (month == 5 && day <= 20) )
        this->zodiacSign = "Телец";	// Телец
    else
    if ( (month == 5 && day >= 21) || (month == 6 && day <= 21) )
        this->zodiacSign = "Близнецы";	// Близнецы
    else
    if ( (month == 6 && day >= 22) || (month == 7 && day <= 22) )
        this->zodiacSign = "Рак";	// Рак
    else
    if ( (month == 7 && day >= 23) || (month == 8 && day <= 23) )
        this->zodiacSign = "Лев";	// Лев
    else
    if ( (month == 8 && day >= 24) || (month == 9 && day <= 23) )
        this->zodiacSign = "Дева";	// Дева
    else
    if ( (month == 9 && day >= 24) || (month == 10 && day <= 22) )
        this->zodiacSign = "Весы";	// Весы
    else
    if ( (month == 10 && day >= 23) || (month == 11 && day <= 22) )
        this->zodiacSign = "Скорпион";	// Скорпион
    else
    if ( (month == 11 && day >= 23) || (month == 12 && day <= 21) )
        this->zodiacSign = "Стрелец";	// Стрелец
    else
    if ( (month == 12 && day >= 22) || (month == 1 && day <= 20) )
        this->zodiacSign = "Козерог";	// Козерог
    else
    if ( (month == 1 && day >= 21) || (month == 2 && day <= 19) )
        this->zodiacSign = "Водолей";	// Водолей
    else
    if ( (month == 2 && day >= 20) || (month == 3 && day <= 20) )
        this->zodiacSign = "Рыбы";	// Рыбы

}

std::vector<std::string> Person::getDataObject()
{

    std::vector<std::string> returnVector;

    returnVector.push_back(this->lastname);
    returnVector.push_back(this->firstname);

    returnVector.push_back(this->dateOfBirthday);
    returnVector.push_back(this->sex);
    returnVector.push_back(this->zodiacSign);

    return returnVector;

}

