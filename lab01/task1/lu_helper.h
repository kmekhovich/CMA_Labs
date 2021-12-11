#ifndef TASK1_LU_HELPER_H
#define TASK1_LU_HELPER_H


#include "quadratic_matrix.h"
#include "symmetric_matrix.h"
#include "vector.h"

class LUHelper {
public:
    static void MakeLU(const SymmetricMatrix& src, QuadraticMatrix* dest);
    static Vector Solve(const QuadraticMatrix& lu, const Vector& b);
};


#endif //TASK1_LU_HELPER_H
