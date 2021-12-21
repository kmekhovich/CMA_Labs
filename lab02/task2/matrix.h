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
    struct Z {
        int type; // 0 swap 1 multi 2 plus
        std::vector<double> values;
    };
    std::vector<Z> MakeFrobenius(); // return transformations

    std::vector<std::pair<double, std::vector<double>>> FindRoots(double eps = 1e-6) const;

    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    double Func(double point) const;
    double DFunc(double point) const;

private:
    int n_, m_;
    std::vector<std::vector<double>> a_;

    double GetNewtonRoot(double start, double eps = 1e-6) const;
};


#endif //TASK3_MATRIX_H
