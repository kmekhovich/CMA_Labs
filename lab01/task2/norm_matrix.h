//
// Created by Kanstantsin Mekhavich on 03.11.2021.
//

#ifndef TASK2_NORM_MATRIX_H
#define TASK2_NORM_MATRIX_H

#include <iostream>
#include "vector.h"
#include "matrix.h"

class NormMatrix {
public:
    NormMatrix(int n, int m);
    ~NormMatrix();

    Vector operator*(const Vector& rhs) const;

    const double& At(unsigned int i, unsigned int j) const;
    double& At(unsigned int i, unsigned int j);

    friend std::ostream& operator<<(std::ostream& os, const NormMatrix& matrix);

private:
    int n_, m_;
    double** data_;
};


#endif //TASK2_NORM_MATRIX_H
