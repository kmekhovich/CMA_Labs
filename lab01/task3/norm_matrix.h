#ifndef TASK2_NORM_MATRIX_H
#define TASK2_NORM_MATRIX_H

#include <iostream>
#include "vector.h"

class NormMatrix {
public:
    NormMatrix(int n, int m);
    ~NormMatrix();

    Vector operator*(const Vector& rhs) const;

    const double& At(unsigned int i, unsigned int j) const;
    double& At(unsigned int i, unsigned int j);

    friend std::ostream& operator<<(std::ostream& os, const NormMatrix& matrix);

    static NormMatrix GenerateWithRate(int size, double rate);

    void PlusRowWithCof(int rowTo, int rowFrom, double cof);

    NormMatrix(const NormMatrix& rhs);

    void SetOptimized();

private:
    int n_, m_;
    double** data_;

    std::vector<std::pair<int, int>> indexes_;
};


#endif //TASK2_NORM_MATRIX_H
