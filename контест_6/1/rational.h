#pragma once
#include <iostream>
#include <stdexcept>
#include <numeric>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("Division by zero") {
  }
};

class Rational {
 public:
  Rational() : numerator_(0), denominator_(1) {
  }

  explicit Rational(int num) : numerator_(num), denominator_(1) {
  }  // NOLINT

  Rational(int num, int denom) {
    if (denom == 0) {
      throw RationalDivisionByZero();
    }
    SetNumerator(num);
    SetDenominator(denom);
    Normalize();
  }

  int GetNumerator() const {
    return numerator_;
  }
  int GetDenominator() const {
    return denominator_;
  }

  void SetNumerator(int num) {
    numerator_ = num;
    Normalize();
  }
  void SetDenominator(int denom) {
    if (denom == 0) {
      throw RationalDivisionByZero();
    }
    denominator_ = denom;
    Normalize();
  }

  Rational& operator+=(const Rational& rhs);
  Rational& operator-=(const Rational& rhs);
  Rational& operator*=(const Rational& rhs);
  Rational& operator/=(const Rational& rhs);

  Rational operator+() const;
  Rational operator-() const;

  Rational& operator++();
  Rational operator++(int);
  Rational& operator--();
  Rational operator--(int);

  bool operator==(const Rational& rhs) const;
  bool operator!=(const Rational& rhs) const;
  bool operator<(const Rational& rhs) const;
  bool operator<=(const Rational& rhs) const;
  bool operator>(const Rational& rhs) const;
  bool operator>=(const Rational& rhs) const;

  friend std::ostream& operator<<(std::ostream& os, const Rational& r);
  friend std::istream& operator>>(std::istream& is, Rational& r);

 private:
  int numerator_;
  int denominator_;

  void Normalize() {
    int gcd_value = std::gcd(numerator_, denominator_);
    numerator_ /= gcd_value;
    denominator_ /= gcd_value;

    if (denominator_ < 0) {
      numerator_ = -numerator_;
      denominator_ = -denominator_;
    }
  }
};
