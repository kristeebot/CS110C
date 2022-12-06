#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef vector<int> MatrixRow;

class Matrix
{
private:
    vector<MatrixRow> adjacencyMatrix;
    double inf; // convenient infinity

public:
    Matrix(int size)
    {
        inf = std::numeric_limits<double>::infinity();
        adjacencyMatrix.resize(size);
        for (int i = 0; i < size; i++)
        {
            adjacencyMatrix[i].resize(size, inf);
        }
    }
    void setItem(int row, int column, int value)
    {
        adjacencyMatrix[row][column] = value;
    }

    void printShortestPath(int startingNode);
};


#endif // MATRIX_H_
