#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <cmath>
#include <cstdlib>
#include <iostream>

#define ACCURACY 1e-7

using namespace std;

class S21Matrix {
 private:
  // attributes
  int rows_, cols_;  // rows and columns attributes
  double* matrix_;   // pointer to the memory where the matrix will be allocated

  static int default_rows;
  static int default_cols;

  void MemoryAllocation() { matrix_ = new double[rows_ * cols_](); }

 public:
  S21Matrix();                    // default constructor
  S21Matrix(int rows, int cols);  // parameterized constructor
  S21Matrix(const S21Matrix& o);  // copy constructor
  S21Matrix(S21Matrix&& o);       // move constructor
  S21Matrix(
      int rows, int cols,
      initializer_list<double> init_list);  // constructor with initializer list
  ~S21Matrix();                             // destructor

  // getters and setters
  int getRows() const;
  int getCols() const;
  void setRows(int rows);
  void setCols(int cols);
  static int getDefaultRows();
  static int getDefaultCols();
  static void setDefaultRows(int rows);
  static void setDefaultCols(int cols);

  // some operators overloads
  double operator()(int row, int col) const;
  double& operator()(int row, int col);
  bool operator==(const S21Matrix& o);
  S21Matrix& operator=(const S21Matrix& o);  // assignment operator overload
  S21Matrix operator+(const S21Matrix& o);
  S21Matrix& operator+=(const S21Matrix& o);
  S21Matrix& operator-=(const S21Matrix& o);
  S21Matrix operator-(const S21Matrix& o);
  S21Matrix& operator*=(const S21Matrix& o);
  S21Matrix operator*(const S21Matrix& o);
  S21Matrix operator*(const double num);
  S21Matrix operator*=(const double num);

  friend S21Matrix operator*(const double num, const S21Matrix& o);

  // some public methods
  bool eq_matrix(const S21Matrix& o);
  void sum_matrix(const S21Matrix& o);
  void sub_matrix(const S21Matrix& o);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix& o);
  S21Matrix transpose();
  double determinant();
  S21Matrix calc_complements();
  S21Matrix inverse_matrix();

  // helpers
  void show();
  void resize(int rows, int cols);
  bool matrix_is_null();
  S21Matrix minor(int rows, int cols);
};

#endif