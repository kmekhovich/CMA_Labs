#include "symmetric_matrix.h"
#include "quadratic_matrix.h"
#include "lu_helper.h"
#include "clock_guard.h"
#include "ldlt_helper.h"
#include "checker.h"

#include <iostream>
#include <vector>
#include <fstream>

int main() {
//    const std::vector<int> sizes = {400, 800, 1200, 1600, 2000};
    const std::vector<int> sizes = {5000};
    std::ofstream out("out.txt");
    std::vector<std::vector<std::vector<double>>> msecs(2, std::vector<std::vector<double>>(2));
    for (int n : sizes) {
        auto dest = QuadraticMatrix(n);
        auto symmetricMatrix = SymmetricMatrix(n);
        symmetricMatrix.LoadRandomValues();
        {
            ClockGuard lu(&std::cout, "lu", &msecs[0][0]);
            LUHelper::MakeLU(symmetricMatrix, &dest);
        }
        auto b = Vector(n);
        b.LoadRandomValues();
        {
            ClockGuard solve(&std::cout, "solve", &msecs[1][0]);
            auto solution = LUHelper::Solve(dest, b);
//        if (!Checker::IsCorrect(symmetricMatrix, solution, b)) {
//            throw std::runtime_error("error");
//        }
        }
        {
            ClockGuard ldlt(&std::cout, "ldlt", &msecs[0][1]);
            LDLTHelper::MakeLDLT(symmetricMatrix, &dest);
        }
        {
            ClockGuard solve(&std::cout, "solve", &msecs[1][1]);
            auto solution = LDLTHelper::Solve(dest, b);
//        if (!Checker::IsCorrect(symmetricMatrix, solution, b)) {
//            throw std::runtime_error("error");
//        }
        }
    }
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 2; i++) {
            out << "y" << j << i << "=[";
            bool fst = true;
            for (const auto &msec: msecs[j][i]) {
                if (!fst) {
                    out << ", ";
                }
                out << msec;
                fst = false;
            }
            out << "]\n";
        }
        out << "\n";
    }
    return 0;
}
