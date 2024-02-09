/*

1) Середнє арифметичне й середнє геометричне мінімальних  елементів у заданому рядку й стовпці.
2) Номер першого зі стовпців, що містять хоча б один нульовий елемент.
3) Характеристикою рядка цілочисельної  матриці назвемо суму її негативних парних елементів. Визначити мінімальну й максимальну з характеристик.


*/

#pragma once

#include <vector>
#include <string>

class Matrix {

private:
    int **matrix;
    int rows;
    int cols;

public:

    Matrix();
    Matrix(int rows, int cols, std::vector<int**> vectorMatrix);
    Matrix(int rows, int cols);
    ~Matrix();

    std::vector<std::string> getAverageArGeoInSelect(int selectRow, int selectCol);
    std::string getFirstColumnHaveNull();
    std::vector<std::string> getMinMaxSumNegUnpairedEachRow();

    int getRows() { return this->rows; }
    int getCols() { return this->cols; }
    int getMatrix(int i, int j) { return this->matrix[i][j]; }

    void setIndex(int row, int col, int data);

};
