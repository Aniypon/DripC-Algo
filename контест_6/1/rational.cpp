#include "rational.h"
#include <numeric>

Rational::Rational() : numerator_(0), denominator_(1) {
}

Rational::Rational(int32_t num) : numerator_(num), denominator_(1) {
}  // NOLINT

Rational::Rational(int32_t num, int32_t denom) : numerator_(num), denominator_(denom) {
  if (denom == 0) {
    throw RationalDivisionByZero{};
  }
  Simplify();
}

int32_t Rational::GetNumerator() const {
  return numerator_;
}

int32_t Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(int32_t num) {
  numerator_ = num;
  Simplify();
}

void Rational::SetDenominator(int32_t denom) {
  if (denom == 0) {
    throw RationalDivisionByZero{};
  }
  denominator_ = denom;
  Simplify();
}

void Rational::Simplify() {
  int32_t gcd = std::gcd(numerator_, denominator_);
  numerator_ /= gcd;
  denominator_ /= gcd;
  if (denominator_ < 0) {
    numerator_ = -numerator_;
    denominator_ = -denominator_;
  }
}

Rational &Rational::operator+=(const Rational &rhs) {
  numerator_ = numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_;
  denominator_ *= rhs.denominator_;
  Simplify();
  return *this;
}

Rational Rational::operator+(const Rational &rhs) const {
  Rational result = *this;
  result += rhs;
  return result;
}

Rational &Rational::operator-=(const Rational &rhs) {
  numerator_ = numerator_ * rhs.denominator_ - rhs.numerator_ * denominator_;
  denominator_ *= rhs.denominator_;
  Simplify();
  return *this;
}

Rational Rational::operator-(const Rational &rhs) const {
  Rational result = *this;
  result -= rhs;
  return result;
}

Rational &Rational::operator*=(const Rational &rhs) {
  numerator_ *= rhs.numerator_;
  denominator_ *= rhs.denominator_;
  Simplify();
  return *this;
}

Rational Rational::operator*(const Rational &rhs) const {
  Rational result = *this;
  result *= rhs;
  return result;
}

Rational &Rational::operator/=(const Rational &rhs) {
  if (rhs.numerator_ == 0) {
    throw RationalDivisionByZero{};
  }
  numerator_ *= rhs.denominator_;
  denominator_ *= rhs.numerator_;
  Simplify();
  return *this;
}

Rational Rational::operator/(const Rational &rhs) const {
  Rational result = *this;
  result /= rhs;
  return result;
}

Rational Rational::operator+() const {
  return *this;
}

Rational Rational::operator-() const {
  return {-numerator_, denominator_};
}

Rational &Rational::operator++() {
  numerator_ += denominator_;
  return *this;
}

Rational Rational::operator++(int) {
  Rational temp = *this;
  numerator_ += denominator_;
  return temp;
}

Rational &Rational::operator--() {
  numerator_ -= denominator_;
  return *this;
}

Rational Rational::operator--(int) {
  Rational temp = *this;
  numerator_ -= denominator_;
  return temp;
}

bool Rational::operator==(const Rational &rhs) const {
  return numerator_ == rhs.numerator_ && denominator_ == rhs.denominator_;
}

bool Rational::operator!=(const Rational &rhs) const {
  return !(*this == rhs);
}

bool Rational::operator<(const Rational &rhs) const {
  return numerator_ * rhs.denominator_ < rhs.numerator_ * denominator_;
}

bool Rational::operator<=(const Rational &rhs) const {
  return *this < rhs || *this == rhs;
}

bool Rational::operator>(const Rational &rhs) const {
  return !(*this <= rhs);
}

bool Rational::operator>=(const Rational &rhs) const {
  return !(*this < rhs);
}

bool Rational::operator<(int rhs) const {
  return numerator_ < rhs * denominator_;
}

bool Rational::operator>(int rhs) const {
  return numerator_ > rhs * denominator_;
}

bool Rational::operator==(int rhs) const {
  return numerator_ == rhs * denominator_;
}

bool Rational::operator!=(int rhs) const {
  return numerator_ != rhs * denominator_;
}

bool Rational::operator<=(int rhs) const {
  return numerator_ <= rhs * denominator_;
}

bool Rational::operator>=(int rhs) const {
  return numerator_ >= rhs * denominator_;
}

bool operator<(int lhs, const Rational &rhs) {
  return lhs * rhs.GetDenominator() < rhs.GetNumerator();
}

bool operator>(int lhs, const Rational &rhs) {
  return lhs * rhs.GetDenominator() > rhs.GetNumerator();
}

bool operator==(int lhs, const Rational &rhs) {
  return lhs * rhs.GetDenominator() == rhs.GetNumerator();
}

bool operator!=(int lhs, const Rational &rhs) {
  return lhs * rhs.GetDenominator() != rhs.GetNumerator();
}

bool operator<=(int lhs, const Rational &rhs) {
  return lhs * rhs.GetDenominator() <= rhs.GetNumerator();
}

bool operator>=(int lhs, const Rational &rhs) {
  return lhs * rhs.GetDenominator() >= rhs.GetNumerator();
}

std::ostream &operator<<(std::ostream &os, const Rational &r) {
  if (r.denominator_ == 1) {
    os << r.numerator_;
  } else {
    os << r.numerator_ << '/' << r.denominator_;
  }
  return os;
}

std::istream &operator>>(std::istream &is, Rational &r) {
  int32_t num = 0;
  int32_t denom = 1;
  char ch = '/';
  is >> num;
  if (is.peek() == '/') {
    is >> ch >> denom;
  }
  r = Rational(num, denom);
  return is;
}