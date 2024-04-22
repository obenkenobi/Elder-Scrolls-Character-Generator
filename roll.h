#ifndef ROLL_H
#define ROLL_H
// #define DEBUG

#include <array>
#include <stdexcept>
#include <vector>
#include "types_aliases.h"
#include <random>

namespace roll {

using r_uint_t = type_aliases::a_uint8_t;

std::uniform_int_distribution<> roll_distribution{1, 100}; // set min and maximum
std::random_device seed;
std::mt19937 gen{seed()};

r_uint_t roll_rand_number() {
    int roll_num = roll_distribution(gen);
    return static_cast<r_uint_t>(roll_num);
}

class range_t {
public:
    bool in_roll_range_inclusive(const r_uint_t num) const {
        return start_ <= num && num <= end_;
    }

    range_t(const r_uint_t &start, const r_uint_t &end)
        : start_(start), end_(end) {}

    range_t() : start_(-1), end_(-1) {}

private:
    r_uint_t start_;
    r_uint_t end_;
};

template <class T> class roll_matcher {
public:
    roll_matcher(const range_t range, const T matched_item)
        : range_(range), matched_item_(matched_item) {}

    bool match(const r_uint_t num) const {
        return this->range_.in_roll_range_inclusive(num);
    }

    T get_matched_item() const { return matched_item_; }

private:
    range_t range_;
    T matched_item_;
};

template <class T, class TList> class roll_list_t {
protected:
    TList matcher_list_;
    size_t size_;

    roll_list_t(TList matcher_list, const size_t &size)
        : matcher_list_(std::move(matcher_list)), size_(size) {
        if (size <= 0) {
            throw std::logic_error(
                "matcher_list must not be empty (i.e. size must be greater than 0)");
        }
    }

public:
    T roll_for_item() const {
        const r_uint_t rolled_num = roll_rand_number();
        const size_t highest_idx = size_ - 1;
        for (size_t i = 0; i < highest_idx; i++) {
            roll_matcher<T> roll_matcher = this->matcher_list_[i];
            if (roll_matcher.match(rolled_num)) {
                const T item = roll_matcher.get_matched_item();
                return item;
            }
        }
        const T last_item = this->matcher_list_[highest_idx].get_matched_item();
        return last_item;
    }
};

template <class T>
class roll_vector_t : public roll_list_t<T, std::vector<roll_matcher<T>>> {
public:
    explicit roll_vector_t(std::vector<roll_matcher<T>> matcher_list)
        : roll_list_t<T, std::vector<roll_matcher<T>>>(matcher_list,
                                                       matcher_list.size()) {}
};

template <class T, size_t FixedSize>
class roll_array_t
    : public roll_list_t<T, std::array<roll_matcher<T>, FixedSize>> {
public:
    explicit roll_array_t(std::array<roll_matcher<T>, FixedSize> matcher_list)
        : roll_list_t<T, std::array<roll_matcher<T>, FixedSize>>(matcher_list,
                                                                 FixedSize) {}
};

template <class Tid> class roll_item_t {
public:
    explicit roll_item_t(Tid id, type_aliases::string_t display_name)
        : id_(id), display_name_(std::move(display_name)) {}

    type_aliases::string_t get_display_name() const { return display_name_; }

    Tid get_id() const { return id_; }

    type_aliases::string_t create_labeled_name(type_aliases::string_t label) const {
        return label + ": " + display_name_;
    }

protected:
    Tid id_;

private:
    type_aliases::string_t display_name_;
};
} // namespace roll

#endif // ROLL_H
