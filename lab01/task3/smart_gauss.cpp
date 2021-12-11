#include <vector>
#include "smart_gauss.h"

namespace SmartGauss {
    void Solve(const NormMatrix &A, Vector &x, const Vector &b, double eps) {
        NormMatrix mtr(A);
        Vector bb(b);
        int n = b.GetSize();
        x = Vector(n);
        std::vector<int> queue(n);
        std::vector<int> in_queue(n, 0);
        for (int j = 0; j < n; j++) {
            int maxi = -1;
            for (int i = 0; i < n; i++) {
                if (in_queue[i]) {
                    continue;
                }
                if (maxi == -1 || std::abs(mtr.At(i, j)) > std::abs(mtr.At(maxi, j))) {
                    maxi = i;
                }
            }
            if (maxi == -1 || std::abs(mtr.At(maxi, j)) < eps) {
                throw std::runtime_error("bug");
            }
            in_queue[maxi] = 1;
            for (int i = 0; i < n; i++) {
                if (i == maxi) {
                    continue;
                }
                if (std::abs(mtr.At(i, j)) < eps) {
                    continue;
                }
                double cof = -mtr.At(i, j) / mtr.At(maxi, j);
                mtr.PlusRowWithCof(i, maxi, cof);
                bb.At(i) += cof * bb.At(maxi);
            }
            queue[j] = maxi;
        }
        for (int i = n - 1; i >= 0; i--) {
            int row = queue[i];
            x.At(i) = bb.At(row) / mtr.At(row, i);
        }
    }
}
