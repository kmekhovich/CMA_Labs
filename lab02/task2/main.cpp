#include <iostream>
#include "matrix.h"

int main() {
    Matrix m(20, true);
    m.SetVar2();
    std::cout << m << "\n";
    m.MakeFrobenius();
    auto ans = m.FindRoots();
    for (const auto& it : ans) {
        std::cout << "eigenvalue : " << it.first << " eigenvector: \n";
        for (const auto& itit : it.second) {
            std::cout << itit << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
