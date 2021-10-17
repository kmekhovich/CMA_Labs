#include "lu_helper.h"
#include <iostream>

void LUHelper::MakeLU(const SymmetricMatrix& src, QuadraticMatrix* dest) {
    if (src.GetSide() != dest->GetSide()) {
        throw std::invalid_argument("Incorrect matrices");
    }
    int n = src.GetSide();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dest->At(i, j) = src.At(i, j);
        }
    }
    for (int k = 0; k < n - 1; k++) {
        auto div = dest->At(k, k);
        for (int i = k + 1; i < n; i++) {
            dest->At(i, k) /= div;
            auto multi = dest->At(i, k);
            for (int j = k + 1; j < n; j++) {
                dest->At(i, j) -= multi * dest->At(k, j);
            }
        }
    }
}

Vector LUHelper::Solve(const QuadraticMatrix& lu, const Vector& b) {
    if (b.GetSide() != lu.GetSide()) {
        throw std::invalid_argument("Incorrect arguments");
    }
    int n = lu.GetSide();
    // get y
    auto y = Vector(n);
    for (int i = 0; i < n; i++) {
        double result = b.At(i);
        for (int j = 0; j < i; j++) {
            result -= lu.At(i, j) * y.At(j);
        }
        y.At(i) = result;
    }
    // get x
    auto x = Vector(n);
    for (int i = n - 1; i >= 0; i--) {
        double result = y.At(i);
        for (int j = n - 1; j > i; j--) {
            result -= lu.At(i, j) * x.At(j);
        }
        result /= lu.At(i, i);
        x.At(i) = result;
    }
    return x;
}
