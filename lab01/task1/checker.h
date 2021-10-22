#ifndef TASK1_CHECKER_H
#define TASK1_CHECKER_H


#include "quadratic_matrix.h"
#include "vector.h"

class Checker {
public:
    static bool IsCorrect(const QuadraticMatrix& a, const Vector& x, const Vector& b);
};


#endif //TASK1_CHECKER_H
