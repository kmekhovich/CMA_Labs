#include "symmetric_matrix.h"
#include "quadratic_matrix.h"
#include "lu_helper.h"
#include "clock_guard.h"
#include "ldlt_helper.h"
#include "checker.h"

#include <iostream>

int main() {
    int n = 2000;
    auto dest = QuadraticMatrix(n);
    auto symmetricMatrix = SymmetricMatrix(n);
    symmetricMatrix.LoadRandomValues();
    {
        ClockGuard lu(&std::cout, "lu");
        LUHelper::MakeLU(symmetricMatrix, &dest);
    }
    auto b = Vector(n);
    b.LoadRandomValues();
    {
        ClockGuard solve(&std::cout, "solve");
        auto solution = LUHelper::Solve(dest, b);
        if (!Checker::IsCorrect(symmetricMatrix, solution, b)) {
            throw std::runtime_error("error");
        }
    }
    {
        ClockGuard ldlt(&std::cout, "ldlt");
        LDLTHelper::MakeLDLT(symmetricMatrix, &dest);
    }
    {
        ClockGuard solve(&std::cout, "solve");
        auto solution = LDLTHelper::Solve(dest, b);
        if (!Checker::IsCorrect(symmetricMatrix, solution, b)) {
            throw std::runtime_error("error");
        }
    }
    return 0;
}
