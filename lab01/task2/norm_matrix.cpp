#include <cstdlib>
#include <cstring>
#include "norm_matrix.h"

NormMatrix::NormMatrix(int n, int m) : n_(n), m_(m) {
    data_ = static_cast<double**>(malloc(sizeof(double*) * n_));
    for (size_t i = 0; i < n_; i++) {
        data_[i] = static_cast<double*>(malloc(sizeof(double) * m_));
        memset(data_[i], 0, m_ * sizeof(double));
    }
}

Vector NormMatrix::operator*(const Vector &rhs) const {
    int sz = rhs.GetSize();
    Vector result(sz);
    for (size_t i = 0; i < sz; i++) {
        for (size_t j = 0; j < sz; j++) {
            result.At(i) += data_[i][j] * rhs.At(j);
        }
    }
    return result;
}

double& NormMatrix::At(unsigned int i, unsigned int j) {
    return data_[i][j];
}

NormMatrix::~NormMatrix() {
    for (size_t i = 0; i < n_; i++) {
        free(data_[i]);
    }
    free(data_);
}

std::ostream &operator<<(std::ostream &os, const NormMatrix &matrix) {
    for (size_t i = 0; i < matrix.n_; i++) {
        for (size_t j = 0; j < matrix.m_; j++) {
            std::cout << matrix.data_[i][j] << " ";
        }
        std::cout << "\n";
    }
    return os;
}

const double &NormMatrix::At(unsigned int i, unsigned int j) const {
    return data_[i][j];
}
