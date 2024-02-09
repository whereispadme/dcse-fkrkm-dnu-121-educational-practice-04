/*

Варіант 9.

1 У масиві розташувати спочатку всі елементи, які не перевищують середнє арифметичне елементів масиву, потім всі інші елементи.
2 Обчислити максимальний по модулю елемент масиву.
3 Обчислити  суму елементів масиву, розташованих між першим і останнім позитивними елементами.
4 Перетворити масив таким чином, щоб елементи, які дорівнюють нулю, розташовувалися після всіх інших.

*/

#pragma once

#include <vector>
#include <string>

template <typename T>
class MyArray
{

private:
    T* data;
    unsigned int size;

public:
    MyArray();
    MyArray(unsigned int size);
    ~MyArray();

    void setData(std::vector<T> valueVector);
    T getDataIndex(int index);

    unsigned int getSize();

    void setNotMoreAverageThenOthers();
    T calculateMaxAbsoluteElement();
    std::string sumElementsBetweenFirstLastPos();
    void convertNullElementsInEnd();

    T operator[] (const int index);

};

#include "MyArrayTpp.h"
