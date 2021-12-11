#ifndef TASK1_LDLT_HELPER_H
#define TASK1_LDLT_HELPER_H


#include "vector.h"
#include "quadratic_matrix.h"
#include "symmetric_matrix.h"

class LDLTHelper {
public:
    static void MakeLDLT(const SymmetricMatrix& src, QuadraticMatrix* dest);
    static Vector Solve(const QuadraticMatrix& ldlt, const Vector& b);
};


#endif //TASK1_LDLT_HELPER_H
