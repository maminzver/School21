#include "../S21_Matrix.h"

void S21Matrix::show() {
  if (rows_ < 1 || cols_ < 1 || matrix_ == nullptr) {
    throw invalid_argument(
        "Invalid number of rows, columns, or the matrix doesn't exist");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        cout << matrix_[i * cols_ + j] << "\t";
      }
      cout << endl;
    }
    cout << endl;
  }
}

void S21Matrix::resize(int rows, int cols) {
  S21Matrix tmp(*this);

  double *newArr = new double[rows * cols]();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i < rows_ && j < cols_) {
        newArr[i * cols + j] = matrix_[i * cols_ + j];
      }
    }
  }
  delete[] matrix_;
  rows_ = rows;
  cols_ = cols;
  matrix_ = newArr;
}

bool S21Matrix::matrix_is_null() {
  bool res = false;
  if (matrix_ == nullptr) res = true;
  return res;
}

S21Matrix S21Matrix::minor(int rows, int cols) {
  int excludeRow = 0;
  int excludeCol = 0;
  S21Matrix result(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_ - 1; i++) {
    if (i == rows) excludeRow = 1;
    for (int j = 0; j < cols_ - 1; j++) {
      if (j == cols) excludeCol = 1;
      *(result.matrix_ + i * result.cols_ + j) =
          *(matrix_ + (i + excludeRow) * cols_ + j + excludeCol);
    }
    excludeCol = 0;
  }

  return result;
}
