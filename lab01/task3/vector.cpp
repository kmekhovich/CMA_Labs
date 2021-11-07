//
// Created by Kanstantsin Mekhavich on 28.10.2021.
//

#include <cassert>
#include <cstring>
#include <random>
#include "vector.h"

Vector::Vector(unsigned int n) : n_(n) {
    data_ = static_cast<double*>(malloc(n_ * sizeof(double)));
    memset(data_, 0, n_ * sizeof(double));
}

const double& Vector::At(unsigned int i) const {
    assert(i < n_);
    return data_[i];
}

void Vector::SetOnes() {
    for (size_t i = 0; i < n_; i++) {
        data_[i] = 1;
    }
}

Vector::~Vector() {
    if (n_) {
        delete[] data_;
    }
}

double Vector::DotProduct(const Vector &rhs) const {
    double result{0};
    for (size_t i = 0; i < n_; i++) {
        result += At(i) * rhs.At(i);
    }
    return result;
}

Vector Vector::operator*(double x) const {
    Vector result(*this);
    for (size_t i = 0; i < n_; i++) {
        result.At(i) *= x;
    }
    return result;
}

Vector::Vector(const Vector &rhs) : n_(rhs.n_) {
    data_ = static_cast<double*>(malloc(n_ * sizeof(double)));
    memcpy(data_, rhs.data_, n_ * sizeof(double));
}

double Vector::GetLength() const {
    double result{0};
    for (size_t i = 0; i < n_; i++) {
        result += At(i) * At(i);
    }
    return sqrt(result);
}

Vector &Vector::operator-=(const Vector &rhs) {
    for (size_t i = 0; i < n_; i++) {
        At(i) -= rhs.At(i);
    }
    return *this;
}

int Vector::GetSize() const {
    return n_;
}

Vector &Vector::operator=(const Vector &rhs) {
    if (n_ < rhs.n_) {
        if (n_ > 0) {
            free(data_);
        }
        n_ = rhs.n_;
        data_ = static_cast<double*>(malloc(n_ * sizeof(double)));
        memcpy(data_, rhs.data_, n_ * sizeof(double));
        return *this;
    }
    for (int i = 0; i < n_; i++) {
        data_[i] = i < rhs.n_ ? rhs.At(i) : 0;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Vector &rhs) {
    for (int i = 0; i < rhs.n_; i++) {
        os << rhs.data_[i] << " ";
    }
    os << "\n";
    return os;
}

Vector operator-(const Vector &lhs, const Vector &rhs) {
    auto cpy = lhs;
    cpy -= rhs;
    return cpy;
}

Vector &Vector::operator=(double value) {
    for (size_t i = 0; i < n_; i++) {
        At(i) = value;
    }
    return *this;
}

Vector &Vector::operator+=(const Vector &rhs) {
    for (size_t i = 0; i < n_; i++) {
        At(i) += rhs.At(i);
    }
    return *this;
}

double &Vector::At(unsigned int i) {
    return data_[i];
}

Vector::Vector() : n_(0) {}

Vector Vector::Generate(int size) {
    static std::mt19937 rng(42);
    static std::uniform_real_distribution<double> uni(-1000, 1000);
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.At(i) = uni(rng);
    }
    return result;
}
