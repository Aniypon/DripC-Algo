#include "rational.h"

Rational::Rational() : numerator(0), denominator(1) {
}

Rational::Rational(int num) : numerator(num), denominator(1) {
} 

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
  if (denom == 0) {
    throw RationalDivisionByZero();
  }
  Reduce();
}

int Rational::GetNumerator() const {
  return numerator;
}

int Rational::GetDenominator() const {
  return denominator;
}

void Rational::SetNumerator(int num) {
  numerator = num;
  Reduce();
}

void Rational::SetDenominator(int denom) {
  if (denom == 0) {
    throw RationalDivisionByZero();
  }
  denominator = denom;
  Reduce();
}

void Rational::Reduce() {
  int gcd = std::gcd(numerator, denominator);
  numerator /= gcd;
  denominator /= gcd;
  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }
}

Rational Rational::operator+(const Rational& other) const {
  return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Rational Rational::operator-(const Rational& other) const {
  return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const {
  return Rational(numerator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator/(const Rational& other) const {
  if (other.numerator == 0) {
    throw RationalDivisionByZero();
  }
  return Rational(numerator * other.denominator, denominator * other.numerator);
}

Rational& Rational::operator+=(const Rational& other) {
  *this = *this + other;
  return *this;
}

Rational& Rational::operator-=(const Rational& other) {
  *this = *this - other;
  return *this;
}

Rational& Rational::operator*=(const Rational& other) {
  *this = *this * other;
  return *this;
}

Rational& Rational::operator/=(const Rational& other) {
  *this = *this / other;
  return *this;
}

Rational Rational::operator+() const {
  return *this;
}

Rational Rational::operator-() const {
  return Rational(-numerator, denominator);
}

Rational& Rational::operator++() {
  numerator += denominator;
  return *this;
}

Rational Rational::operator++(int) {
  Rational temp = *this;
  ++(*this);
  return temp;
}

Rational& Rational::operator--() {
  numerator -= denominator;
  return *this;
}

Rational Rational::operator--(int) {
  Rational temp = *this;
  --(*this);
  return temp;
}

bool Rational::operator==(const Rational& other) const {
  return numerator == other.numerator && denominator == other.denominator;
}

bool Rational::operator!=(const Rational& other) const {
  return !(*this == other);
}

bool Rational::operator<(const Rational& other) const {
  return numerator * other.denominator < other.numerator * denominator;
}

bool Rational::operator<=(const Rational& other) const {
  return *this < other || *this == other;
}

bool Rational::operator>(const Rational& other) const {
  return !(*this <= other);
}

bool Rational::operator>=(const Rational& other) const {
  return !(*this < other);
}

std::ostream& operator<<(std::ostream& out, const Rational& r) {
  if (r.denominator == 1) {
    out << r.numerator;
  } else {
    out << r.numerator << '/' << r.denominator;
  }
  return out;
}

std::istream& operator>>(std::istream& in, Rational& r) {
  int num, denom;
  char slash;
  in >> num >> slash >> denom;
  if (denom == 0) {
    throw RationalDivisionByZero();
  }
  r = Rational(num, denom);
  return in;
}