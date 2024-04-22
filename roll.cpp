#include "roll.h"
#include <random>

std::uniform_int_distribution<> roll_distribution{1, 100}; // set min and maximum
std::random_device seed;
std::mt19937 gen{seed()};

Roll::RollUint Roll::rollRandNumber() {
    int roll_num = roll_distribution(gen);
    return static_cast<RollUint>(roll_num);
}

bool Roll::Range::inRollRangeInclusive(const RollUint num) const {
    return start_ <= num && num <= end_;
}

Roll::Range::Range(const RollUint &start, const RollUint &end)
    : start_(start), end_(end) {}
