//
// Created by Kanstantsin Mekhavich on 27.11.2021.
//

#ifndef TASK3_MATRIX_H
#define TASK3_MATRIX_H

#include <vector>
#include <ostream>
#include <complex>

class Matrix {
public:
    explicit Matrix(int n, bool random = false);

    void SetVar1();
    void SetVar2();

    void MakeHessenByReflectionMethod();

    std::vector<std::complex<double>> DoQRAlgorithm(int& cnt, double eps = 1e-6);

    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

private:
    int n_, m_;
    std::vector<std::vector<double>> a_;
};


#endif //TASK3_MATRIX_H
