#include "vector.h"

#include "random_generator.h"

#include <cstdlib>

Vector::Vector(int n) : n_(n) {
    fields_ = static_cast<double *>(malloc(n * sizeof(double)));
}

Vector::~Vector() {
    free(fields_);
}

const double *Vector::Get() const {
    return fields_;
}

double &Vector::At(int i) {
    return fields_[i];
}

const double &Vector::At(int i) const {
    return fields_[i];
}

void Vector::LoadRandomValues(double l, double r) {
    RandomGenerator::GenerateDoubleArray(fields_, n_, l, r);
}

std::ostream &operator<<(std::ostream &os, const Vector& vector) {
    for (int i = 0; i < vector.n_; i++) {
        os << vector.fields_[i] <<  " ";
    }
    os << "\n";
    return os;
}

int Vector::GetSide() const {
    return n_;
}
