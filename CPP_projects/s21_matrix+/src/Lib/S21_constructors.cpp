#include "../S21_Matrix.h"

int S21Matrix::default_rows = 2;
int S21Matrix::default_cols = 2;

S21Matrix::S21Matrix() : rows_(default_rows), cols_(default_cols) {
  MemoryAllocation();
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw invalid_argument("Invalid number of rows or columns\n");
  }
  MemoryAllocation();
}

S21Matrix::S21Matrix(const S21Matrix& o) : rows_(o.rows_), cols_(o.cols_) {
  MemoryAllocation();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i * cols_ + j] = o.matrix_[i * cols_ + j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& o)
    : rows_(o.rows_), cols_(o.cols_), matrix_(o.matrix_) {
  o.rows_ = 0;
  o.cols_ = 0;
  o.matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols, initializer_list<double> init_list)
    : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw invalid_argument("Number of rows and columns must be greater than 0");
  }
  MemoryAllocation();
  copy(init_list.begin(), init_list.end(), matrix_);
}

S21Matrix::~S21Matrix() {
  delete[] matrix_;

  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}