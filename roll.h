#ifndef ROLL_H
#define ROLL_H
// #define DEBUG

#include "types_aliases.h"
#include <array>
#include <stdexcept>
#include <vector>

namespace Roll {

using RollUint = TAS::Uint8;

RollUint rollRandNumber();

class Range {
public:
    bool inRollRangeInclusive(const RollUint num) const;

    Range(const RollUint &start, const RollUint &end);

    Range() : start_(-1), end_(-1) {}

private:
    RollUint start_;
    RollUint end_;
};

template <class T> class RollMatcher {
public:
    RollMatcher(const Range range, const T matched_item)
        : range_(range), matchedItem_(matched_item) {}

    bool match(const RollUint num) const {
        return this->range_.inRollRangeInclusive(num);
    }

    T getMatchedItem() const { return matchedItem_; }

private:
    Range range_;
    T matchedItem_;
};

template <class T, class TList> class RollList {
protected:
    TList matcherList_;
    size_t size_;

    RollList(TList matcher_list, const size_t &size)
        : matcherList_(std::move(matcher_list)), size_(size) {
        if (size <= 0) {
            throw std::logic_error(
                "matcher_list must not be empty (i.e. size must be greater than 0)");
        }
    }

public:
    T rollForItem() const {
        const RollUint rolledNum = rollRandNumber();
        const size_t highestIdx = size_ - 1;
        for (size_t i = 0; i < highestIdx; i++) {
            RollMatcher<T> roll_matcher = this->matcherList_[i];
            if (roll_matcher.match(rolledNum)) {
                const T item = roll_matcher.getMatchedItem();
                return item;
            }
        }
        const T lastItem = this->matcherList_[highestIdx].getMatchedItem();
        return lastItem;
    }
};

template <class T>
class RollVector : public RollList<T, std::vector<RollMatcher<T>>> {
public:
    explicit RollVector(std::vector<RollMatcher<T>> matcher_list)
        : RollList<T, std::vector<RollMatcher<T>>>(matcher_list,
                                                   matcher_list.size()) {}
};

template <class T, size_t FixedSize>
class RollArray : public RollList<T, std::array<RollMatcher<T>, FixedSize>> {
public:
    explicit RollArray(std::array<RollMatcher<T>, FixedSize> matcher_list)
        : RollList<T, std::array<RollMatcher<T>, FixedSize>>(matcher_list,
                                                             FixedSize) {}
};

template <class Tid> class RollItem {
public:
    explicit RollItem(Tid id, TAS::String display_name)
        : id_(id), display_name_(std::move(display_name)) {}

    TAS::String getDisplayName() const { return display_name_; }

    Tid getId() const { return id_; }

    TAS::String createLabeledName(TAS::String label) const {
        return label + ": " + display_name_;
    }

protected:
    Tid id_;

private:
    TAS::String display_name_;
};

} // namespace Roll

#endif // ROLL_H
