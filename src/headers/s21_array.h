#ifndef SRC_HEADERS_S21_ARRAY_H
#define SRC_HEADERS_S21_ARRAY_H

#include <algorithm>         // для std::copy и std::min
#include <initializer_list>  // для std::initializer_list
#include <iostream>
#include <stdexcept>  // для std::out_of_range
#include <string>

namespace s21 {

template <typename T, size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // КОНСТРУКТОРЫ И ДЕСТРУКТОР
  array() = default;
  array(std::initializer_list<value_type> const &items);
  array(const array &a) noexcept;
  array(array &&a) noexcept;
  ~array() noexcept;
  array &operator=(array &&a);
  array &operator=(const array &a);

  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos) noexcept;
  const_reference operator[](size_type pos) const noexcept;
  reference front() noexcept;
  const_reference front() const noexcept;
  reference back() noexcept;
  const_reference back() const noexcept;
  iterator data() noexcept;
  const_iterator data() const noexcept;

  iterator begin() noexcept;
  const_iterator cbegin() const noexcept;
  iterator end() noexcept;
  const_iterator cend() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void swap(array &other) noexcept;
  void fill(const_reference value) noexcept;

 private:
  value_type *array_ = new value_type[N];
};

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  if (items.size() > N) {
    throw std::runtime_error("Size is not the same.");
  }
  std::copy(items.begin(), items.end(), array_);
}

template <typename T, size_t N>
array<T, N>::array(const array &a) noexcept {
  std::copy(a.array_, a.array_ + N, array_);
}

template <typename T, size_t N>
array<T, N>::array(array &&a) noexcept {
  std::move(a.array_, a.array_ + N, array_);
}

template <typename T, size_t N>
array<T, N>::~array() noexcept {
  delete[] array_;
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array &&a) {
  if (this != &a) {
    std::move(a.array_, a.array_ + N, array_);
  }
  return *this;
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(const array &a) {
  if (this != &a) {
    std::copy(a.array_, a.array_ + N, array_);
  }
  return *this;
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("index out of range");
  }
  return array_[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::at(size_type pos) const {
  if (pos >= N) {
    throw std::out_of_range("index out of range");
  }
  return array_[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](
    size_type pos) noexcept {
  return array_[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::operator[](
    size_type pos) const noexcept {
  return array_[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::front() noexcept {
  return array_[0];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() const noexcept {
  return array_[0];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::back() noexcept {
  return array_[N - 1];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() const noexcept {
  return array_[N - 1];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data() noexcept {
  return array_;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::data() const noexcept {
  return array_;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() noexcept {
  return array_;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::cbegin() const noexcept {
  return array_;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end() noexcept {
  return array_ + N;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::cend() const noexcept {
  return array_ + N;
}

template <typename T, size_t N>
bool array<T, N>::empty() const noexcept {
  return size() == 0;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::size() const noexcept {
  return N;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const noexcept {
  return N;
}

template <typename T, size_t N>
void array<T, N>::swap(array &other) noexcept {
  std::swap_ranges(array_, array_ + N, other.array_);
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value) noexcept {
  std::fill(array_, array_ + N, value);
}

}  // namespace s21

#endif  // SRC_HEADERS_S21_ARRAY_H
