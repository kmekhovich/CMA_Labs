#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H


#include "vector.h"

class Matrix {
public:
    explicit Matrix(unsigned int n);
    double At(unsigned int i, unsigned int j) const;

    Vector operator*(const Vector& rhs) const;

private:
    unsigned int n_;
};


#endif //TASK2_MATRIX_H
