#include <iostream>
#include <vector>
#include "matrix.h"
#include "vector.h"
#include "norm_matrix.h"
#include "gmres.h"
#include "clock_guard.h"
#include <fstream>

template <typename T>
double GetEuclid(const T& a, const Vector& x, const Vector& b, unsigned int size) {
    Vector res(size);
    for (size_t j = 0; j < size; j++) {
        res.At(j) = -b.At(j);
    }
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            res.At(i) += a.At(i, j) * x.At(j);
        }
    }
    double norm = 0;
    for (size_t i = 0; i < size; i++) {
        norm += res.At(i) * res.At(i);
    }
    return sqrt(norm);
}

int main() {
    const std::vector<unsigned int> sizes{500, 1000, 2000, 4000};
    std::vector<std::vector<double>> results(2);
    for (const auto size : sizes) {
        ClockGuard cl(&std::cout, " gauss", &results[0]);
        Matrix a(size);
        Vector b(size);
        b.SetOnes();
        Vector x(size);
        x.SetOnes();
        int iterations = 0;
        while (GetEuclid(a, x, b, size) > 1e-10) {
            for (size_t i = 0; i < size; i++) {
                x.At(i) = b.At(i);
                for (size_t j = 0; j < size; j++) {
                    if (i == j) {
                        continue;
                    }
                    x.At(i) -= a.At(i, j) * x.At(j);
                }
                x.At(i) /= a.At(i, i);
            }
            iterations++;
        }
        std::cout << size << " : " << iterations << "\n";
    }
    for (const auto size : sizes) {
        ClockGuard cl(&std::cout, " gmres", &results[1]);
        Matrix a(size);
        Vector b(size);
        b.SetOnes();
        Vector x(size);
        int max_iters = size;
        NormMatrix h(size + 1, size);
        GMRES::Solve(a, x, b, max_iters, 1e-10);
        std::cout << size << " : " << max_iters << "\n";
    }
    std::ofstream out("out.txt");
    for (int i = 0; i < 2; i++) {
        out << "y" << i << "=[";
        bool fst = true;
        for (const auto &msec: results[i]) {
            if (!fst) {
                out << ", ";
            }
            out << msec;
            fst = false;
        }
        out << "]\n";
    }
    out << "\n";
    return 0;
}
