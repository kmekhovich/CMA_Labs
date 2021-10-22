#include "random_generator.h"

#include <random>

namespace {

unsigned long x = 123456789, y = 362436069, z = 521288629;

unsigned long xorshf96() { // pseudo-random with period 2^96-1
    unsigned long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;

    return z % 1000;
}

}  // namespace

//#define USE_FAST_RANDOM true
double RandomGenerator::GenerateDouble(double l, double r) {
    if (l > r) {
        throw std::invalid_argument("Invalid l and r");
    }
#ifdef USE_FAST_RANDOM
    return static_cast<double>(xorshf96());
#else
    static std::mt19937 rng(42);
    static std::uniform_real_distribution<double> uni(l, r);
    return uni(rng);
#endif
}

void RandomGenerator::GenerateDoubleArray(double* dest, int count, double l, double r) {
    for (int i = 0; i < count; i++) {
        dest[i] = GenerateDouble(l, r);
    }
}
