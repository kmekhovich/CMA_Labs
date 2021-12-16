#include "matrix.h"

#include <iostream>

int main() {
    Matrix m(20, true);
    m.SetVar2();
    std::cout << m << "\n";
    m.MakeHessenByReflectionMethod();
    std::cout << m << "\n";
    auto eigenvalues = m.DoQRAlgorithm();
//    std::cout << m << "\n";

    for (const auto& eigenvalue : eigenvalues) {
        std::cout << eigenvalue << " ";
    }
    return 0;
}
