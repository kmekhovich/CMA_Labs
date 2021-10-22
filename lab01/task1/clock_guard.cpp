#include <ostream>
#include "clock_guard.h"

ClockGuard::ClockGuard(std::ostream *os, std::string title) : os_(os), title_(std::move(title)) {
    clock_ = clock();
}

ClockGuard::~ClockGuard() {
    (*os_) << "Process ended : " << title_ << " "
        << (double)(clock() - clock_) / CLOCKS_PER_SEC * 1000 << " msecs" << "\n";
}
