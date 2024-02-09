#pragma once
#include "MyArray.h"
#include <cmath>

template<typename T>
inline MyArray<T>::MyArray()
{

    this->data = nullptr;
    this->size = 0;

}

template<typename T>
inline MyArray<T>::MyArray(unsigned int size)
{

    this->size = size;
    this->data = new T[this->size];

    for (unsigned int i = 0; i < this->size; ++i)
        this->data[i] = 0;

}

template<typename T>
inline MyArray<T>::~MyArray()
{

    if (this->data != nullptr)
        delete[] this->data;

}

template<typename T>
inline void MyArray<T>::setData(std::vector<T> valueVector)
{

    if (this->data == nullptr)
        return;

    for (unsigned int i = 0; i < this->size; ++i)
        this->data[i] = valueVector[i];

}

template<typename T>
inline T MyArray<T>::getDataIndex(int index)
{
    return this->data[index];
}

template<typename T>
inline unsigned int MyArray<T>::getSize()
{
    return this->size;
}

template<typename T>
inline void MyArray<T>::setNotMoreAverageThenOthers()
{

    if (this->data == nullptr)
        return;

    T averageValue = 0;

    for (unsigned int i = 0; i < this->size; ++i)
    {
        averageValue += this->data[i];
    }

    averageValue = averageValue / this->size;

    std::vector<T> tempVector;

    for (unsigned int i = 0; i < this->size; ++i)
    {

        if (this->data[i] < averageValue)
        {

            tempVector.push_back(this->data[i]);

        }

    }

    for (unsigned int i = 0; i < this->size; ++i)
    {

        if (this->data[i] >= averageValue)
        {

            tempVector.push_back(this->data[i]);

        }

    }

    for (unsigned int i = 0; i < this->size; ++i)
    {

        this->data[i] = tempVector[i];

    }

}

template<typename T>
inline T MyArray<T>::calculateMaxAbsoluteElement()
{

    if (this->data == nullptr)
        return NULL;

    T maxAbsoluteValue = fabs(this->data[0]);

    for (unsigned int i = 0; i < this->size; ++i)
    {

        if (fabs(this->data[i]) > maxAbsoluteValue)
        {
            maxAbsoluteValue = fabs(this->data[i]);
        }

    }

    return maxAbsoluteValue;

}

template<typename T>
inline std::string MyArray<T>::sumElementsBetweenFirstLastPos()
{

    if (this->data == nullptr)
        return NULL;

    T sum = 0;
    size_t step(0);

    for (unsigned int i = 0; i < this->size; ++i) {
        switch (step) {

        case 0: {
            if (this->data[i] > 0) {
                step = 1;
            }
            break;
        }

        case 1: {
            if (this->data[i] > 0) {
                step = 2;
            }
            else {
                sum += this->data[i];
            }
            break;
        }

        case 2: {
            break;
        }
        }//switch
    }//for

    std::string str = "";

    switch (step) {
        case 0: {
            str = "Не було позитивних елеменнтів!";
            return str;
        }

        case 1: {
            str = "Було введено тільки один позитивний елемент!";
            return str;
        }

        case 2: {
            str = "Сумма між першим та другим позитивними елементами: " + std::to_string(sum);
            return str;
        }

    }

    return str;

}

template<typename T>
inline void MyArray<T>::convertNullElementsInEnd()
{

    if (this->data == nullptr)
        return;

    std::vector<T> tempVector;

    for (unsigned int i = 0; i < this->size; ++i)
    {

        if (this->data[i] != 0.)
        {

            tempVector.push_back(this->data[i]);

        }

    }

    for (unsigned int i = 0; i < this->size; ++i)
    {

        if (this->data[i] == 0.)
        {

            tempVector.push_back(this->data[i]);

        }

    }

    for (unsigned int i = 0; i < this->size; ++i)
    {

        this->data[i] = tempVector[i];

    }

}
