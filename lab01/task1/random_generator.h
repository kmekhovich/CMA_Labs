#ifndef TASK1_RANDOM_GENERATOR_H
#define TASK1_RANDOM_GENERATOR_H


class RandomGenerator {
public:
    static double GenerateDouble(double l = -1, double r = 1);
    static void GenerateDoubleArray(double* dest, int count, double l = -1, double r = 1);
};


#endif //TASK1_RANDOM_GENERATOR_H
