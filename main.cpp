#include <iostream>
#include <fstream>
#include "Matrix.h"

int main() {
    std::ifstream fin("C:\\project11\\input.txt");

    int n;

    if (!fin) {
        std::cout << "Failed!\n";
    } else {
        fin >> n;

        for (int i = 0; i < n; i++) {
            Matrix matrix;
            matrix.readMatrix(fin);
            matrix.printSimCouple();
        }
    }

    fin.close();

    return 0;
}
