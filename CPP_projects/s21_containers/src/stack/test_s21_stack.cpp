#include <gtest/gtest.h>

#include "s21_stack.h"

TEST(stack, size) {
  s21::stack<int> res;
  res.push(2);
  res.push(3);
  EXPECT_EQ(static_cast<unsigned long>(2),
            static_cast<unsigned long>(res.size()));
}

TEST(stack, emtyTrue) {
  s21::stack<int> res;
  EXPECT_EQ(res.empty(), true);
}
TEST(stack, emtyFalse) {
  s21::stack<int> res;
  res.push(3);
  EXPECT_EQ(res.empty(), false);
}

TEST(stack, clear) {
  s21::stack<int> res;
  res.push(3);
  res.push(1);
  res.push(1);
  res.clear();
  EXPECT_EQ(res.empty(), true);
}

TEST(stack, size_in_class) {
  s21::stack<int> res;

  res.push(3);
  res.push(2);
  res.push(1);
  EXPECT_EQ(static_cast<unsigned long>(3),
            static_cast<unsigned long>(res.size()));
}

TEST(stack, copy) {
  s21::stack<int> res;

  res.push(3);
  res.push(2);
  res.push(1);
  s21::stack<int> res1;
  res1 = std::move(res);

  EXPECT_EQ(res1.top(), 1);
}

TEST(stack, copy_constructor) {
  s21::stack<int> res;

  res.push(3);
  res.push(2);
  res.push(1);
  s21::stack<int> res1(res);
  while (!res1.empty()) {
    EXPECT_EQ(res.top(), res1.top());
    res.pop();
    res1.pop();
  }
}

TEST(stack, move) {
  s21::stack<int> res;

  res.push(3);
  res.push(2);
  res.push(1);
  s21::stack<int> res1(std::move(res));
  int a = 1;
  int b = 0;
  while (!res1.empty()) {
    b = res1.top();
    EXPECT_EQ(a, b);
    res1.pop();
    a++;
  }
}

TEST(stack, move_operator) {
  s21::stack<int> res;

  res.push(3);
  res.push(2);
  res.push(1);
  s21::stack<int> res1;
  res1 = std::move(res);
  while (!res.empty()) {
    int a = 1;
    int b = res1.top();
    EXPECT_EQ(a, b);
    res.pop();
    res1.pop();
    a++;
  }
}

TEST(stack, swap) {
  s21::stack<int> res;
  res.push(2);
  res.push(1);

  s21::stack<int> res1;
  res1.push(3);
  res1.push(2);
  res1.push(1);

  res.swap(res1);
  EXPECT_EQ(static_cast<unsigned long>(3),
            static_cast<unsigned long>(res.size()));
  EXPECT_EQ(static_cast<unsigned long>(2),
            static_cast<unsigned long>(res1.size()));
  int a = 1;
  while (!res.empty()) {
    EXPECT_EQ(a, res.top());
    res.pop();
    a++;
  }
  int b = 1;
  while (!res1.empty()) {
    EXPECT_EQ(b, res1.top());
    res1.pop();
    b++;
  }
}

TEST(stack, init_list) {
  s21::stack<int> res{0, 1, 2};
  int a = 2;
  while (!res.empty()) {
    EXPECT_EQ(res.top(), a);
    res.pop();
    a--;
  }
}

TEST(stack, insert_many_back_single_element) {
  s21::stack<int> res;
  res.insert_many_back(5);
  EXPECT_EQ(res.top(), 5);
  EXPECT_EQ(static_cast<unsigned long>(1),
            static_cast<unsigned long>(res.size()));
}

TEST(stack, insert_many_back_multiple_elements) {
  s21::stack<int> res;
  res.insert_many_back(1, 2, 3, 4, 5);
  EXPECT_EQ(res.top(), 5);
  EXPECT_EQ(static_cast<unsigned long>(5),
            static_cast<unsigned long>(res.size()));

  int expected_values[] = {5, 4, 3, 2, 1};
  for (int value : expected_values) {
    EXPECT_EQ(value, res.top());
    res.pop();
  }
}

TEST(stack, insert_many_back_no_arguments) {
  s21::stack<int> res;
  res.insert_many_back();
  EXPECT_TRUE(res.empty());
}

// int main(int argc, char* argv[]) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }