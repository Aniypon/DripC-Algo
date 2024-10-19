#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
#include <cstddef>

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("Array index out of range") {
  }
};

template <typename T, std::size_t N>
class Array {
 public:
  T data[N];

  T& operator[](std::size_t idx) {
    return data[idx];
  }

  const T& operator[](std::size_t idx) const {
    return data[idx];
  }

  T& At(std::size_t idx) {
    if (idx >= N) {
      throw ArrayOutOfRange();
    }
    return data[idx];
  }

  const T& At(std::size_t idx) const {
    if (idx >= N) {
      throw ArrayOutOfRange();
    }
    return data[idx];
  }

  T& Front() {
    return data[0];
  }

  const T& Front() const {
    return data[0];
  }

  T& Back() {
    return data[N - 1];
  }

  const T& Back() const {
    return data[N - 1];
  }

  T* Data() {
    return data;
  }

  const T* Data() const {
    return data;
  }

  std::size_t Size() const {
    return N;
  }

  bool Empty() const {
    return N == 0;
  }

  void Fill(const T& value) {
    for (std::size_t i = 0; i < N; ++i) {
      data[i] = value;
    }
  }

  void Swap(Array<T, N>& other) {
    for (std::size_t i = 0; i < N; ++i) {
      std::swap(data[i], other.data[i]);
    }
  }
};

#endif  // ARRAY_H