#include "../S21_Matrix.h"

bool S21Matrix::eq_matrix(const S21Matrix &o) {
  if (rows_ != o.rows_ || cols_ != o.cols_ || matrix_ == nullptr ||
      o.matrix_ == nullptr) {
    return false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (abs(matrix_[i * cols_ + j] - o.matrix_[i * cols_ + j]) > ACCURACY)
          return false;
      }
    }
  }
  return true;
}