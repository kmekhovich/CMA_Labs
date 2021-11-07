#include "clock_guard.h"
#include <ostream>
#include <vector>

ClockGuard::ClockGuard(std::ostream *os, std::string title, std::vector<double>* out)
    : os_(os), title_(std::move(title)), out_(out) {
    clock_ = clock();
}

ClockGuard::~ClockGuard() {
    double msecs = (double)(clock() - clock_) / CLOCKS_PER_SEC * 1000;
    (*os_) << "Process ended : " << title_ << " "
        << msecs << " msecs" << "\n";
    out_->push_back(msecs);
}
