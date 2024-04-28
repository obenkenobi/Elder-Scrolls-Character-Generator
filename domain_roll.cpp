#include "domain_roll.h"
#include <random>

namespace Domain {

std::uniform_int_distribution<> rollDistribution{1, 100}; // set min and maximum
std::random_device seed;
std::mt19937 gen{seed()};

RollUint rollRandNumber()
{
	const int rollNum = rollDistribution(gen);
    return static_cast<RollUint>(rollNum);
}

bool Range::inRollRangeInclusive(const RollUint num) const
{
    return start_ <= num && num <= end_;
}

Range::Range(const RollUint &start, const RollUint &end)
    : start_(start)
    , end_(end)
{}

Range::Range()
    : start_(-1)
    , end_(-1)
{}

Types::String Range::toString()
{
    if (stringValue_.isEmpty()) {
        stringValue_ = Types::String("%1-%2").arg(start_).arg(end_);
    }
    return stringValue_;
}

} // namespace Roll
