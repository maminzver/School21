#include "../S21_Matrix.h"

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

void S21Matrix::setRows(int rows) {
  if (rows < 1) {
    throw invalid_argument("Number of rows < 1");
  } else if (rows != rows_) {
    resize(rows, cols_);
  }
}

void S21Matrix::setCols(int cols) {
  if (cols < 1) {
    throw invalid_argument("Number of cols < 1");
  } else if (cols != cols_) {
    resize(rows_, cols);
  }
}

int S21Matrix::getDefaultRows() { return default_rows; }

int S21Matrix::getDefaultCols() { return default_cols; }

void S21Matrix::setDefaultCols(int cols) {
  if (cols < 1) {
    throw invalid_argument("The number of columns can't be less than 1\n");
  }
  default_cols = cols;
}

void S21Matrix::setDefaultRows(int rows) {
  if (rows < 1) {
    throw invalid_argument("The number of rows can't be less than 1\n");
  }
  default_rows = rows;
}