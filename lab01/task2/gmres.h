#ifndef TASK2_GMRES_H
#define TASK2_GMRES_H

#include <vector>

#include "vector.h"
#include "norm_matrix.h"
#include "matrix.h"

namespace GMRES {
    void Solve(const Matrix &A, Vector &x, const Vector &b, int &max_iter, double eps);
}

#endif //TASK2_GMRES_H
