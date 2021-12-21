#include "matrix.h"
#include "clock_guard.h"

#include <iostream>
#include <numeric>

void test() {
    Matrix m(20, true);
    m.SetVar2();
    int iter;
    std::vector<double> time;
    auto ans = [&]() {
        ClockGuard clockGuard(&std::cout, "all", &time);
        m.MakeHessenByReflectionMethod();
        return m.DoQRAlgorithm(iter);
    }();
    std::cout << "iterations : " << iter << "\n";
    for (const auto& it : ans) {
        std::cout << it << " ";
    }
}

int main() {
    test();
    return 0;
    std::vector<int> sizes = {25, 75, 150, 250};
    std::vector<double> times;
    std::vector<double> timesH;
    std::vector<int> iters;
    for (auto& size : sizes) {
        iters.push_back(0);
        std::vector<double> timeH;
        std::vector<double> time;
        for (int i = 0; i < 1; i++) {
            Matrix m(size, true);
//            std::cout << m << "\n";
            int iter;
            {
                ClockGuard clockGuard(&std::cout, "make hessen", &timeH);
                m.MakeHessenByReflectionMethod();
            };
            auto ans = [&]() {
                ClockGuard clockGuard(&std::cout, "qr-algo", &time);
                return m.DoQRAlgorithm(iter);
            }();
            iters.back() += iter;
        }
        iters.back() /= time.size();
        double averageH = std::accumulate(timeH.begin(), timeH.end(), 0.) / static_cast<double>(time.size());
        double average = std::accumulate(time.begin(), time.end(), 0.) / static_cast<double>(time.size());
        timesH.push_back(averageH);
        times.push_back(average);
    }
    auto f = [&] (auto& str, auto& m) {
        std::cout << str << " = [";
        bool fst = true;
        for (const auto &i: m) {
            if (!fst) {
                std::cout << ", ";
            }
            std::cout << i;
            fst = false;
        }
        std::cout << "]\n";
    };
    f("x", sizes);
    f("y00", timesH);
    f("y01", times);
    f("y1", iters);

    return 0;
}
