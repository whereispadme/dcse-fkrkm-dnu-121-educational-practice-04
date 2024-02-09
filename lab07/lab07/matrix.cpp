#pragma once
#include "matrix.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
using namespace std;

Matrix::Matrix()
{

    this->matrix = nullptr;
    this->rows = 0;
    this->cols = 0;

}

Matrix::Matrix(int rows, int cols, std::vector<int**> vectorMatrix)
{

    this->rows = rows;
    this->cols = cols;

    this->matrix = vectorMatrix[0];

}

Matrix::Matrix(int rows, int cols)
{

    this->rows = rows;
    this->cols = cols;

    matrix = new int *[rows];

    for (int j = 0; j < rows; ++j)
    {

        matrix[j] = new int[cols];

    }

    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j)
        {

            this->matrix[i][j] = 0;

        }
    }

}

Matrix::~Matrix()
{

    if (this->matrix != nullptr) {

        for (int i = 0; i < rows; ++i)
        {

            delete matrix[i];

        }

        delete[] matrix;

    }

}

vector<std::string> Matrix::getAverageArGeoInSelect(int selectRow, int selectCol)
{

    double averageAr = 0;
    double averageGeo = 1;

    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j)
        {

            if (i == selectRow)
            {
                averageAr += this->matrix[i][j];
            }

        }
    }

    averageAr = averageAr / this->cols;

    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j)
        {

            if (j == selectCol)
            {
                averageGeo *= this->matrix[i][j];
            }

        }
    }

    averageGeo = pow(averageGeo, 1 / 3.0);

    vector<string> stringVector;
    std::string *str = new string[2];

    str[0].append("Середнє арифметичне " + to_string(selectRow + 1) +  " рядка: "  + to_string(averageAr) + "!");
    stringVector.push_back(str[0]);

    str[1].append("Середнє геометричне " + to_string(selectCol + 1) +  " стовпця: " + to_string(averageGeo) + "!");
    stringVector.push_back(str[1]);

    delete[] str;

    return stringVector;

}

std::string Matrix::getFirstColumnHaveNull()
{

    int requiredColumn = -1;
    bool statusQuitForCicle = false;

    for (int j = 0; j < this->cols; ++j) {
        for (int i = 0; i < this->rows; ++i) {

            if (this->matrix[i][j] == 0)
            {

                requiredColumn = j + 1;
                statusQuitForCicle = true;
                break;

            }

        }

        if (statusQuitForCicle)
            break;

    }

    std::string str;

    if (requiredColumn == -1)
    {
        str.append("Номер першого зі стовпців, що містять хоча б один нульовий елемент: Не було нульових елементів!");
    }
    else
    {
        str.append("Номер першого зі стовпців, що містять хоча б один нульовий елемент: " + std::to_string(requiredColumn));
    }

    return str;

}

vector<string> Matrix::getMinMaxSumNegUnpairedEachRow()
{

    std::vector<int> vectorSumNegUnpaired;

    int tempNegSumUnpaired = -1;
    bool status = false;


    for (int i = 0; i < this->rows; ++i)
    {

        tempNegSumUnpaired = 0;

        for (int j = 0; j < this->cols; ++j)
        {

            if (this->matrix[i][j] % 2 != 0 && this->matrix[i][j] < 0)
            {

                tempNegSumUnpaired += this->matrix[i][j];
                status = true;

            }

        }

        vectorSumNegUnpaired.push_back(tempNegSumUnpaired);

    }

    vector<string> stringVector;
    std::string *str = new string[2];

    if (!status)
    {

        str[0].append("Не було введено жодного непарного значення!");
        stringVector.push_back(str[0]);

        delete[] str;

        return stringVector;

    }

    int negativeSumCount = 0;
    int value = 0;
    int absRow = 0;

    for (int i = 0; i < vectorSumNegUnpaired.size(); ++i)
    {

        if (vectorSumNegUnpaired[i] < 0)
        {

            negativeSumCount++;
            value = vectorSumNegUnpaired[i];
            absRow = i + 1;

        }

    }

    if (negativeSumCount == 1)
    {

        str[0].append("Було знайдено один рядок з непарними елементами, аболютне значення характеристики: " + to_string(value) + "; рядок: " + to_string(absRow) + "!");
        stringVector.push_back(str[0]);


    }
    else
    {

        int min = vectorSumNegUnpaired[0];
        int minRow;

        int max = vectorSumNegUnpaired[0];
        int maxRow;

        for (int i = 0; i < vectorSumNegUnpaired.size(); ++i)
        {

            if (vectorSumNegUnpaired[i] <= min && (vectorSumNegUnpaired[i] < 0))
            {

                min = vectorSumNegUnpaired[i];
                minRow = i + 1;

            }

        }

        for (int i = 0; i < vectorSumNegUnpaired.size(); ++i)
        {

            if (vectorSumNegUnpaired[i] >= max && (vectorSumNegUnpaired[i] < 0))
            {

                max = vectorSumNegUnpaired[i];
                maxRow = i + 1;

            }

        }

        str[0].append("Мінімальна  з характеристик: " + to_string(min) + "; рядок: " + to_string(minRow) + "!");
        stringVector.push_back(str[0]);

        str[1].append("Максимальна з характеристик: " + to_string(max) + "; рядок: " + to_string(maxRow) + "!");
        stringVector.push_back(str[1]);

    }

    delete[] str;

    return stringVector;

}

void Matrix::setIndex(int row, int col, int data)
{

    if(this->matrix == nullptr)
        return;

    this->matrix[row][col] = data;

}
