#ifndef TASK1_QUADRATIC_MATRIX_H
#define TASK1_QUADRATIC_MATRIX_H


#include <ostream>

class QuadraticMatrix {
public:
    explicit QuadraticMatrix(int n);
    ~QuadraticMatrix();

    int GetSide() const;

    virtual double& At(int i, int j);
    virtual const double& At(int i, int j) const;

    friend std::ostream& operator<<(std::ostream& os, const QuadraticMatrix& matrix);

protected:
    QuadraticMatrix() = default;

    int n_{0};
    double** fields_{nullptr};
};


#endif //TASK1_QUADRATIC_MATRIX_H
