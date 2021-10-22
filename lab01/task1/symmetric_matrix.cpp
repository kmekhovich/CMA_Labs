#include "symmetric_matrix.h"

#include "random_generator.h"

#include <cstdlib>
#include <random>

SymmetricMatrix::SymmetricMatrix(int n) : QuadraticMatrix() {
    n_ = n;
    fields_ = static_cast<double**>(malloc(n_ * sizeof(double *)));
    for (int i = 0; i < n_; i++) {
        fields_[i] = static_cast<double *>(malloc((i + 1) * sizeof(double)));
    }
}

void SymmetricMatrix::LoadRandomValues(double l, double r) {
    for (int i = 0; i < n_; i++) {
        RandomGenerator::GenerateDoubleArray(fields_[i], i + 1, l, r);
    }
}

double& SymmetricMatrix::At(int i, int j) {
    if (j <= i) {
        return fields_[i][j];
    } else {
        return fields_[j][i];
    }
}

const double &SymmetricMatrix::At(int i, int j) const {
    if (j <= i) {
        return fields_[i][j];
    } else {
        return fields_[j][i];
    }
}
