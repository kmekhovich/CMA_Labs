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
            ans += (*begin).real() * (*begin).real();
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

    template <typename T>
    std::ostream &operator<<(std::ostream &os, const std::vector<T> &rhs) {
        for (const auto &it: rhs) {
            os << it << " ";
        }
        os << "\n";
        return os;
    }

    double Dot(const std::vector<std::complex<double>>& lhs, const std::vector<std::complex<double>>& rhs) {
        std::complex<double> res = 0;
        for (int i = 0; i < lhs.size(); i++) {
            res += lhs[i] * rhs[i];
        }
        return res.real();
    }
}

Matrix::Matrix(int n, bool random) : n_(n), m_(n), a_(n_, std::vector<std::complex<double>>(m_, 0)) {
    if (random) {
        static std::mt19937 rng(43);
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

std::vector<std::pair<std::vector<std::complex<double>>, std::complex<double>>> Matrix::PowerMethod(int& iters, double eps) const {
    std::complex<double> lambda_1 = 0, lambda_2 = 0;
    std::complex<double> prev_lambda_1 = 0, prev_lambda_2 = 0;
    double lambda = 0;
    std::vector<std::complex<double>> u(n_, 0);
    u[0] = 1;
    std::vector<std::complex<double>> au = *this * u;
    std::vector<std::complex<double>> aulu = au;
    for (int i = 0; i < aulu.size(); i++) {
        aulu[i] -= lambda * u[i];
    }
    iters = 1;
    while (EuclidNorm(aulu.begin(), aulu.end()) > eps) {
        std::complex<double> normau = EuclidNorm(au.begin(), au.end());
        for (int i = 0; i < n_; i++) {
            u[i] = au[i] / normau;
        }
        au = *this * u;

        std::vector<std::complex<double>> ucp = u;
        std::vector<std::complex<double>> aucp = au;
        std::vector<std::complex<double>> aau = *this * au;
        std::vector<std::complex<double>> aaucp = aau;

        std::vector<std::vector<std::complex<double>>> w(2);
        for (int k = 0; k < 2; k++) {
            std::vector<std::complex<double>> vec(n_, 0);
            {
                int it = k;
                std::for_each(vec.begin() + k, vec.end(), [k, &ucp, &aucp, &it](std::complex<double> &x) {
                    if (k == 0) {
                        x = ucp[it++];
                    } else {
                        x = aucp[it++];
                    }
                });
            }
            double norm = EuclidNorm(vec.begin(), vec.end());
            double a_new_k = norm * (vec[k].real() > 0 ? -1 : +1);
            w[k] = std::vector<std::complex<double>>(vec.begin(), vec.end());
            w[k][k] -= a_new_k;
            double eu = EuclidNorm(w[k].begin(), w[k].end());
            std::for_each(w[k].begin(), w[k].end(), [&eu](std::complex<double> &x) {
                x /= eu;
            });
            for (int i = k; i < 2; i++) {
                std::complex<double> scalar = 0;
                for (int j = k; j < n_; j++) {
                    scalar += (i == 0 ? ucp[j] : aucp[j]) * w[k][j];
                }
                for (int j = k; j < n_; j++) {
                    (i == 0 ? ucp[j] : aucp[j]) -= 2. * scalar * w[k][j];
                }
            }
            std::complex<double> scalar2 = 0;
            for (int j = k; j < n_; j++) {
                scalar2 += aaucp[j] * w[k][j];
            }
            for (int j = k; j < n_; j++) {
                aaucp[j] -= 2. * scalar2 * w[k][j];
            }
        }

        std::complex<double> a = 1, b, c;
        b = -aaucp[1] / aucp[1];
        c = -aaucp[0] - aucp[0] * b;
        c /= ucp[0];

        std::complex<double> sqrtd = std::sqrt(std::complex<double>(b * b - a * c * 4.));
        lambda_1 = (-b + sqrtd) / (2. * a);
        lambda_2 = (-b - sqrtd) / (2. * a);

        std::vector<std::complex<double>> u1(n_);
        std::vector<std::complex<double>> u2(n_);
        for (int i = 0; i < n_; i++) {
            u1[i] = (au[i] - lambda_2 * u[i]) / (lambda_1 - lambda_2);
            u2[i] = (au[i] - lambda_1 * u[i]) / (lambda_2 - lambda_1);
        }

        if (abs(lambda_1 - prev_lambda_1) < eps && abs(lambda_2 - prev_lambda_2) < eps) {
            return {{u1, lambda_1}, {u2, lambda_2}};
        }

        lambda = Dot(u, au);
        aulu = au;
        for (int i = 0; i < aulu.size(); i++) {
            aulu[i] -= lambda * u[i];
        }
        prev_lambda_1 = lambda_1;
        prev_lambda_2 = lambda_2;
        iters++;
    }
    return {{u, lambda}};
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

std::vector<std::complex<double>> operator*(const Matrix &lhs, const std::vector<double> &rhs) {
    std::vector<std::complex<double>> res(lhs.n_, 0);
    for (int i = 0; i < lhs.n_; i++) {
        for (int j = 0; j < lhs.m_; j++) {
            res[i] += lhs.a_[i][j] * rhs[j];
        }
    }
    return res;
}

void Matrix::SetVar3() {
    assert(n_ == 3);
    a_ = {{15.000000,  12.000000,  -6.000000},
          {-16.000000, -13.000000,   6.000000},
          {4.000000,   4.000000,  -3.000000}};
}

void Matrix::SetVar4() {
    assert(n_ == 3);
    a_ = {{-2, 2, -3},
          {-9, -7, -5},
          {-5, 2, 2}};
}

std::vector<std::complex<double>> operator*(const Matrix &lhs, const std::vector<std::complex<double>> &rhs) {
    std::vector<std::complex<double>> res(lhs.n_, 0);
    for (int i = 0; i < lhs.n_; i++) {
        for (int j = 0; j < lhs.m_; j++) {
            res[i] += lhs.a_[i][j] * rhs[j];
        }
    }
    return res;
}
