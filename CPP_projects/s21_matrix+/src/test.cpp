#include <gtest/gtest.h>

#include "S21_Matrix.h"

TEST(Constructors, ParamConstructorsException1) {
  EXPECT_THROW(S21Matrix matrix1(-1, -1), invalid_argument);
}

TEST(Constructors, ParamConstructorsException2) {
  EXPECT_THROW(S21Matrix matrix1(-1, 3), invalid_argument);
}

TEST(Constructors, ParamConstructorsException3) {
  EXPECT_THROW(S21Matrix matrix1(3, -1), invalid_argument);
}

TEST(Constructors, ConstructorBase) {
  S21Matrix A;
  EXPECT_EQ(2, A.getRows());
  EXPECT_EQ(2, A.getCols());

  A.setDefaultRows(3);
  A.setDefaultCols(3);

  S21Matrix B;
  EXPECT_EQ(3, B.getRows());
  EXPECT_EQ(3, B.getCols());
}

TEST(Constructors, ConstructorParam) {
  S21Matrix A(3, 2);
  EXPECT_EQ(3, A.getRows());
  EXPECT_EQ(2, A.getCols());
}

TEST(Constructors, ConstructorCopy) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix B(A);
  EXPECT_EQ(true, A == B);
}

TEST(Constructors, ConstructorMove) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix B(A);
  S21Matrix C(move(A));
  EXPECT_EQ(true, B == C);
  EXPECT_EQ(true, A.getRows() == 0 && A.getCols() == 0 && A.matrix_is_null());
}

TEST(Methodes, Accessor3x3to2x2) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  A.setRows(2);
  A.setCols(2);
  S21Matrix B(2, 2, {1, 2, 4, 5});
  EXPECT_EQ(true, A == B);
}

TEST(Methodes, Accessor2x2to4x4) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  S21Matrix B(4, 4, {1, 2, 0, 0, 3, 4});
  A.setRows(4);
  A.setCols(4);
  EXPECT_EQ(A == B, true);
}

TEST(Methodes, MethodeEqFailure) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  S21Matrix B(2, 2, {1, 2, 3, 4.1});
  EXPECT_EQ(false, A.eq_matrix(B));
}

TEST(Methodes, MethodeEqSuccess) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix B(A);
  EXPECT_EQ(true, A.eq_matrix(B));
}

TEST(Methodes, MethodeSumMatrixException) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);
  EXPECT_THROW(A.sum_matrix(B), invalid_argument);
}

TEST(Methodes, MethodeSumMatrixFailure) {
  S21Matrix A(2, 2, {1, 1, 1, 1});
  S21Matrix B(2, 2, {2, 2, 2, 2});
  A.sum_matrix(B);
  S21Matrix C(2, 2, {3, 3, 3, 4});
  EXPECT_EQ(false, A == C);
}

TEST(Methodes, MethodeSumMatrixSuccess) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix B(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  A.sum_matrix(B);
  S21Matrix C(3, 3, {2, 4, 6, 8, 10, 12, 14, 16, 18});
  EXPECT_EQ(true, A == C);
}

TEST(Methodes, MethodeSubMatrixException) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);
  EXPECT_THROW(A.sub_matrix(B), invalid_argument);
}

TEST(Methodes, MethodeSubMatrixFailure) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix B(3, 3, {9, 8, 7, 6, 5, 4, 3, 2, 1});
  A.sub_matrix(B);
  S21Matrix C(3, 3, {-8, -6, -4, -2, 0, 2, 4, 6, 7.99});
  EXPECT_EQ(false, A == C);
}

TEST(Methodes, MethodeSubMatrixSuccess) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix B(3, 3, {9, 8, 7, 6, 5, 4, 3, 2, 1});
  A.sub_matrix(B);
  S21Matrix C(3, 3, {-8, -6, -4, -2, 0, 2, 4, 6, 8});
  EXPECT_EQ(true, A == C);
}

TEST(Methodes, MethodesMulNumberFailure) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  double num = 2;
  S21Matrix B(3, 3, {2, 4, 6, 8, 10, 12, 14, 16.11, 18});
  A.mul_number(num);
  EXPECT_EQ(false, A == B);
}

TEST(Methodes, MethodeMultNumberSuccess) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  double num = 2;
  S21Matrix B(3, 3, {2, 4, 6, 8, 10, 12, 14, 16, 18});
  A.mul_number(num);
  EXPECT_EQ(true, A == B);
}

TEST(Methodes, MethodeMultMatrixException) {
  S21Matrix A(4, 3);
  S21Matrix B(4, 3);
  EXPECT_THROW(A.mul_matrix(B), invalid_argument);
}

TEST(Methodes, MethodeMultMatrixFailure) {
  S21Matrix A(4, 1, {3, 2, 0, 1});
  S21Matrix B(1, 4, {-1, 1, 0, 2});
  A.mul_matrix(B);
  S21Matrix C(4, 4, {-3, 3, 0, 6, -1, 2, 0, 4, 0, 0, 0, 0, -1, 1, 0, 2});
  EXPECT_EQ(false, A == C);
}

TEST(Methodes, MethodeMultMatrixSuccess) {
  S21Matrix A(4, 1, {3, 2, 0, 1});
  S21Matrix B(1, 4, {-1, 1, 0, 2});
  A.mul_matrix(B);
  S21Matrix C(4, 4, {-3, 3, 0, 6, -2, 2, 0, 4, 0, 0, 0, 0, -1, 1, 0, 2});
  EXPECT_EQ(true, A == C);
}

TEST(Methodes, MethodeTransposeFailure) {
  S21Matrix A(4, 2, {2, 6, 3, 7, 4, 8, 5, 9});
  S21Matrix B(2, 4, {1, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix C = A.transpose();
  EXPECT_EQ(false, B == C);
}

TEST(Methodes, MethodeTransposeSuccess) {
  S21Matrix A(4, 2, {2, 6, 3, 7, 4, 8, 5, 9});
  S21Matrix B(2, 4, {2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix C = A.transpose();
  EXPECT_EQ(true, B == C);
}

TEST(Methodes, MethodeDetException) {
  S21Matrix A(2, 3, {1, 2, 3, 4});
  EXPECT_THROW(A.determinant(), domain_error);
}

TEST(Methodes, MethodeDet2x2Failure) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  double res = A.determinant();
  double check = -2.11;
  EXPECT_EQ(false, abs(check - res) < ACCURACY);
}

TEST(Methodes, MethodeDet2x2Success) {
  S21Matrix A(2, 2, {1, -4, -5, 2});
  double res = A.determinant();
  double check = -18;
  EXPECT_EQ(true, abs(check - res) < ACCURACY);
}

TEST(Methodes, MethodeDet3x3Success) {
  S21Matrix A(3, 3, {1, -2, 3, 4, 0, 6, -7, 8, 9});
  double res = A.determinant();
  double check = 204;
  EXPECT_EQ(true, abs(check - res) < ACCURACY);
}

TEST(Methodes, MethodeDet4x4Success) {
  S21Matrix A(4, 4, {1, 3, 1, 4, 3, 9, 5, 15, 0, 2, 1, 1, 0, 4, 2, 3});
  double res = A.determinant();
  double check = -4;
  EXPECT_EQ(true, abs(check - res) < ACCURACY);
}

TEST(Methodes, MethodeCalcComplementsException) {
  S21Matrix A(3, 4, {2, -3, 1, 2, 1, -4, 6, -5, 2});

  EXPECT_THROW(A.calc_complements(), domain_error);
}

TEST(Methodes, MethodeCalcComplementsFailure) {
  S21Matrix A(3, 3, {2, -3, 1, 2, 1, -4, 6, -5, 2});
  S21Matrix B = A.calc_complements();
  S21Matrix C(3, 3, {-19, -28, -16, 1, -2, -8, 11, 10, 8});
  EXPECT_EQ(false, B == C);
}

TEST(Methodes, MethodeCalcComplementsSuccess) {
  S21Matrix A(3, 3, {2, -3, 1, 2, 1, -4, 6, -5, 2});
  S21Matrix B = A.calc_complements();
  S21Matrix C(3, 3, {-18, -28, -16, 1, -2, -8, 11, 10, 8});
  EXPECT_EQ(true, B == C);
}

TEST(Methodes, MethodesInverseMatrixException) {
  S21Matrix A(3, 4, {1, 2, 3, 4, 8});
  EXPECT_THROW(A.inverse_matrix(), domain_error);
  S21Matrix B(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  EXPECT_THROW(B.inverse_matrix(), invalid_argument);
}

TEST(Methodes, MethodesInverseMatrixFailure) {
  S21Matrix A(3, 3, {1, -2, 1, 2, 1, -1, 3, 2, -2});
  S21Matrix B = A.inverse_matrix();
  S21Matrix C(3, 3, {1, 2, -1, -1, 5, -3, -1, 8, -5});
  EXPECT_EQ(false, B == C);
}

TEST(Methodes, MethodesInverseMatrixSuccess) {
  S21Matrix A(3, 3, {1, -2, 1, 2, 1, -1, 3, 2, -2});
  S21Matrix B = A.inverse_matrix();
  S21Matrix C(3, 3, {0, 2, -1, -1, 5, -3, -1, 8, -5});
  EXPECT_EQ(true, B == C);
}

TEST(Operators, OperatorDoubleEqFailure) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  S21Matrix B(2, 2, {1, 2, 3, 4.1});
  EXPECT_EQ(false, A == B);
}

TEST(Operators, OperatorDoubleEqSuccess) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  S21Matrix B(2, 2, {1, 2, 3, 4});
  EXPECT_EQ(true, A == B);
}

TEST(Operators, OperatorEqFailure1) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  S21Matrix B = A;
  S21Matrix C(2, 2, {1, 2, 3, 5});
  EXPECT_EQ(false, B == C);
}

TEST(Operators, OperatorEqSuccess1) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  S21Matrix B = A;
  EXPECT_EQ(true, A == B);
}

TEST(Operators, OperatorEqSuccess2) {
  S21Matrix A(2, 2, {1, 2, 3, 4});
  S21Matrix B(3, 3, {3, 4, 5, 6});
  A = B;
  EXPECT_EQ(true, A == B);
}

TEST(Operators, OperatorPlusException) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 3);
  EXPECT_THROW(A + B, invalid_argument);
}

TEST(Operators, OperatorPlusFailure) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2, {1, 2, 3, 4});
  S21Matrix C = A + B;
  EXPECT_EQ(false, A == C);
}

TEST(Operators, OperatorPlusSuccess) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2, {1, 2, 3, 4});
  S21Matrix C = A + B;
  EXPECT_EQ(true, B == C);
}

TEST(Operators, OperatorPlusEqException) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 3);
  EXPECT_THROW(A += B, invalid_argument);
}

TEST(Operators, OperatorsPlusEqFailure) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix B(3, 3, {9, 8, 7, 6, 5, 4, 3, 2, 1});
  S21Matrix C(3, 3, {10, 10, 10, 10, 10, 10, 10, 10, 9});

  A += B;
  EXPECT_EQ(false, A == C);
}

TEST(Operators, OperatorPlusEqSuccess) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix B(3, 3, {9, 8, 7, 6, 5, 4, 3, 2, 1});
  S21Matrix C(3, 3, {10, 10, 10, 10, 10, 10, 10, 10, 10});

  A += B;
  EXPECT_EQ(true, A == C);
}

TEST(Operators, OperatorSubEqException) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 3);
  EXPECT_THROW(A -= B, invalid_argument);
}

TEST(Operators, OperatorSubEqFailure) {
  S21Matrix A(3, 3, {10, 10, 10, 10, 10, 10, 10, 10, 10});
  S21Matrix B(3, 3, {9, 8, 7, 6, 5, 4, 3, 2, 1});
  A -= B;
  S21Matrix C(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9.00001});
  EXPECT_EQ(false, A == C);
}

TEST(Operators, OperatorSubEqSuccess) {
  S21Matrix A(3, 3, {10, 10, 10, 10, 10, 10, 10, 10, 10});
  S21Matrix B(3, 3, {9, 8, 7, 6, 5, 4, 3, 2, 1});
  A -= B;
  S21Matrix C(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  EXPECT_EQ(true, A == C);
}

TEST(Operators, OperatorSubException) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 3);
  EXPECT_THROW(A - B, invalid_argument);
}

TEST(Operators, OperatorSubFailure) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2, {1, 2, 3, 4});
  S21Matrix C(2, 2, {-1, -2, -3, -4.22});
  S21Matrix D = A - B;
  EXPECT_EQ(false, D == C);
}

TEST(Operators, OperatorSubSuccess) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2, {1, 2, 3, 4});
  S21Matrix C(2, 2, {-1, -2, -3, -4});
  S21Matrix D = A - B;
  EXPECT_EQ(true, D == C);
}

TEST(Operators, OperatorMulEqWithMatrixException) {
  S21Matrix A(4, 3);
  S21Matrix B(4, 3);
  EXPECT_THROW(A *= B, invalid_argument);
}

TEST(Operators, OperatorMulEqWithMatrixFailure) {
  S21Matrix A(4, 1, {3, 2, 0, 1});
  S21Matrix B(1, 4, {-1, 1, 0, 2});
  A *= B;
  S21Matrix C(4, 4, {-3, 3, 1, 6, -2, 2, 0, 4, 0, 0, 0, 0, -1, 1, 0, 2});
  EXPECT_EQ(false, A == C);
}

TEST(Operators, OperatorMulEqWithMatrixSuccess) {
  S21Matrix A(4, 1, {3, 2, 0, 1});
  S21Matrix B(1, 4, {-1, 1, 0, 2});
  A *= B;
  S21Matrix C(4, 4, {-3, 3, 0, 6, -2, 2, 0, 4, 0, 0, 0, 0, -1, 1, 0, 2});
  EXPECT_EQ(true, A == C);
}

TEST(Operators, OperatorMulEqWithNumberSuccess) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  double num = 2;
  S21Matrix B(3, 3, {2, 4, 6, 8, 10, 12, 14, 16, 18});
  A *= num;
  EXPECT_EQ(true, A == B);
}

TEST(Operators, OperatorMulEqWithNumberFailure) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  double num = 2;
  S21Matrix B(3, 3, {1, 4, 6, 8, 10, 12, 14, 16, 18});
  A *= num;
  EXPECT_EQ(false, A == B);
}

TEST(Operators, OperatorMulWithMatrixException) {
  S21Matrix A(4, 3);
  S21Matrix B(4, 3);
  EXPECT_THROW(A * B, invalid_argument);
}

TEST(Operators, OperatorMulWithMatrixFailure) {
  S21Matrix A(4, 1, {3, 2, 0, 1});
  S21Matrix B(1, 4, {-1, 1, 0, 2});
  S21Matrix D = A * B;
  S21Matrix C(4, 4, {-3, 2, 0, 6, -2, 2, 0, 4, 0, 0, 0, 0, -1, 1, 0, 2});
  EXPECT_EQ(false, D == C);
}

TEST(Operators, OperatorMulWithMatrixSuccess) {
  S21Matrix A(4, 1, {3, 2, 0, 1});
  S21Matrix B(1, 4, {-1, 1, 0, 2});
  S21Matrix D = A * B;
  S21Matrix C(4, 4, {-3, 3, 0, 6, -2, 2, 0, 4, 0, 0, 0, 0, -1, 1, 0, 2});
  EXPECT_EQ(true, D == C);
}

TEST(Operators, OperatorMulWithNumberSuccess) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  double num = 2;
  S21Matrix B(3, 3, {2, 4, 6, 8, 10, 12, 14, 16, 18});
  A = A * num;
  EXPECT_EQ(true, A == B);
}

TEST(Operators, OperatorMulWithNumberFailure) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  double num = 2;
  S21Matrix B(3, 3, {1, 4, 6, 8, 10, 12, 14, 16, 18});
  A = A * num;
  EXPECT_EQ(false, A == B);
}

TEST(Operators, OperatorMulNumberWithMatrixSuccess) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  double num = 2;
  S21Matrix B(3, 3, {2, 4, 6, 8, 10, 12, 14, 16, 18});
  A = num * A;
  EXPECT_EQ(true, A == B);
}

TEST(Operators, OperatorParantheseException) {
  S21Matrix A(3, 3);
  EXPECT_THROW(A(4, 3), out_of_range);
}

TEST(Operators, OperatorParantheseSuccess) {
  S21Matrix A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  const S21Matrix B(A);
  const double num = B(2, 1);
  EXPECT_EQ(true, abs(num - 8) < ACCURACY);
  A(1, 1) = 9.;
  S21Matrix C(3, 3, {1, 2, 3, 4, 9, 6, 7, 8, 9});
  EXPECT_EQ(true, A == C);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}