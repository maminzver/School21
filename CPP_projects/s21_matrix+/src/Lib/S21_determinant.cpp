#include "../S21_Matrix.h"

double S21Matrix::determinant() {
  if (rows_ != cols_) {
    throw domain_error("Matrix must be square");
  } else if (rows_ == 1) {
    return *matrix_;
  } else if (rows_ == 2) {
    return *matrix_ * *(matrix_ + 3) - *(matrix_ + 1) * *(matrix_ + 2);
  } else {
    double sign = 1., result = 0;
    for (int i = 0; i < cols_; i++) {
      S21Matrix MinorMatrix = minor(0, i);
      result += sign * *(matrix_ + i) * MinorMatrix.determinant();
      sign = -sign;
    }
    return result;
  }
}