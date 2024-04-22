#ifndef ROLL_H
#define ROLL_H
// #define DEBUG

#include "aliases.h"

namespace Roll {

using RollUint = Aliases::Uint8;

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

template <class T> class RollList {
private:
    Aliases::Vector<RollMatcher<T>> matcherVector_;

public:
    RollList(Aliases::InitializerList<RollMatcher<T>> initializerList)
        : matcherVector_(Aliases::Vector<RollMatcher<T>>(std::move(initializerList))) {
    }

    T rollForItem() const {
        const RollUint rolledNum = rollRandNumber();
        const size_t highestIdx = matcherVector_.size() - 1;
        for (size_t i = 0; i < highestIdx; i++) {
            RollMatcher<T> roll_matcher = matcherVector_.at(i);
            if (roll_matcher.match(rolledNum)) {
                const T item = roll_matcher.getMatchedItem();
                return item;
            }
        }
        const T lastItem = this->matcherVector_[highestIdx].getMatchedItem();
        return lastItem;
    }
};

template <class Tid> class RollItem {
public:
    explicit RollItem(Tid id, Aliases::String display_name)
        : id_(id), displayName_(std::move(display_name)) {}

    Aliases::String getDisplayName() const { return displayName_; }

    Tid getId() const { return id_; }

    Aliases::String createLabeledName(Aliases::String label) const {
        return label + ": " + displayName_;
    }

protected:
    Tid id_;

private:
    Aliases::String displayName_;
};

} // namespace Roll

#endif // ROLL_H
