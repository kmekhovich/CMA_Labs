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

void Matrix::MakeHessenByReflectionMethod() {
    for (int k = 1; k < m_ - 1; k++) {
        {
            bool fail = false;
            for (int i = k + 1; i < n_; i++) {
                if (std::abs(a_[i][k - 1]) > 1e-6) {
                    fail = true;
                    break;
                }
            }
            if (!fail) {
                continue;
            }
        }
        std::vector<double> vec(n_, 0);
        {
            int it = k;
            std::for_each(vec.begin() + k, vec.end(), [this, k, &it](double &x) {
                x = a_[it++][k - 1];
            });
        }
        double norm = EuclidNorm(vec.begin(), vec.end());
        double a_new_k = norm * (vec[k] > 0 ? -1 : +1);
        std::vector<double> w(vec.begin(), vec.end());
        w[k] -= a_new_k;
        double eu = EuclidNorm(w.begin(), w.end());
        std::for_each(w.begin(), w.end(), [&eu](double &x) {
            x /= eu;
        });
        for (int i = k - 1; i < m_; i++) {
            double scalar = 0;
            for (int j = k; j < n_; j++) {
                scalar += a_[j][i] * w[j];
            }
            for (int j = k; j < n_; j++) {
                a_[j][i] -= 2 * scalar * w[j];
            }
        }
        for (int i = 0; i < n_; i++) {
            double scalar = 0;
            for (int j = k; j < m_; j++) {
                scalar += a_[i][j] * w[j];
            }
            for (int j = k; j < m_; j++) {
                a_[i][j] -= 2 * scalar * w[j];
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

std::vector<std::complex<double>> Matrix::DoQRAlgorithm(double eps) {
    std::vector<std::complex<double>> res;
    res.reserve(2 * n_);


    for (int cnt = 1;; cnt++) {
        std::vector<double> cs(n_, 0.);
        std::vector<double> sn(n_, 0.);

        for (int i = 0; i < n_; i++) {
            for (int k = 0; k < i; k++) {
                ApplyPlaneRotation(a_[k][i], a_[k + 1][i], cs[k], sn[k]);
            }
            if (i == n_ - 1) {
                continue;
            }
            GeneratePlaneRotation(a_[i][i], a_[i + 1][i], cs[i], sn[i]);
            ApplyPlaneRotation(a_[i][i], a_[i + 1][i], cs[i], sn[i]);
        }

        for (int i = 0; i < n_ - 1; i++) {
            for (int j = 0; j <= i + 1; j++) {
                ApplyPlaneRotation(a_[j][i], a_[j][i + 1], cs[i], sn[i]);
            }
        }

        res.clear();

        bool lastsq = false;
        bool fail = false;
        for (int i = 0; i < n_; i++) {
            if (lastsq) {
                if (i == n_ - 1) {
                    continue;
                }
                if (std::abs(a_[i + 1][i]) > eps) {
                    fail = true;
                    break;
                }
                lastsq = false;
                continue;
            }
            if (i != n_ - 1 && std::abs(a_[i + 1][i]) > eps) {
                double a = 1;
                double b = (-a_[i][i] - a_[i + 1][i + 1]);
                double c = -a_[i][i + 1] * a_[i + 1][i] + a_[i][i] * a_[i + 1][i + 1];
                std::complex<double> d = b * b - 4 * a * c;
                res.emplace_back((-b + std::sqrt(d)) / (2. * a));
                res.emplace_back((-b - std::sqrt(d)) / (2. * a));
                lastsq = true;
            } else {
                res.emplace_back(a_[i][i]);
            }
        }
        if (fail) {
            continue;
        }

        if (res.size() == n_) {
            std::cout << cnt << " iter" << "\n";
            return res;
        }
    }
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
