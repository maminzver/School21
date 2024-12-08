#include "../S21_Matrix.h"

void S21Matrix::sub_matrix(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_ || matrix_ == nullptr ||
      o.matrix_ == nullptr) {
    throw invalid_argument("The sizes of matricies are not equal");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        *(matrix_ + i * cols_ + j) -= *(o.matrix_ + i * cols_ + j);
      }
    }
  }
}