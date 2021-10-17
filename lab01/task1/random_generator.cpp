#include "random_generator.h"

#include <random>

double RandomGenerator::GenerateDouble(double l, double r) {
    if (l > r) {
        throw std::invalid_argument("Invalid l and r");
    }
    static std::mt19937 rng(42);
    static std::uniform_real_distribution<double> uni(l, r);
    return uni(rng);
}

void RandomGenerator::GenerateDoubleArray(double* dest, int count, double l, double r) {
    for (int i = 0; i < count; i++) {
        dest[i] = GenerateDouble(l, r);
    }
}
