#include "S21_Matrix.h"

int main() {
  S21Matrix A(3, 3, {2, 5, 7, 6, 3, 4, 5, -2, -3});
  S21Matrix B = A.inverse_matrix();
  S21Matrix C(3, 3, {1, 0, 0, 0, 1, 0, 0, 0, 1});
  cout << "A: " << endl;
  A.show();
  cout << "B: " << endl;
  B.show();
  cout << "C: " << endl;
  C.show();
  return 0;
}