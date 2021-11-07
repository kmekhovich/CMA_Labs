//
// Created by Kanstantsin Mekhavich on 28.10.2021.
//

#ifndef TASK2_VECTOR_H
#define TASK2_VECTOR_H

#include <iostream>

class Vector {
public:
    explicit Vector(unsigned int n);
    Vector();

    void SetOnes();
    ~Vector();
    const double& At(unsigned int i) const;
    double& At(unsigned int i);
    Vector(const Vector& rhs);

    double DotProduct(const Vector& rhs) const;
    Vector operator*(double x) const;

    double GetLength() const;

    int GetSize() const;

    friend Vector operator-(const Vector& lhs, const Vector& rhs);

    Vector& operator-=(const Vector& rhs);
    Vector& operator+=(const Vector& rhs);
    Vector& operator=(const Vector& rhs);
    Vector& operator=(double value);

    friend std::ostream& operator<<(std::ostream& os, const Vector& rhs);

private:
    double* data_;
    unsigned int n_;
};


#endif //TASK2_VECTOR_H
