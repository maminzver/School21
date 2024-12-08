#include "../S21_Matrix.h"

S21Matrix S21Matrix::transpose() {
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      *(res.matrix_ + j * rows_ + i) = *(matrix_ + i * cols_ + j);
    }
  }
  return res;
}