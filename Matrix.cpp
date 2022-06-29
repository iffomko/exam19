//
// Created by Iluha on 28.06.2022.
//

#include "Matrix.h"

Matrix::Matrix() {
    this->array = nullptr;
    this->n = 0;
    this->m = 0;
}

Matrix::Matrix(const Matrix &other) {
    for (int i = 0; i < this->n; i++)
        delete[] this->array[i];

    delete[] this->array;

    this->n = other.n;
    this->m = other.m;

    this->array = new int*[this->n];

    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->m; j++)
            this->array[i][j] = other.array[i][j];
}

Matrix::~Matrix() {
    for (int i = 0; i < this->n; i++)
        delete[] this->array[i];

    delete[] this->array;
}

void Matrix::readMatrix(std::ifstream &fin) {
    if (!fin) {
        std::cout << "Failed!\n";
    } else {
        fin >> this->n >> this->m;

        this->array = new int*[this->n];

        for (int i = 0; i < this->n; i++)
            this->array[i] = new int[this->m];

        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                fin >> this->array[i][j];
    }
}

void Matrix::printSimCouple() {
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this->m; j++)
            if (j + 1 <= this->n && i + 1 <= this->m && this->array[i][j] == -this->array[j][i]) {
                std::cout << this->array[i][j] << " " << this->array[j][i] << " " << i << " " << j << std::endl;
            }
    }
}