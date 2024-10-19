#include "rational.h"

Rational& Rational::operator+=(const Rational& rhs) {
  numerator_ = numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_;
  denominator_ *= rhs.denominator_;
  Normalize();
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
  numerator_ = numerator_ * rhs.denominator_ - rhs.numerator_ * denominator_;
  denominator_ *= rhs.denominator_;
  Normalize();
  return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
  numerator_ *= rhs.numerator_;
  denominator_ *= rhs.denominator_;
  Normalize();
  return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
  if (rhs.numerator_ == 0) {
    throw RationalDivisionByZero();
  }
  numerator_ *= rhs.denominator_;
  denominator_ *= rhs.numerator_;
  Normalize();
  return *this;
}

Rational Rational::operator+() const {
  return *this;
}

Rational Rational::operator-() const {
  return {-numerator_, denominator_};  // Использование списка инициализаторов
}

Rational& Rational::operator++() {
  *this += 1;
  return *this;
}

Rational Rational::operator++(int) {
  Rational temp = *this;
  *this += 1;
  return temp;
}

Rational& Rational::operator--() {
  *this -= 1;
  return *this;
}

Rational Rational::operator--(int) {
  Rational temp = *this;
  *this -= 1;
  return temp;
}

bool Rational::operator==(const Rational& rhs) const {
  return numerator_ == rhs.numerator_ && denominator_ == rhs.denominator_;
}

bool Rational::operator!=(const Rational& rhs) const {
  return !(*this == rhs);
}

bool Rational::operator<(const Rational& rhs) const {
  return numerator_ * rhs.denominator_ < rhs.numerator_ * denominator_;
}

bool Rational::operator<=(const Rational& rhs) const {
  return *this < rhs || *this == rhs;
}

bool Rational::operator>(const Rational& rhs) const {
  return !(*this <= rhs);
}

bool Rational::operator>=(const Rational& rhs) const {
  return !(*this < rhs);
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
  if (r.denominator_ == 1) {
    os << r.numerator_;
  } else {
    os << r.numerator_ << '/' << r.denominator_;
  }
  return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
  int num = 0, denom = 1;
  char delim = '/';
  is >> num >> delim >> denom;
  if (is && delim == '/') {
    r = Rational(num, denom);
  } else {
    is.setstate(std::ios::failbit);
  }
  return is;
}
