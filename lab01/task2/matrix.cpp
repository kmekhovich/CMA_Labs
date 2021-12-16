#include <cassert>
#include "matrix.h"

Matrix::Matrix(unsigned int n) : n_(n) {}

double Matrix::At(unsigned int i, unsigned int j) const {
    assert(i < n_ && j < n_);
    if (i == j) {
        return n_;
    }
    if (i == 0 || j == 0) {
        return 1;
    }
    return 0;
}

Vector Matrix::operator*(const Vector &rhs) const {
    Vector result(n_);
    for (size_t i = 0; i < n_; i++) {
        for (size_t j = 0; j < n_; j++) {
            result.At(i) += At(i, j) * rhs.At(j);
        }
    }
    return result;
}
