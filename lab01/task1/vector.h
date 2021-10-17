#ifndef TASK1_VECTOR_H
#define TASK1_VECTOR_H


#include <ostream>

class Vector {
public:
    explicit Vector(int n);
    ~Vector();

    void LoadRandomValues(double l = -1, double r = 1);

    int GetSide() const;

    const double* Get() const;

    double& At(int i);
    const double& At(int i) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);

private:
    int n_;
    double* fields_;
};


#endif //TASK1_VECTOR_H
