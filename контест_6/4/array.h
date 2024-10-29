#ifndef ARRAY_H
#define ARRAY_H

#include <cstdint>
#include <stdexcept>

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {}
};

template <class T, size_t N>
class Array {
 public:
  T data[N];

  const T &operator[](size_t index) const {
    return data[index];
  }

  T &operator[](size_t index) {
    return data[index];
  }

  T &At(size_t index) {
    if (index < N) {
      return data[index];
    }
    throw ArrayOutOfRange{};
  }

  T &Front() {
    return data[0];
  }

  const T &Front() const {
    return data[0];
  }

  T &Back() {
    return data[N - 1];
  }

  const T &Back() const {
    return data[N - 1];
  }

  T *Data() {
    return data;
  }

  const T *Data() const {
    return data;
  }

  size_t Size() const {
    return N;
  }

  bool Empty() const {
    return N == 0;
  }

  void Fill(const T &value) {
    for (size_t i = 0; i < N; i++) {
      data[i] = value;
    }
  }

  void Swap(Array<T, N> &other) {
    std::swap(data, other.data);
  }
};

#endif  // ARRAY_H
