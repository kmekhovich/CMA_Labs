#include <iostream>
#include "clock_guard.h"
#include "gmres.h"
#include "norm_matrix.h"
#include "vector.h"
#include "smart_gauss.h"

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
    std::vector<std::vector<double>> results(3);
    int size = 1000;
    std::vector<double> rates{0.0, 0.5, 0.9, 0.95, 0.99};
    for (const auto rate : rates) {
        NormMatrix a = NormMatrix::GenerateWithRate(size, rate);
        Vector b = Vector::Generate(size);
        double eps = 1e-10;
        {
            Vector x;
            ClockGuard cl(&std::cout, "Gauss", &results[0]);
            SmartGauss::Solve(a, x, b, eps);
            std::cout << GetEuclid(a, x, b, size) << "\n";
        }
        {
            ClockGuard cl(&std::cout, "Gmres", &results[1]);
            Vector x;
            int iters = size;
            GMRES::Solve(a, x, b, iters, eps);
            std::cout << GetEuclid(a, x, b, size) << "\n";
            std::cout << iters << " iters\n";
        }
        a.SetOptimized();
        {
            ClockGuard cl(&std::cout, "Gmres optimized 1", &results[2]);
            Vector x;
            int iters = size;
            GMRES::Solve(a, x, b, iters, eps);
            std::cout << GetEuclid(a, x, b, size) << "\n";
            std::cout << iters << " iters\n";
        }
    }
    std::ofstream out("out.txt");
    for (int i = 0; i < results.size(); i++) {
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
