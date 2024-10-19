#ifndef RANGE_H
#define RANGE_H

#include <iostream>

class RangeIterator {
 public:
  RangeIterator(int current, int step) : current_(current), step_(step) {
  }

  int operator*() const {
    return current_;
  }

  RangeIterator& operator++() {
    current_ += step_;
    return *this;
  }

  bool operator!=(const RangeIterator& other) const {
    return step_ > 0 ? current_ < other.current_ : current_ > other.current_;
  }

 private:
  int current_;
  int step_;
};

class Range {
 public:
  explicit Range(int end) : begin_(0), end_(end), step_(1) {
  }
  Range(int begin, int end) : begin_(begin), end_(end), step_(1) {
  }
  Range(int begin, int end, int step) : begin_(begin), end_(end), step_(step) {
  }

  RangeIterator Begin() const {
    return {begin_, step_};
  }

  RangeIterator End() const {
    return {end_, step_};
  }

 private:
  int begin_;
  int end_;
  int step_;
};

#endif  // RANGE_H