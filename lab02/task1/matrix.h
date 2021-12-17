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
    void SetVar3();
    void SetVar4();

    std::vector<std::pair<std::vector<std::complex<double>>, std::complex<double>>> PowerMethod(int& iters, double eps = 1e-6) const;

    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);

    friend std::vector<std::complex<double>> operator*(const Matrix& lhs, const std::vector<double>& rhs);
    friend std::vector<std::complex<double>> operator*(const Matrix& lhs, const std::vector<std::complex<double>>& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

private:
    int n_, m_;
    std::vector<std::vector<std::complex<double>>> a_;
};


#endif //TASK3_MATRIX_H
