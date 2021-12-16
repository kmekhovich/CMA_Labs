//
// Created by Kanstantsin Mekhavich on 27.11.2021.
//

#include <random>
#include <iostream>
#include "matrix.h"

namespace {
    template<typename Iterator>
    double EuclidNorm(Iterator begin, const Iterator &end) {
        double ans = 0;
        while (begin != end) {
            ans += (*begin) * (*begin);
            ++begin;
        }
        return sqrt(ans);
    }

    void ApplyPlaneRotation(double &dx, double &dy, double cs, double sn) {
        // применили матрицу поворота
        // cs  sn
        // -sn cs
        double temp = cs * dx + sn * dy;
        dy = -sn * dx + cs * dy;
        dx = temp;
    }

    void GeneratePlaneRotation(double dx, double dy, double &cs, double &sn) {
        // по двум значениям построили такой sn и cs
        // чтобы new_dy = -sn * dx + cs * dy = 0
        if (std::abs(dy) > std::abs(dx)) {
            if (std::abs(dy) < 1e-6) {
                sn = 0;
                cs = 1;
                return;
            }
            double temp = dx / dy;
            sn = 1.0 / sqrt(1.0 + temp * temp);
            cs = temp * sn;
        } else {
            if (std::abs(dx) < 1e-6) {
                sn = 1;
                cs = 0;
                return;
            }
            double temp = dy / dx;
            cs = 1.0 / sqrt(1.0 + temp * temp);
            sn = temp * cs;
        }
    }

    std::ostream &operator<<(std::ostream &os, const std::vector<double> &rhs) {
        for (const auto &it: rhs) {
            os << it << " ";
        }
        os << "\n";
        return os;
    }
}

Matrix::Matrix(int n, bool random) : n_(n), m_(n), a_(n_, std::vector<double>(m_, 0)) {
    if (random) {
        static std::mt19937 rng(42);
        static std::uniform_real_distribution<double> uni(-10, 10);
        for (int i = 0; i < n_; i++) {
            for (int j = 0; j < m_; j++) {
                a_[i][j] = uni(rng);
            }
        }
    }
}



std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    os << "[";
    for (int i = 0; i < matrix.n_; i++) {
        if (i) {
            os << ", \n";
        }
        os << "[";
        for (int j = 0; j < matrix.m_; j++) {
            if (j) {
                os << ", ";
            }
            os << matrix.a_[i][j];
        }
        os << "]";
    }
    os << "]\n";
    return os;
}

void Matrix::MakeFrobenius() {
    for (int i = n_ - 1; i >= 1; i--) {
        // выбираем наибольший
        int maxi = 0;
        for (int j = 0; j < i; j++) {
            if (std::abs(a_[i][j]) > std::abs(a_[i][maxi])) {
                maxi = j;
            }
        }

        if (maxi != i - 1) {
            for (int j = 0; j < n_; j++) {
                std::swap(a_[j][i - 1], a_[j][maxi]);
            }
            std::swap(a_[i - 1], a_[maxi]);
        }

        double c = a_[i][i - 1];
        for (int j = 0; j < n_; j++) {
            a_[j][i - 1] /= c;
        }
        for (int j = 0; j < n_; j++) {
            a_[i - 1][j] *= c;
        }
        for (int j = 0; j < n_; j++) {
            if (j == i - 1) {
                continue;
            }
            double cc = a_[i][j];
            for (int z = 0; z < n_; z++) {
                a_[z][j] -= cc * a_[z][i - 1];
            }
            for (int z = 0; z < n_; z++) {
                a_[i - 1][z] += cc * a_[j][z];
            }
        }
    }
}

std::vector<std::pair<double, std::vector<double>>> Matrix::FindRoots(double eps) const {
    std::vector<std::pair<double, std::vector<double>>> ans;
    double sz = 2e6;
    ans.reserve(sz);
    double left = -1e4;
    double right = 1e4;
    double step = (right - left) / sz;
//    std::cout << Func(-3.66920587181) << "\n";
    for (double i = left; i < right; i += step) {
        auto newRoot = GetNewtonRoot(i);
        if (ans.empty() || std::abs(newRoot - ans.back().first) > eps) {
            ans.push_back({newRoot, {}});
        }
    }
    std::sort(ans.begin(), ans.end());
    std::vector<std::pair<double, std::vector<double>>> ans2;
    ans2.reserve(ans.size());
    auto prev = *ans.begin();
    std::for_each(ans.begin(), ans.end(), [&prev, &ans2, eps] (auto& t) {
        if (std::abs(prev.first - t.first) > eps) {
            ans2.push_back(t);
            prev = t;
        }
    });
    return ans2;
}


double Matrix::GetNewtonRoot(double start, double eps) const {
    double prev = start;
    double now = start;
    while (true) {
        prev = now;
        now -= Func(now) / DFunc(now);
        if (std::abs(prev - now) < eps) {
            return now;
        }
    }
}

double Matrix::Func(double point) const {
    double res = point;
    for (int i = 0; i < n_; i++) {
        res -= a_[0][i];
        if (i != n_ - 1) {
            res *= point;
        }
    }
    return res;
}

double Matrix::DFunc(double point) const {
    double res = n_ * point;
    for (int i = 0; i < n_ - 1; i++) {
        res -= (n_ - 1 - i) * a_[0][i];
        if (i != n_ - 2) {
            res *= point;
        }
    }
    return res;
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
    Matrix ans(lhs.n_);
    for (int i = 0; i < lhs.n_; i++) {
        for (int j = 0; j < lhs.m_; j++) {
            for (int z = 0; z < lhs.m_; z++) {
                ans.a_[i][j] += lhs.a_[i][z] * rhs.a_[z][j];
            }
        }
    }
    return ans;
}

void Matrix::SetVar1() {
    assert(n_ == 10);
    a_ = {{1, -2, 1, 0, -1, 1, -2, 2, 0, -2},
     {0, 2, 0, 0, 2, 1, -1, -1, -1, -2},
     {0, 1, 0, -1, 1, -1, 0, -1, 1, -1},
     {-2, -1, 2, -1, 0, 0, 0, 0, 1, 0},
     {1, -2, 0, 1, 0, -2, -1, 0, 2, 2},
     {
      -2,
        -2, 0,
           -2, 0, 1, 1,
                   -2, 1, 1},
     {
      -1,
        -2,
          -1,
           -1,
             -2,
               -1,
                 -2, 1,
                     -1, 2},
     {
      -2, 1, 2,
           -2, 0, 2, 1,
                   -1,
                     -2, 2},
     {0, 1, 0, 1, 1,
               -2, 2, 0, 1, 1},
     {0, 0, 2,
           -1,
             -1, 0,
                 -2, 2,
                     -1,
                       -1}
  };
}

void Matrix::SetVar2() {
    assert(n_ == 20);
    a_ = {{
        -1, 1, 
                -1, 0, 
                -1, 0, 
                -1, 1, 1, 
                -1, 0, 
                -1,  
                -1, 1, 0, 0, 1, 1, 1, 1}, 
    {
        -1, 0, 
                -1, 1, 
                -1, 0, 0, 0, 0, 
                -1, 0, 0, 
                -1, 1, 0, 
                -1, 1, 
                -1,  
                -1, 0}, 
    {1, 0,
                -1, 1, 0, 1, 
                -1,  
                -1,  
                -1, 0, 
                -1,  
                -1, 1, 
                -1, 1, 1, 
                -1, 1, 
                -1, 0}, 
    {
        -1, 1, 0, 0, 
                -1, 0, 0, 
                -1, 0, 
                -1, 1, 1, 
                -1,  
                -1, 1, 1, 
                -1, 1, 
                -1, 0}, 
    {1, 0,
                -1, 0, 0, 
                -1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 
                -1, 0, 0, 1}, 
    {0, 0, 0, 0,
                -1, 1, 1, 0, 0, 1, 1, 0, 
                -1, 0, 1, 1, 0, 1, 0, 0}, 
    {
        -1, 0, 1, 1, 1, 
                -1,  
                -1, 0, 
                -1, 1, 
                -1,  
                -1,  
                -1, 0, 
                -1, 0, 0, 0, 
                -1, 1}, 
    {0, 0,
                -1,  
                -1, 0, 1, 1, 1, 1, 
                -1, 0, 0, 
                -1, 1, 1, 1, 1, 0, 0, 
                -1},
    {0, 0, 1, 1, 0, 1, 1, 0, 1,
                -1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, 
    {0,
                -1, 0, 0, 1, 0, 
                -1, 0, 
                -1, 0, 
                -1, 0, 
                -1, 0, 1, 
                -1, 0, 0, 1, 1}, 
    {1,
                -1, 1, 
                -1,  
                -1,  
                -1, 1, 0, 
                -1, 0, 1, 1, 
                -1, 0, 1, 1, 1, 0, 0, 0}, 
    {0, 1, 0, 0,
                -1, 0, 1, 0, 1, 0, 0, 1, 1, 
                -1,  
                -1, 0, 
                -1, 1, 1, 
                -1},
    {
        -1,  
                -1,  
                -1,  
                -1, 0, 1, 
                -1, 0, 0, 
                -1, 0, 0, 0, 1, 1, 0, 0, 0, 
                -1, 0}, 
    {
        -1, 0, 1, 0, 
                -1, 0, 0, 1, 
                -1, 1, 1, 
                -1, 1, 1, 1, 
                -1, 1, 
                -1,  
                -1, 0}, 
    {1,
                -1, 0, 
                -1,  
                -1, 0, 
                -1,  
                -1, 0, 0, 1, 0, 1, 1, 
                -1, 1, 0, 0, 
                -1, 0}, 
    {
        -1,  
                -1, 1, 0, 
                -1, 1, 1, 
                -1, 1, 0, 0, 
                -1, 1, 
                -1,  
                -1, 0, 0, 1, 1, 1}, 
    {0, 0,
                -1, 0, 0, 0, 0, 
                -1, 1, 1, 0, 
                -1, 1, 
                -1, 0, 0, 0, 
                -1,  
                -1, 1}, 
    {
        -1, 0, 
                -1,  
                -1,  
                -1, 1, 1, 
                -1, 1, 
                -1, 1, 
                -1, 1, 
                -1, 1, 1, 0, 
                -1, 0, 
                -1},
    {
        -1, 0, 1, 0, 0, 0, 0, 
                -1, 1, 
                -1, 1, 
                -1, 0, 
                -1,  
                -1, 1, 0, 1, 0, 0}, 
    {0,
                -1,  
                -1, 1, 
                -1, 1, 
                -1,  
                -1,  
                -1, 1, 1, 
                -1, 0, 
                -1,  
                -1, 0, 1, 0, 
                -1,  
                -1}
};
}