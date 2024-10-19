#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <stdexcept>
#include <numeric>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("Division by zero") {
  }
};

class Rational {
 private:
  int numerator;
  int denominator;

  void Reduce();

 public:
  Rational();
  Rational(int num);  // NOLINT
  Rational(int num, int denom);

  int GetNumerator() const;
  int GetDenominator() const;
  void SetNumerator(int num);
  void SetDenominator(int denom);

  Rational operator+(const Rational& other) const;
  Rational operator-(const Rational& other) const;
  Rational operator*(const Rational& other) const;
  Rational operator/(const Rational& other) const;

  Rational& operator+=(const Rational& other);
  Rational& operator-=(const Rational& other);
  Rational& operator*=(const Rational& other);
  Rational& operator/=(const Rational& other);

  Rational operator+() const;
  Rational operator-() const;

  Rational& operator++();
  Rational operator++(int);
  Rational& operator--();
  Rational operator--(int);

  bool operator==(const Rational& other) const;
  bool operator!=(const Rational& other) const;
  bool operator<(const Rational& other) const;
  bool operator<=(const Rational& other) const;
  bool operator>(const Rational& other) const;
  bool operator>=(const Rational& other) const;

  friend std::ostream& operator<<(std::ostream& out, const Rational& r);
  friend std::istream& operator>>(std::istream& in, Rational& r);
};

#endif