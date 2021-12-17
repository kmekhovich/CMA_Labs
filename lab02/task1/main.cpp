#include <iostream>
#include <numeric>
#include "matrix.h"
#include "clock_guard.h"

int main() {
    std::vector<int> sizes = {25, 75, 150, 250, 500, 1000};
    std::vector<double> times;
    std::vector<int> iters;
    for (auto& size : sizes) {
        iters.push_back(0);
        std::vector<double> time;
        for (int i = 0; i < 3; i++) {
            Matrix m(size, true);
//            std::cout << m << "\n";
            int iter;
            auto ans = [&]() {
                ClockGuard clockGuard(&std::cout, "power", &time);
                return m.PowerMethod(iter);
            }();
            iters.back() += iter;

    //        for (const auto& a : ans) {
    //            std::cout << "eigenvalue : " << a.second << "\neigenvector : \n";
    //            for (const auto& b : a.first) {
    //                std::cout << b << " ";
    //            }
    //            std::cout << "\n";
    //        }
        }
        iters.back() /= time.size();
        double average = std::accumulate(time.begin(), time.end(), 0.) / static_cast<double>(time.size());
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
    f("y0", times);
    f("y1", iters);

    return 0;
}
