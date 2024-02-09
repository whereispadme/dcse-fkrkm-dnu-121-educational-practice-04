#include "functions.h"

bool correctUnsignedIntegerValue(string str)
{

    bool validStatus = false;

    for (int i = 0; i < str.length(); ++i)
    {

        if (str[i] == '0' ||
            str[i] == '1' ||
            str[i] == '2' ||
            str[i] == '3' ||
            str[i] == '4' ||
            str[i] == '5' ||
            str[i] == '6' ||
            str[i] == '7' ||
            str[i] == '8' ||
            str[i] == '9')
        {

            validStatus = true;

        }
        else
        {

            validStatus = false;
            break;

        }

    }

    return validStatus;

}
