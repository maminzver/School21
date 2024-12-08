#include "../S21_Matrix.h"

S21Matrix S21Matrix::calc_complements() {
  if (rows_ != cols_) {
    throw domain_error("Matrix must be square");
  } else {
    S21Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix MinorMatrix = minor(i, j);

        double det = MinorMatrix.determinant();

        result(i, j) = det;

        *(result.matrix_ + i * cols_ + j) *= pow(-1, i + j);
      }
    }
    return result;
  }
}