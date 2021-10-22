#include <iostream>
#include "checker.h"

bool Checker::IsCorrect(const QuadraticMatrix &a, const Vector &x, const Vector &b) {
    int n = a.GetSide();
    if (n != x.GetSide() || n != b.GetSide()) {
        return false;
    }
    Vector ans(n);
    for (int i = 0; i < n; i++) {
        ans.At(i) = 0;
        for (int j = 0; j < n; j++) {
            ans.At(i) += a.At(i, j) * x.At(j);
        }
    }

    for (int i = 0; i < n; i++) {
        if (std::abs(b.At(i) - ans.At(i)) > 1e-1) {
            std::cout << "error: " << b.At(i) << " " << ans.At(i);
            return false;
        }
    }
    return true;
}
