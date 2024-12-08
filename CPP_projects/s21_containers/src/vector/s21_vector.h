#ifndef CPP2_S21_CONTAINERS_SRC_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_SRC_S21_VECTOR_H_

#include <iostream>
#include <limits>
#include <memory>

namespace s21 {

template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  // using позволяет определять псевдонимы для типов

  vector() : arr_(nullptr), size_(0u), capacity_(0u) {}
  explicit vector(size_type size) : size_(size), capacity_(size) {
    if (size)
      arr_ = new value_type[size_]();
    else
      arr_ = nullptr;
  }
  vector(std::initializer_list<T> const &items) {
    arr_ = new value_type[items.size()];
    int i = 0;
    for (auto it = items.begin(); it != items.end(); it++) {
      arr_[i] = *it;
      i++;
    }
    size_ = items.size();
    capacity_ = items.size();
  }
  // explicit не допускает неявные преобразования типов
  vector(const vector &other) : vector() { *this = other; }
  vector(vector &&other)
      : arr_(other.arr_), size_(other.size_), capacity_(other.capacity_) {
    other.arr_ = nullptr;
    other.size_ = 0;
  }
  ~vector() { delete[] arr_; }
  vector<T> &operator=(const vector &other) {
    if (this != &other) {
      if (other.size_ > capacity_) {
        capacity_ = other.capacity_;
        delete[] arr_;
        arr_ = new value_type[capacity_];
      }
      for (size_type i = 0; i < other.size_; i++) {
        arr_[i] = other.arr_[i];
      }
      size_ = other.size_;
    }
    return *this;
  }
  vector<T> &operator=(vector &&other) {
    if (this != &other) {
      size_ = other.size_;
      capacity_ = other.capacity_;
      delete[] arr_;
      arr_ = other.arr_;
      other.arr_ = nullptr;
    }
    return *this;
  }

  reference at(size_type position) {
    if (position >= size_) throw std::out_of_range("Error");
    return arr_[position];
  }
  reference operator[](size_type position) { return arr_[position]; }
  const_reference operator[](size_type position) const {
    return arr_[position];
  }
  const_reference front() {
    if (!arr_) throw std::out_of_range("The vector contains no elements");
    return arr_[0];
  }
  const_reference back() {
    if (!arr_) throw std::out_of_range("The vector contains no elements");
    return arr_[size_ - 1];
  }
  iterator data() { return arr_; }

  iterator begin() { return arr_; }
  iterator end() { return arr_ + size_; }

  bool empty() { return size_ == 0; }
  size_type size() { return size_; }
  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
  }
  void reserve(size_type newCapacity) {
    if (newCapacity <= capacity_) return;

    iterator newarr = reinterpret_cast<iterator>(
        new int8_t[newCapacity * sizeof(value_type)]);

    try {
      std::uninitialized_copy(arr_, arr_ + size_, newarr);
    } catch (...) {
      delete[] reinterpret_cast<int8_t *>(newarr);
      throw;
    }

    for (size_t i = 0; i < size_; i++) {
      (arr_ + i)->~value_type();
    }

    delete[] reinterpret_cast<int8_t *>(arr_);

    arr_ = newarr;
    capacity_ = newCapacity;
  }
  size_type capacity() { return capacity_; }
  void shrink_to_fit() {
    if (size_ == capacity_) return;
    reserve(size_);
    capacity_ = size_;
  }

  void clear() { size_ = 0; }
  iterator insert(iterator position, const_reference value) {
    size_type index = position - arr_;
    if (index >= size_) throw std::invalid_argument("Error: invalid pointer");
    if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }
    for (size_type i = size_, j = size_ - 1; i > 0; i--, j--) {
      arr_[i] = arr_[j];
      if (i == index) {
        arr_[i] = value;
        j++;
      }
    }
    size_++;
    arr_[index] = value;
    position = arr_ + index;
    return position;
  }
  void erase(iterator pos) {
    size_type index = pos - arr_;
    if (size_ == 0 || index >= size_)
      throw std::invalid_argument("Error: invalid pointer");
    for (size_type i = index; i < size_ - 1; i++) {
      arr_[i] = arr_[i + 1];
    }
    size_--;
  }
  void push_back(const_reference value) {
    if (size_ == capacity_) {
      if (capacity_ == 0) {
        reserve(capacity_ + 1);
      } else {
        reserve(capacity_ * 2);
      }
    }
    new (arr_ + size_) value_type(value);
    size_++;
  }
  void pop_back() {
    if (size_) {
      (arr_ + size_ - 1)->~value_type();
      size_--;
    }
  }
  void swap(vector &other) {
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(arr_, other.arr_);
  }

  //допы
  template <typename... Args>
  iterator emplace(const_iterator pos, Args &&...args) {
    const size_type sizeArgs = sizeof...(args);

    s21::vector<value_type> temp{args...};
    value_type *res = const_cast<value_type *>(pos);

    for (size_type i = 0; i < sizeArgs; ++i) {
      res = insert(res, temp[i]);
      ++res;
    }

    return --res;
  }
  template <typename... Args>
  void emplace_back(Args &&...args) {
    const size_type sizeArgs = sizeof...(args);

    s21::vector<value_type> temp{args...};
    for (size_type i = 0; i < sizeArgs; ++i) {
      push_back(temp[i]);
    }
  }

 private:
  T *arr_;
  size_type size_;
  size_type capacity_;
};

}  // namespace s21

//#include "s21_vector.tpp"

#endif