#ifndef SRC_HEADERS_S21_STACK_H_
#define SRC_HEADERS_S21_STACK_H_

#include <exception>

#include "s21_list.h"

namespace s21 {
template <typename T>
class stack {
 public:
  // Stack Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Stack Member functions
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack();
  stack operator=(stack &&s);

  // Stack Element access
  const_reference top();

  // Stack Capacity
  bool empty();
  size_type size();

  // Stack Modifiers
  void push(const_reference value);
  void pop();
  void swap(stack &other);

  // Bonus part
  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  s21::list<value_type> container_;
};
}  // namespace s21

namespace s21 {
template <typename value_type>
stack<value_type>::stack() {
  container_.clear();
}

template <typename value_type>
stack<value_type>::stack(std::initializer_list<value_type> const &items) {
  container_.clear();
  for (const auto &item : items) {
    push(item);
  }
}

template <typename value_type>
stack<value_type>::stack(const stack &s) {
  container_ = s.container_;
}

template <typename value_type>
stack<value_type>::stack(stack &&s) {
  container_ = std::move(s.container_);
}

template <typename value_type>
stack<value_type> stack<value_type>::operator=(stack &&s) {
  container_ = std::move(s.container_);
  return *this;
}

template <typename value_type>
stack<value_type>::~stack() {
  container_.clear();
}

template <typename value_type>
typename stack<value_type>::size_type stack<value_type>::size() {
  return container_.size();
}

template <typename value_type>
bool stack<value_type>::empty() {
  return container_.empty();
}

template <typename value_type>
void stack<value_type>::push(const_reference value) {
  container_.push_front(value);
}

template <typename value_type>
void stack<value_type>::pop() {
  container_.pop_front();
}

template <typename value_type>
void stack<value_type>::swap(stack &other) {
  container_.swap(other.container_);
}

template <typename value_type>
typename stack<value_type>::const_reference stack<value_type>::top() {
  return container_.front();
}

template <typename value_type>
template <typename... Args>
void stack<value_type>::insert_many_front(Args &&...args) {
  container_.insert_many_front(args...);
}
}  // namespace s21

#endif  // SRC_HEADERS_S21_STACK_H_