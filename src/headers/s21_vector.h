#ifndef SRC_HEADERS_S21_VECTOR_H
#define SRC_HEADERS_S21_VECTOR_H

#include <algorithm>         // для std::copy и std::min
#include <initializer_list>  // для std::initializer_list
#include <iostream>
#include <limits>     // для std::numeric_limits
#include <stdexcept>  // для std::out_of_range
#include <string>

namespace s21 {
template <typename T>
class vector {
 public:
  // ВНУТРИКЛАССОВЫЕ ПЕРЕОПРЕДЕЛЕНИЯ ТИПОВ
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  ////////////////////////////////////////////////

  // КОНСТРУКТОРЫ И ДЕСТРУКТОР
  vector();  // базовый конструктор, инициализирующий вертор с заранее заданной
             // размерностью
  vector(size_type n) noexcept;  // параметризированный конструктор
  vector(std::initializer_list<value_type> const &items) noexcept;
  vector(const vector &v) noexcept;  // конструктор копирования
  vector(vector &&v) noexcept;  // конструткор перемещения
  ~vector() noexcept;           // деструктор
  vector &operator=(vector &&v);  // перегрузка оператора присваивания
  vector &operator=(const vector &v);

  ////////////////////////////////////////////////

  // Доступ к эл-ам класса
  reference at(
      size_type pos);  // доступ к указанному элементу с проверкой границ
  const_reference at(
      size_type pos) const;  // доступ к указанному элементу с проверкой границ
  reference operator[](size_type pos) noexcept;  // доступ к указанному элементу
  const_reference operator[](
      size_type pos) const noexcept;  // доступ к указанному элементу
  reference front() noexcept;
  const_reference front() const noexcept;  // доступ к первому элементу
  reference back() noexcept;
  const_reference back() const noexcept;  // доступ к последнему элементу
  iterator data() noexcept;  // прямой доступ к базовому массиву
  const_iterator data() const noexcept;

  // Итерирование по элементам класса (доступ к итераторам)
  iterator begin() noexcept;  // возвращает итератор в начало
  const_iterator cbegin() const noexcept;
  iterator end() noexcept;  // возвращает итератор в конец
  const_iterator cend() const noexcept;

  // Доступ к информации о наполнении контейнера
  bool empty() const noexcept;  // проверяет, пуст ли контейнер // 1 - пуст
  size_type size() const noexcept;  // возвращает размер хранимого массива
  size_type max_size()
      const noexcept;  // возвращает максимально возможное количество элементов
  void reserve(size_type size);
  size_type capacity() const noexcept;  // возвращает размер буфера
  void shrink_to_fit() noexcept;  // уменьшает использование памяти за счет
                                  // освобождения неиспользуемой памяти

  // Изменение контейнера
  void clear() noexcept;
  iterator insert(const_iterator pos, const_reference value);
  iterator insert(const_iterator pos, value_type &&value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();  // удаляет последний элемент
  void swap(vector &other);

  // Реализация методов insert_many
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  // Переменные
  value_type *vector_ = nullptr;
  size_type size_;      // текущий размер массива
  size_type capacity_;  // доступный размер буфера

  void memory_allocation_(size_type n) noexcept;
  void zero_vector_() noexcept;
  void change_capacity_(size_type n) noexcept;
};
}  // namespace s21

//////////////////////////////////////////////////////////////////////////////////////

// КОНСТРУКТОРЫ И ДЕСТРУКТОР
namespace s21 {

// базовый конструктор, инициализирующий вертор с заранее заданной размерностью
template <typename T>
vector<T>::vector() {
  zero_vector_();
}

// параметризированный конструктор
template <typename T>
vector<T>::vector(size_type n) noexcept {
  memory_allocation_(n);
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items) noexcept {
  memory_allocation_(items.size());
  std::copy(items.begin(), items.end(), vector_);
}

// конструктор копирования
template <typename T>
vector<T>::vector(const vector &v) noexcept {
  memory_allocation_(v.size_);
  std::copy(v.vector_, v.vector_ + v.size_, vector_);
}

// конструктор перемещения
template <typename T>
vector<T>::vector(vector &&v) noexcept
    : vector_(std::move(v.vector_)), size_(v.size_), capacity_(v.capacity_) {
  v.zero_vector_();
}

// деструктор
template <typename T>
vector<T>::~vector() noexcept {
  delete[] vector_;
  zero_vector_();
}

// перегрузка оператора присваивания
template <typename T>
vector<T> &vector<T>::operator=(vector &&v) {
  if (this != &v) {
    delete[] vector_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    vector_ = v.vector_;
    v.zero_vector_();
  }
  return *this;
}

// перегрузка оператора присваивания
template <typename T>
vector<T> &vector<T>::operator=(const vector &v) {
  if (this != &v) {
    delete[] vector_;
    vector_ = new T[v.capacity_];
    std::copy(v.vector_, v.vector_ + v.size_, vector_);
    size_ = v.size_;
    capacity_ = v.capacity_;
  }
  return *this;
}

//////////////////////////////////////////////////////////////////////////////////////

// ДОСТУП К ЭЛ-ТАМ КЛАССА

// доступ к указанному элементу с проверкой границ
template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) throw std::out_of_range("index out of range");
  return vector_[pos];
}

// доступ к указанному элементу с проверкой границ
template <typename T>
typename vector<T>::const_reference vector<T>::at(size_type pos) const {
  if (pos >= size_) throw std::out_of_range("index out of range");
  return vector_[pos];
}

// доступ к указанному элементу
template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) noexcept {
  return vector_[pos];
}

// доступ к указанному элементу
template <typename T>
typename vector<T>::const_reference vector<T>::operator[](
    size_type pos) const noexcept {
  return vector_[pos];
}

// доступ к первому элементу
template <typename T>
typename vector<T>::reference vector<T>::front() noexcept {
  return vector_[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() const noexcept {
  return vector_[0];
}

// доступ к последнему элементу
template <typename T>
typename vector<T>::reference vector<T>::back() noexcept {
  return vector_[size_ - 1];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const noexcept {
  return vector_[size_ - 1];
}

// прямой доступ к базовому массиву
template <typename T>
typename vector<T>::iterator vector<T>::data() noexcept {
  return vector_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::data() const noexcept {
  return vector_;
}

//////////////////////////////////////////////////////////////////////////////////////

// ИТЕРИРОВАНИЕ ПО ЭЛ-ТАМ КЛАССА (доступ к итераторам)

// возвращает итератор в начало
template <typename T>
typename vector<T>::iterator vector<T>::begin() noexcept {
  return vector_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const noexcept {
  return vector_;
}

// returns an iterator to the end
template <typename T>
typename vector<T>::iterator vector<T>::end() noexcept {
  return vector_ + size();
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const noexcept {
  return vector_ + size();
}

//////////////////////////////////////////////////////////////////////////////////////

// ДОСТУП К ИНФОРМАЦИИ О НАПОЛНЕНИИ КОНТЕЙНЕРА

// проверяет, пуст ли контейнер // 1 - пуст
template <typename T>
bool vector<T>::empty() const noexcept {
  return size() == 0;
}

// возвращает размер хранимого массива
template <typename T>
typename vector<T>::size_type vector<T>::size() const noexcept {
  return size_;
}

// возвращает максимально возможное количество элементов
template <typename T>
typename vector<T>::size_type vector<T>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size > max_size()) {
    throw std::length_error("can't allocate memory of this size");
  }
  if (size > capacity_) {
    value_type *temp = new value_type[size];
    std::copy(vector_, vector_ + size_, temp);
    delete[] vector_;
    vector_ = temp;
    capacity_ = size;
  }
}

// возвращает размер буфера
template <typename T>
typename vector<T>::size_type vector<T>::capacity() const noexcept {
  return capacity_;
}

// уменьшает использование памяти за счет освобождения неиспользуемой памяти
template <typename T>
void vector<T>::shrink_to_fit() noexcept {
  if (capacity_ > size_) change_capacity_(size_);
}

//////////////////////////////////////////////////////////////////////////////////////

// ИЗМЕНЕНИЕ КОНТЕЙНЕРА
// очищает содержимое
template <typename T>
void vector<T>::clear() noexcept {
  size_ = 0;
  delete[] vector_;
  vector_ = nullptr;
}

// вставляет элементы в конкретную позицию и возвращает итератор, указывающий на
// новый элемент
template <typename T>
typename vector<T>::iterator vector<T>::insert(const_iterator pos,
                                               const_reference value) {
  if (pos < begin() || pos > end())
    throw std::out_of_range("Error: pos >= size_");
  size_type position = pos - begin();
  push_back(value);
  for (size_type i = size_ - 1; i > position; i--)
    std::swap(vector_[i], vector_[i - 1]);
  return vector_ + position;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(const_iterator pos,
                                               value_type &&value) {
  if (pos < begin() || pos > end())
    throw std::out_of_range("Error: pos >= size_");
  size_type position = pos - begin();
  push_back(value);
  for (size_type i = size_ - 1; i > position; i--)
    std::swap(vector_[i], vector_[i - 1]);
  return vector_ + position;
}

// стирает элемент в позиции
template <typename T>
void vector<T>::erase(iterator pos) {
  if (pos < begin() || pos > end())
    throw std::out_of_range("Error: pos >= size_");
  size_type position = pos - begin();
  for (size_type i = position; i < size_ - 1; i++)
    std::swap(vector_[i], vector_[i + 1]);
  size_ -= 1;
}

// добавляет элемент в конец
template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size_ + 1 > capacity_) {
    reserve((capacity_ == 0) ? 1 : capacity_ * 2);
  }
  vector_[size_] = value;
  size_ += 1;
}

// удаляет последний элемент
template <typename T>
void vector<T>::pop_back() {
  if (empty()) {
    size_ = 0;
    throw std::logic_error("Vector is empty");
  }
  size_ -= 1;
}

// меняет содержимое
template <typename T>
void vector<T>::swap(vector &other) {
  if (this != &other) {
    std::swap(vector_, other.vector_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }
}

//////////////////////////////////////////////////////////////////////////////////////

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  size_type count = sizeof...(Args);
  reserve(size_ + count);

  iterator it = begin() + (pos - cbegin());
  ((void)insert(it++, std::forward<Args>(args)), ...);
  return it;
}

template <typename value_type>
template <typename... Args>
void vector<value_type>::insert_many_back(Args &&...args) {
  insert_many(end(), args...);
}

//////////////////////////////////////////////////////////////////////////////////////

// ПРИВАТНЫЕ МЕТОДЫ

template <typename T>
void vector<T>::memory_allocation_(size_type n) noexcept {
  size_ = n;
  capacity_ = size_;
  vector_ = new value_type[size_];
}

template <typename T>
void vector<T>::zero_vector_() noexcept {
  vector_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <typename T>
void vector<T>::change_capacity_(size_type n) noexcept {
  T *tmp_vector = new T[n];
  std::copy(vector_, end(), tmp_vector);
  delete[] vector_;
  vector_ = tmp_vector;
  capacity_ = n;
}

}  // namespace s21

#endif  // SRC_S21_VECTOR_H