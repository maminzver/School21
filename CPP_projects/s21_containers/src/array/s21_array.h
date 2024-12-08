#ifndef CPP2_S21_CONTAINERS_INCLUDE_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_INCLUDE_S21_ARRAY_H_

#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <utility>

namespace s21 {

template <typename T, size_t N>
class array {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  array() : size_(N) {}
  array(std::initializer_list<value_type> const& items) {
    if (items.size() != N) {
      throw std::out_of_range(
          "Num of elements in initializer list is not equal to array size");
    }
    std::copy(items.begin(), items.end(), data_);
  }

  array(const array& a) : size_(a.size_) {
    std::copy(a.data_, a.data_ + N, data_);
  }

  array(array&& a) { std::move(a.data_, a.data_ + N, data_); }

  ~array() = default;

  array& operator=(const array& a) {
    if (this != &a) {
      size_ = a.size_;
      std::copy(a.data_, a.data_ + a.size_, data_);
    }
    return *this;
  }

  array& operator=(array&& a) noexcept {
    for (size_t i = 0; i < N; ++i) {
      data_[i] = std::move(a.data_[i]);
    }
    // Заполняем перемещенный массив значениями по умолчанию
    a.fill(value_type{});
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= N) {
      throw std::out_of_range("Index is out of range");
    }
    return data_[pos];
  }

  const_reference at(size_type pos) const {
    if (pos >= N) {
      throw std::out_of_range("Index is out of range");
    }
    return data_[pos];
  }

  reference operator[](size_type pos) { return data_[pos]; }

  const_reference operator[](size_type pos) const { return data_[pos]; }

  const_reference front() const {
    if (N == 0) {
      throw std::out_of_range("Size of array is 0");
    }
    return data_[0];
  }

  reference front() {
    if (N == 0) {
      throw std::out_of_range("Size of array is 0");
    }
    return data_[0];
  }

  const_reference back() const {
    if (N == 0) {
      throw std::out_of_range("Size of array is 0");
    }
    return data_[size_ - 1];
  }

  reference back() {
    if (N == 0) {
      throw std::out_of_range("Size of array is 0");
    }
    return data_[size_ - 1];
  }

  iterator data() { return data_; }

  iterator begin() noexcept { return data_; }

  iterator end() noexcept { return data_ + size_; }

  const_iterator cbegin() const noexcept { return data_; }

  const_iterator cend() const noexcept { return data_ + size_; }

  bool empty() const { return N == 0; }

  size_type size() const { return size_; }

  size_type max_size() const { return size(); }

  void swap(array& other) noexcept {
    for (size_type i = 0; i < N; ++i) {
      std::swap(data_[i], other.data_[i]);
    }
  }

  void fill(const_reference value) { std::fill(begin(), end(), value); }

 private:
  value_type data_[N ? N : 1] = {};  // Базовый массив данных
  size_type size_ = N;  // Текущий размер массива
};

}  // namespace s21

#endif
