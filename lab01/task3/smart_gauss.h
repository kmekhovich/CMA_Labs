//
// Created by Kanstantsin Mekhavich on 06.11.2021.
//

#ifndef TASK3_SMART_GAUSS_H
#define TASK3_SMART_GAUSS_H
#include "norm_matrix.h"
#include "vector.h"

namespace SmartGauss {
    void Solve(const NormMatrix &A, Vector &x, const Vector &b, double eps);
}


#endif //TASK3_SMART_GAUSS_H
