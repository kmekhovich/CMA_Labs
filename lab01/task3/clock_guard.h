#ifndef TASK1_CLOCK_GUARD_H
#define TASK1_CLOCK_GUARD_H


#include <string>

class ClockGuard {
public:
    ClockGuard(std::ostream* os, std::string title, std::vector<double>* out);
    ~ClockGuard();

private:
    std::ostream* os_;
    std::string title_;
    clock_t clock_;
    std::vector<double>* out_;
};


#endif //TASK1_CLOCK_GUARD_H
