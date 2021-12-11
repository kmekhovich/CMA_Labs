#include <cstdlib>
#include <cstring>
#include <random>
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
    if (indexes_.empty()) {
        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz; j++) {
                result.At(i) += data_[i][j] * rhs.At(j);
            }
        }
    } else {
        for (const auto& pair : indexes_) {
            result.At(pair.first) += data_[pair.first][pair.second] * rhs.At(pair.second);
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

NormMatrix NormMatrix::GenerateWithRate(int size, double rate) {
    static std::mt19937 rng(45);
    static std::uniform_real_distribution<double> uni(-2, 2);
    static std::uniform_real_distribution<double> chance(0, 1);
    NormMatrix result(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (chance(rng) <= rate) {
                result.At(i, j) = 0;
            } else {
                result.At(i, j) = uni(rng);
            }
        }
    }
    return result;
}

void NormMatrix::PlusRowWithCof(int rowTo, int rowFrom, double cof) {
    for (int i = 0; i < m_; i++) {
        At(rowTo, i) += cof * At(rowFrom, i);
    }
}

NormMatrix::NormMatrix(const NormMatrix &rhs) : NormMatrix(rhs.n_, rhs.m_) {
    for (int i = 0; i < n_; i++) {
        memcpy(data_[i], rhs.data_[i], m_ * sizeof(double));
    }
}

void NormMatrix::SetOptimized() {
    indexes_.clear();
    for (int i = 0; i < n_; i++) {
        for (int j = 0; j < m_; j++) {
            if (std::abs(data_[i][j]) > 1e-15) {
                indexes_.emplace_back(i, j);
            }
        }
    }
}
