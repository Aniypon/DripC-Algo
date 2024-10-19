#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <stdexcept>

class RationalDivisionByZero : public std::logic_error {
 public:
  RationalDivisionByZero() : std::logic_error("You cant divide by zero") {
  }
};

class Rational {
 private:
  int32_t numerator_;
  int32_t denominator_;
  void Simplify();

 public:
  Rational();
  Rational(int32_t num);  // NOLINT
  Rational(int32_t num, int32_t denom);
  int32_t GetNumerator() const;
  int32_t GetDenominator() const;
  void SetNumerator(int32_t num);
  void SetDenominator(int32_t denom);
  Rational &operator+=(const Rational &rhs);
  Rational &operator-=(const Rational &rhs);
  Rational &operator*=(const Rational &rhs);
  Rational &operator/=(const Rational &rhs);
  Rational operator+(const Rational &rhs) const;
  Rational operator-(const Rational &rhs) const;
  Rational operator*(const Rational &rhs) const;
  Rational operator/(const Rational &rhs) const;
  Rational operator+() const;
  Rational operator-() const;
  Rational &operator++();
  Rational operator++(int);
  Rational &operator--();
  Rational operator--(int);
  bool operator==(const Rational &rhs) const;
  bool operator!=(const Rational &rhs) const;
  bool operator<(const Rational &rhs) const;
  bool operator<=(const Rational &rhs) const;
  bool operator>(const Rational &rhs) const;
  bool operator>=(const Rational &rhs) const;
  bool operator<(int rhs) const;
  bool operator>(int rhs) const;
  bool operator==(int rhs) const;
  bool operator!=(int rhs) const;
  bool operator<=(int rhs) const;
  bool operator>=(int rhs) const;
  friend bool operator<(int lhs, const Rational &rhs);
  friend bool operator>(int lhs, const Rational &rhs);
  friend bool operator==(int lhs, const Rational &rhs);
  friend bool operator!=(int lhs, const Rational &rhs);
  friend bool operator<=(int lhs, const Rational &rhs);
  friend bool operator>=(int lhs, const Rational &rhs);
  friend std::ostream &operator<<(std::ostream &os, const Rational &r);
  friend std::istream &operator>>(std::istream &is, Rational &r);
};

#endif