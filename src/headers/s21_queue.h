#ifndef SRC_HEADERS_S21_QUEUE_H_
#define SRC_HEADERS_S21_QUEUE_H_

#include <exception>

#include "s21_list.h"

namespace s21 {
template <typename T>
class queue {
 public:
  // Queue Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Queue Member functions
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();
  queue operator=(queue &&q);

  // Queue Element access
  const_reference front();
  const_reference back();

  // Queue Capacity
  bool empty();
  size_type size();

  // Queue Modifiers
  void push(const_reference value);
  void pop();
  void swap(queue &other);

  // Bonus part
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  s21::list<value_type> container_;
};

}  // namespace s21

namespace s21 {
template <typename value_type>
queue<value_type>::queue() {
  container_.clear();
}

template <typename value_type>
queue<value_type>::queue(std::initializer_list<value_type> const &items) {
  container_.clear();
  for (const auto &item : items) {
    push(item);
  }
}

template <typename value_type>
queue<value_type>::queue(const queue &s) {
  container_ = s.container_;
}

template <typename value_type>
queue<value_type>::queue(queue &&s) {
  container_ = std::move(s.container_);
}

template <typename value_type>
queue<value_type> queue<value_type>::operator=(queue &&s) {
  container_ = std::move(s.container_);
  return *this;
}

template <typename value_type>
queue<value_type>::~queue() {
  container_.clear();
}

template <typename value_type>
typename queue<value_type>::size_type queue<value_type>::size() {
  return container_.size();
}

template <typename value_type>
bool queue<value_type>::empty() {
  return container_.empty();
}

template <typename value_type>
void queue<value_type>::push(const_reference value) {
  container_.push_back(value);
}

template <typename value_type>
void queue<value_type>::pop() {
  container_.pop_front();
}

template <typename value_type>
void queue<value_type>::swap(queue &other) {
  container_.swap(other.container_);
}

template <typename value_type>
typename queue<value_type>::const_reference queue<value_type>::front() {
  return container_.front();
}

template <typename value_type>
typename queue<value_type>::const_reference queue<value_type>::back() {
  return container_.back();
}

template <typename value_type>
template <typename... Args>
void queue<value_type>::insert_many_back(Args &&...args) {
  container_.insert_many_back(args...);
}
}  // namespace s21

#endif  // SRC_HEADERS_S21_QUEUE_H_