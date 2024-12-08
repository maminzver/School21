#include "../S21_Matrix.h"

void S21Matrix::mul_matrix(const S21Matrix& o) {
  if (cols_ != o.rows_) {
    throw invalid_argument(
        "The quantity of first matrix columns is not equal to quantity of "
        "second matrix rows");
  } else {
    S21Matrix tmp(rows_, o.cols_);
    for (int m1 = 0, m = 0; m1 < rows_; m1++, m++) {
      for (int n2 = 0, n = 0; n2 < o.cols_; n2++, n++) {
        for (int n1 = 0, m2 = 0; n1 < cols_; n1++, m2++) {
          *(tmp.matrix_ + m * tmp.cols_ + n) +=
              *(matrix_ + m1 * cols_ + n1) * *(o.matrix_ + m2 * o.cols_ + n2);
        }
      }
    }

    *this = tmp;
  }
}