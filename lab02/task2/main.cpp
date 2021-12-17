#include <iostream>
#include "matrix.h"

int main() {
    int n = 20;
    Matrix m(n, true);
    m.SetVar2();
    std::cout << m << "\n";
    auto zaprs = m.MakeFrobenius();
    auto ans = m.FindRoots();
    std::reverse(zaprs.begin(), zaprs.end());
    for (auto& it : ans) {
        std::vector<double> resultVector(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            resultVector[i] = resultVector[i + 1] * it.first;
        }
        for (const auto& z : zaprs) {
            if (z.type == 0) {
                std::swap(resultVector[z.values.front()], resultVector[z.values.back()]);
            } else if (z.type == 1) {
                resultVector[z.values.front()] /= z.values.back();
            } else {
                resultVector[z.values.front()] -= resultVector[*(z.values.begin() + 1)] * z.values.back();
            }
        }
        it.second = std::move(resultVector);
    }
    for (const auto& it : ans) {
        std::cout << "eigenvalue : " << it.first << " eigenvector: \n";
        for (const auto& itit : it.second) {
            std::cout << itit << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
