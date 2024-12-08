#include "../S21_Matrix.h"

void S21Matrix::mul_number(const double num) {
  for (int i = 0; i < rows_ * cols_; i++) *(matrix_ + i) = *(matrix_ + i) * num;
}