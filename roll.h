#ifndef ROLL_H
#define ROLL_H
// #define DEBUG

#include "aliases.h"
#include "logging.h"

namespace Roll {

using RollUint = Aliases::Uint8;

RollUint rollRandNumber();

class Range {
public:
    bool inRollRangeInclusive(const RollUint num) const;

    Range(const RollUint &start, const RollUint &end);

    Range();

    Aliases::String toString();

private:
    RollUint start_;
    RollUint end_;
    Aliases::String stringValue_ = "";
};

template <class T> class RollMatcher {
public:
    RollMatcher(const Range range, const T matched_item)
        : range_(range), matchedItem_(matched_item) {}

    bool match(const RollUint num) const {
        return this->range_.inRollRangeInclusive(num);
    }

    T getMatchedItem() const { return matchedItem_; }

    Range getRange() const { return range_; };

private:
    Range range_;
    T matchedItem_;
};

template <class T> class RollList {
private:
    Aliases::Vector<RollMatcher<T>> matcherVector_;

public:
    RollList(Aliases::InitializerList<RollMatcher<T>> initializerList)
        : matcherVector_(Aliases::Vector<RollMatcher<T>>(std::move(initializerList)))
    {
        // LOG_DEBUG << "Created " + toString();
    }

    T rollForItem() const {
        const RollUint rolledNum = rollRandNumber();
        for (auto i = matcherVector_.begin(); i != matcherVector_.end(); i++) {
            RollMatcher<T> rollMatcher = *i;
            if (rollMatcher.match(rolledNum)) {
                const T item = rollMatcher.getMatchedItem();
                LOG_INFO << Aliases::String(
                                "Rolled [%1] with result [%2] with roll number [%3] in range %4")
                                .arg(item.getLabel())
                                .arg(item.getDisplayName())
                                .arg(rolledNum)
                                .arg(rollMatcher.getRange().toString());
                return item;
            }
        }
        static const size_t highestIdx = matcherVector_.size() - 1;
        static const T lastItem = this->matcherVector_[highestIdx].getMatchedItem();
        return lastItem;
    }

    Aliases::String toString()
    {
        Aliases::String label = matcherVector_.at(0).getMatchedItem().getLabel();
        Aliases::String listPrintString = "RollList with Label [" + label + "] and contents (";
        for (auto i = matcherVector_.begin(); i != matcherVector_.end(); i++) {
            if (i != matcherVector_.begin()) {
                listPrintString += ", ";
            }
            listPrintString += (*i).getMatchedItem().getDisplayName();
        }
        listPrintString += ")";
        return listPrintString;
    }
};

template<class Tid>
class RollItem
{
public:
    explicit RollItem(Tid id, Aliases::String display_name)
        : id_(id), displayName_(std::move(display_name)) {}

    Aliases::String getDisplayName() const { return displayName_; }

    Tid getId() const { return id_; }

    virtual Aliases::String getLabel() const = 0;

protected:
    Tid id_;

private:
    Aliases::String displayName_;
};

} // namespace Roll

#endif // ROLL_H
