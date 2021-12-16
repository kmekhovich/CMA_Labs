#include <iostream>
#include "ldlt_helper.h"

void LDLTHelper::MakeLDLT(const SymmetricMatrix &src, QuadraticMatrix *dest) {
    if (src.GetSide() != dest->GetSide()) {
        throw std::invalid_argument("Incorrect matrices");
    }
    int n = src.GetSide();
    dest->CopyFrom(src);
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            auto multi = dest->At(k, i) / dest->At(k, k);
            for (int j = i; j < n; j++) {
                dest->At(i, j) -= multi * dest->At(k, j);
            }
        }
        auto div = dest->At(k, k);
        for (int j = k + 1; j < n; j++) {
            dest->At(k, j) /= div;
        }
    }
}

Vector LDLTHelper::Solve(const QuadraticMatrix& ldlt, const Vector& b) {
    if (b.GetSide() != ldlt.GetSide()) {
        throw std::invalid_argument("Incorrect arguments");
    }
    int n = ldlt.GetSide();

    // get y
    auto y = Vector(n);
    for (int i = 0; i < n; i++)  {
        double result = b.At(i);
        for (int j = 0; j < i; j++) {
            result -= ldlt.At(j, i) * y.At(j);
        }
        y.At(i) = result;
    }

    for (int i = 0; i < n; i++) {
        y.At(i) /= ldlt.At(i, i);
    }

    // get x
    auto x = Vector(n);
    for (int i = n - 1; i >= 0; i--) {
        double result = y.At(i);
        for (int j = i + 1; j < n; j++) {
            result -= ldlt.At(i, j) * x.At(j);
        }
        x.At(i) = result;
    }
    return x;
}
