#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

using namespace std;

template <typename T>
class Matrix {
 public:
  Matrix(const vector<vector<T>>& data) : data_(data) {
    rows_ = data.size();
    cols_ = data[0].size();
  }

  pair<size_t, size_t> size() const {
    return {data_.size(), data_[0].size()};
  }

  Matrix<T>& operator+=(const Matrix<T>& other) {
    for (size_t i = 0; i < data_.size(); i++) {
      for (size_t j = 0; j < data_[i].size(); j++) {
        data_[i][j] += other.data_[i][j];
      }
    }
    return *this;
  }

  Matrix<T> operator+(const Matrix<T>& other) const {
    vector<vector<T>> resultData(data_.size(), vector<T>(data_[0].size()));
    for (size_t i = 0; i < data_.size(); ++i) {
      for (size_t j = 0; j < data_[i].size(); ++j) {
        resultData[i][j] = data_[i][j] + other.data_[i][j];
      }
    }
    return Matrix<T>(resultData);
  }

  template <typename U>
  Matrix<T>& operator*=(const U& scalar) {
    for (size_t i = 0; i < data_.size(); i++) {
      for (size_t j = 0; j < data_[i].size(); j++) {
        data_[i][j] *= scalar;
      }
    }
    return *this;
  }
  template <typename P>
  Matrix<T> operator*(const P& scalar) const{
    vector<vector<T>> resultData(data_.size(), vector<T>(data_[0].size()));
    for (size_t i = 0; i < data_.size(); i++) {
      for (size_t j = 0; j < data_[i].size(); j++) {
        resultData[i][j] = data_[i][j] * scalar;
      }
    }
    return Matrix<T>(resultData);
  }

  Matrix<T>& operator*=(const Matrix<T>& other) {
    assert(cols_ == other.rows_);
    vector<vector<T>> resultData(rows_, vector<T>(other.cols_, 0));
    for (size_t i = 0; i < rows_; ++i) {
      for (size_t j = 0; j < other.cols_; ++j) {
        for (size_t k = 0; k < cols_; ++k) {
          resultData[i][j] += data_[i][k] * other.data_[k][j];
        }
      }
    }
    data_ = resultData;
    cols_ = other.cols_;
    return *this;
  }

  Matrix<T> operator*(const Matrix<T>& other) const {
    assert(cols_ == other.rows_);
    vector<vector<T>> resultData(rows_, vector<T>(other.cols_, 0));
    for (size_t i = 0; i < rows_; ++i) {
      for (size_t j = 0; j < other.cols_; ++j) {
        for (size_t k = 0; k < cols_; ++k) {
          resultData[i][j] += data_[i][k] * other.data_[k][j];
        }
      }
    }
    return Matrix<T>(resultData);
  }

  Matrix<T>& transpose() {
    vector<vector<T>> transposedData(cols_, vector<T>(rows_));
    for (size_t i = 0; i < rows_; ++i) {
      for (size_t j = 0; j < cols_; ++j) {
        transposedData[j][i] = data_[i][j];
      }
    }
    data_ = transposedData;
    swap(rows_, cols_);
    return *this;
  }

  Matrix<T> transposed() const {
    vector<vector<T>> transposedData(cols_, vector<T>(rows_));
    for (size_t i = 0; i < rows_; ++i) {
      for (size_t j = 0; j < cols_; ++j) {
        transposedData[j][i] = data_[i][j];
      }
    }
    return Matrix<T>(transposedData);
  }

  friend ostream& operator<<(ostream& out, const Matrix<T>& m) {
    for (size_t i = 0; i < m.data_.size(); ++i) {
      for (size_t j = 0; j < m.data_[i].size(); ++j) {
        if (j > 0)
          out << "\t";
        out << m.data_[i][j];
      }
      if (i < m.data_.size() - 1) {
        out << "\n";
      }
    }
    return out;
  }

 private:
  vector<vector<T>> data_;
  size_t rows_;
  size_t cols_;
};

