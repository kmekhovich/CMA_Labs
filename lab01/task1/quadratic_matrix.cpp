#include "quadratic_matrix.h"

QuadraticMatrix::QuadraticMatrix(int n) : n_(n) {
    fields_ = static_cast<double**>(malloc(n_ * sizeof(double *)));
    for (int i = 0; i < n_; i++) {
        fields_[i] = static_cast<double *>(malloc(n_ * sizeof(double)));
    }
}

QuadraticMatrix::~QuadraticMatrix() {
    for (int i = 0; i < n_; i++) {
        free(fields_[i]);
    }
    free(fields_);
}

std::ostream& operator<<(std::ostream &os, const QuadraticMatrix& matrix) {
    for (int i = 0; i < matrix.n_; i++) {
        for (int j = 0; j < matrix.n_; j++) {
            os << matrix.At(i, j) << " ";
        }
        os << "\n";
    }
    return os;
}

int QuadraticMatrix::GetSide() const {
    return n_;
}

double &QuadraticMatrix::At(int i, int j) {
    return fields_[i][j];
}

const double &QuadraticMatrix::At(int i, int j) const {
    return fields_[i][j];
}
