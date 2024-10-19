#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>

class MatrixOutOfRange : public std::out_of_range {
 public:
  MatrixOutOfRange() : std::out_of_range("Matrix index out of range") {}
};

template <typename T, size_t Rows, size_t Cols>
class Matrix {
 public:
  T data[Rows][Cols];

  Matrix() = default;

  size_t RowsNumber() const {
    return Rows;
  }

  size_t ColumnsNumber() const {
    return Cols;
  }

  T& operator()(size_t row, size_t col) {
    return data[row][col];
  }

  const T& operator()(size_t row, size_t col) const {
    return data[row][col];
  }

  T& At(size_t row, size_t col) {
    if (row >= Rows || col >= Cols) {
      throw MatrixOutOfRange();
    }
    return data[row][col];
  }

  const T& At(size_t row, size_t col) const {
    if (row >= Rows || col >= Cols) {
      throw MatrixOutOfRange();
    }
    return data[row][col];
  }

  Matrix<T, Cols, Rows> GetTransposed() const {
    Matrix<T, Cols, Rows> result;
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        result(j, i) = data[i][j];
      }
    }
    return result;
  }

  Matrix<T, Rows, Cols>& operator+=(const Matrix<T, Rows, Cols>& other) {
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        data[i][j] += other.data[i][j];
      }
    }
    return *this;
  }

  Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols>& other) const {
    Matrix<T, Rows, Cols> result = *this;
    result += other;
    return result;
  }

  Matrix<T, Rows, Cols>& operator-=(const Matrix<T, Rows, Cols>& other) {
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        data[i][j] -= other.data[i][j];
      }
    }
    return *this;
  }

  Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols>& other) const {
    Matrix<T, Rows, Cols> result = *this;
    result -= other;
    return result;
  }

  template <size_t OtherCols>
  Matrix<T, Rows, OtherCols> operator*(const Matrix<T, Cols, OtherCols>& other) const {
    Matrix<T, Rows, OtherCols> result{};
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < OtherCols; ++j) {
        for (size_t k = 0; k < Cols; ++k) {
          result(i, j) += data[i][k] * other.data[k][j];
        }
      }
    }
    return result;
  }

  Matrix<T, Rows, Cols>& operator*=(const T& scalar) {
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        data[i][j] *= scalar;
      }
    }
    return *this;
  }

  Matrix<T, Rows, Cols> operator*(const T& scalar) const {
    Matrix<T, Rows, Cols> result = *this;
    result *= scalar;
    return result;
  }

  Matrix<T, Rows, Cols>& operator/=(const T& scalar) {
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        data[i][j] /= scalar;
      }
    }
    return *this;
  }

  Matrix<T, Rows, Cols> operator/(const T& scalar) const {
    Matrix<T, Rows, Cols> result = *this;
    result /= scalar;
    return result;
  }

  bool operator==(const Matrix<T, Rows, Cols>& other) const {
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        if (data[i][j] != other.data[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  bool operator!=(const Matrix<T, Rows, Cols>& other) const {
    return !(*this == other);
  }

  friend std::ostream& operator<<(std::ostream& out, const Matrix<T, Rows, Cols>& matrix) {
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        if (j > 0) {
          out << ' ';
        }
        out << matrix.data[i][j];
      }
      if (i < Rows - 1) {
        out << '\n';
      }
    }
    return out;
  }

  friend std::istream& operator>>(std::istream& in, Matrix<T, Rows, Cols>& matrix) {
    for (size_t i = 0; i < Rows; ++i) {
      for (size_t j = 0; j < Cols; ++j) {
        in >> matrix.data[i][j];
      }
    }
    return in;
  }
};

#endif  // MATRIX_H