#include "../S21_Matrix.h"

S21Matrix S21Matrix::inverse_matrix() {
  if (rows_ != cols_) {
    throw domain_error("Matrix must be square\n");
  }
  double det = determinant();
  if (det == 0) {
    throw invalid_argument("Determinant equals 0\n");
  }
  S21Matrix result(rows_, cols_);
  result = calc_complements();

  result = result.transpose();
  result.mul_number(1.0 / det);
  return result;
}