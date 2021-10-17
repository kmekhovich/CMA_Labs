#include "symmetric_matrix.h"
#include "quadratic_matrix.h"
#include "lu_helper.h"

#include <iostream>

int main() {
    int n = 3;

    auto symmetricMatrix = SymmetricMatrix(n);
    symmetricMatrix.LoadRandomValues();

    std::cout << std::fixed << symmetricMatrix << "\n";
    auto dest = QuadraticMatrix(n);
    LUHelper::MakeLU(symmetricMatrix, &dest);

    auto b = Vector(n);
    b.LoadRandomValues();

    std::cout << b << "\n";

    auto solution = LUHelper::Solve(dest, b);
    std::cout << solution;
    return 0;
}
