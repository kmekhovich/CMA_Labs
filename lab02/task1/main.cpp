#include <iostream>
#include "matrix.h"

int main() {
    Matrix m(20, true);
    m.SetVar2();
    std::cout << m << "\n";
    auto ans = m.PowerMethod();
    for (const auto& a : ans) {
        std::cout << "eigenvalue : " << a.second << "\neigenvector : \n";
        for (const auto& b : a.first) {
            std::cout << b << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
