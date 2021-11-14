#include "gmres.h"

namespace {
    void Update(Vector &x, int k, const NormMatrix &h, const Vector &s, const std::vector<Vector>& Q) {
        // сделаем обратный ход метода гаусса
        x = Vector(Q.front().GetSize());
        Vector y(s);
        for (int i = k; i >= 0; i--) {
            y.At(i) /= h.At(i, i);
            for (int j = i - 1; j >= 0; j--) {
                y.At(j) -= h.At(j, i) * y.At(i);
            }
        }

        // теперь чтобы конвертнуть из y в x нужно произвести преобразование Q
        for (int j = 0; j <= k; j++) {
            x += Q[j] * y.At(j);
        }
    }

    void ApplyPlaneRotation(double& dx, double& dy, double cs, double sn) {
        // применили матрицу поворота
        // cs  sn
        // -sn cs
        double temp = cs * dx + sn * dy;
        dy = -sn * dx + cs * dy;
        dx = temp;
    }

    void GeneratePlaneRotation(double dx, double dy, double& cs, double& sn) {
        // по двум значениям построили такой sn и cs
        // чтобы new_dy = -sn * dx + cs * dy = 0
        if (std::abs(dy) > std::abs(dx)) {
            double temp = dx / dy;
            sn = 1.0 / sqrt(1.0 + temp * temp);
            cs = temp * sn;
        } else {
            double temp = dy / dx;
            cs = 1.0 / sqrt(1.0 + temp * temp);
            sn = temp * cs;
        }
    }
}  // namespace

namespace GMRES {
    void Solve(const Matrix& A, Vector& x, const Vector& b, int& max_iter, double eps) {
        int m = max_iter;
        double blen = b.GetLength();
        NormMatrix H(m + 1, m);

        Vector s(m + 1);
        s.At(0) = blen;
        // s - это короче R^T * d_k, то есть как будто
        // взяли вектор (||b||, 0, 0, ...) и применили к нему все преобразования вращенияы

        Vector cs(m);
        Vector sn(m);
        // cs и sn - это типо матрицы поворота записанные в двух векторах так как по сути значения
        // там по диагонали и их как раз 2 * m

        std::vector<Vector> Q(m + 1);

        Q[0] = b * (1.0 / blen);
        // первым вектором берем b/||b||

        for (int i = 0; i < m && i < max_iter; i++) {
            // алгос г-на Арнольди
            Vector z = A * Q[i];
            int k;
            for (k = 0; k <= i; k++) {
                H.At(k, i) = z.DotProduct(Q[k]);
                z -= Q[k] * H.At(k, i);
            }
            H.At(i + 1, i) = z.GetLength();
            Q[i + 1] = z * (1.0 / H.At(i + 1, i));

            // костыль имени Арнольди
            bool failed = std::abs(H.At(i + 1, i)) < eps;

            // повернем весь столбец согласно прошлым преобразованиям
            for (k = 0; k < i; k++) {
                ApplyPlaneRotation(H.At(k, i), H.At(k + 1, i), cs.At(k), sn.At(k));
            }

            // получим новое преобразование, которое сделает нулем H.At(i + 1, i)
            GeneratePlaneRotation(H.At(i, i), H.At(i + 1, i), cs.At(i), sn.At(i));
            // поворачиваем новым преобразованием
            ApplyPlaneRotation(H.At(i, i), H.At(i + 1, i), cs.At(i), sn.At(i));
            // обновляем R^T * d_i+1 (то есть s)
            ApplyPlaneRotation(s.At(i), s.At(i + 1), cs.At(i), sn.At(i));

            // применение костыля Арнольди после всех поворотов i-того шага
            // решение в больше раз улучшить чем наш eps уже не получится, а как раз нам это и требуется
            if (failed) {
                Update(x, i, H, s, Q);
                max_iter = i + 1;
                return;
            }
        }
        // все прошли максы итераций значит возвращаем ответ че посчитали
        Update(x, max_iter - 1, H, s, Q);
    }
}  // GMRES namespace
