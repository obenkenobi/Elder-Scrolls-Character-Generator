#ifndef DOMAIN_ROLL_H
#define DOMAIN_ROLL_H
// #define DEBUG

#include "logging.h"
#include "types.h"

namespace Domain {

using RollUint = Types::Uint8;

RollUint rollRandNumber();

class Range {
public:
    bool inRollRangeInclusive(const RollUint num) const;

    Range(const RollUint &start, const RollUint &end);

    Range();

    Types::String toString();

private:
    RollUint start_;
    RollUint end_;
    Types::String stringValue_ = "";
};

template <class T> class RollMatcher {
public:
    RollMatcher(const Range& range, const T matchedItem)
        : range_(range), matchedItem_(matchedItem) {}

    [[nodiscard]] bool match(const RollUint num) const {
        return this->range_.inRollRangeInclusive(num);
    }

    T getMatchedItem() const { return matchedItem_; }

    [[nodiscard]] Range getRange() const { return range_; };

private:
    Range range_;
    T matchedItem_;
};

template <class T> class RollList {
private:
    Types::Vector<RollMatcher<T>> matcherVector_;

public:
    RollList(Types::InitializerList<RollMatcher<T>> initializerList)
        : matcherVector_(Types::Vector<RollMatcher<T>>(std::move(initializerList)))
    {
        // LOG_DEBUG << "Created " + toString();
    }

    T rollForItem() const {
        const RollUint rolledNum = rollRandNumber();
        for (auto i = matcherVector_.begin(); i != matcherVector_.end(); ++i) {
	        if (RollMatcher<T> rollMatcher = *i; rollMatcher.match(rolledNum)) {
                const T item = rollMatcher.getMatchedItem();
                LOG_INFO << Types::String(
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

    [[nodiscard]] Types::String toString() const
    {
	    const Types::String label = matcherVector_.at(0).getMatchedItem().getLabel();
        Types::String listPrintString = "RollList with Label [" + label + "] and contents (";
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
    explicit RollItem(Tid id, Types::String displayName)
        : id_(id)
        , displayName_(std::move(displayName))
    {}

    [[nodiscard]] Types::String getDisplayName() const { return displayName_; }

    Tid getId() const { return id_; }

    [[nodiscard]] virtual Types::String getLabel() const = 0;

protected:
    ~RollItem() = default;
    Tid id_;

private:
    Types::String displayName_;
};

} // namespace Domain

#endif // DOMAIN_ROLL_H
