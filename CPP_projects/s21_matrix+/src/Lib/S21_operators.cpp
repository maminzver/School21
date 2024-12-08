#include "../S21_Matrix.h"

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw out_of_range("Incorrect input, index is out of range");
  }

  return matrix_[(row)*cols_ + col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw out_of_range("Incorrect input, index is out of range");
  }

  return *(matrix_ + (row)*cols_ + col);
}

bool S21Matrix::operator==(const S21Matrix& o) { return eq_matrix(o); }

S21Matrix& S21Matrix::operator=(const S21Matrix& o) {
  if (!rows_ && !cols_ && matrix_ == nullptr) {
    rows_ = o.rows_;
    cols_ = o.cols_;
    MemoryAllocation();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        *(matrix_ + i * cols_ + j) = *(o.matrix_ + i * cols_ + j);
      }
    }

  } else {
    if (rows_ != o.rows_) setRows(o.rows_);
    if (cols_ != o.cols_) setCols(o.cols_);
    for (int i = 0; i < rows_ * cols_; i++) *(matrix_ + i) = *(o.matrix_ + i);
  }
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_ || matrix_ == nullptr ||
      o.matrix_ == nullptr) {
    throw invalid_argument("The matricies' sizes are not equal");
  } else {
    S21Matrix tmp(*this);
    tmp += o;
    return tmp;
  }
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_ || matrix_ == nullptr ||
      o.matrix_ == nullptr) {
    throw invalid_argument("The matricies' sizes are not equal");
  } else {
    sum_matrix(o);
    return *this;
  }
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_ || matrix_ == nullptr ||
      o.matrix_ == nullptr) {
    throw invalid_argument("The matricies' sizes are not equal");
  } else {
    sub_matrix(o);
    return *this;
  }
}

S21Matrix S21Matrix::operator-(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_ || matrix_ == nullptr ||
      o.matrix_ == nullptr) {
    throw invalid_argument("The matricies' sizes are not equal");
  } else {
    S21Matrix tmp(*this);
    tmp -= o;
    return tmp;
  }
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& o) {
  if (cols_ != o.rows_ || matrix_ == nullptr || o.matrix_ == nullptr) {
    throw invalid_argument(
        "The quantity of first matrix columns is not equal to quantity of "
        "second matrix rows");
  } else {
    mul_matrix(o);
  }
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& o) {
  if (cols_ != o.rows_ || matrix_ == nullptr || o.matrix_ == nullptr) {
    throw invalid_argument(
        "The quantity of first matrix columns is not equal to quantity of "
        "second matrix rows");
  } else {
    S21Matrix tmp(*this);
    tmp *= o;
    return tmp;
  }
}

S21Matrix S21Matrix::operator*=(const double num) {
  mul_number(num);
  return *this;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix tmp(*this);
  tmp *= num;
  return tmp;
}

S21Matrix operator*(const double num, const S21Matrix& o) {
  S21Matrix tmp(o);
  tmp.mul_number(num);
  return tmp;
}
