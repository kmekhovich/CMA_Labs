#ifndef TASK1_SYMMETRIC_MATRIX_H
#define TASK1_SYMMETRIC_MATRIX_H


#include "quadratic_matrix.h"

#include <ostream>

class SymmetricMatrix : public QuadraticMatrix {
public:
    explicit SymmetricMatrix(int n);

    void LoadRandomValues(double l = -1, double r = 1);

    double& At(int i, int j) override;
    const double& At(int i, int j) const override;
};


#endif //TASK1_SYMMETRIC_MATRIX_H
