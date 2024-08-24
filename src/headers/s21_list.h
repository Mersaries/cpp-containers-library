#ifndef SRC_HEADERS_S21_LIST_H_
#define SRC_HEADERS_S21_LIST_H_

#include <cmath>
#include <exception>
#include <initializer_list>
#include <limits>
#include <stdexcept>

namespace s21 {
template <typename T>
class list {
 public:
  // List Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  // List Functions
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  list operator=(list&& l);
  list operator=(const list& l);

  // List Element access
  const_reference front();
  const_reference back();

  // List Capacity
  bool empty();
  size_type size();
  size_type max_size();

  struct Node {
    value_type value_;
    Node* next_;
    Node* prev_;
    Node(const value_type& value)
        : value_(value), next_(nullptr), prev_(nullptr){};
  };

  template <typename value_type>
  class ListIterator {
   public:
    ListIterator(Node* node) : current_(node){};
    reference operator*() {
      if (current_) {
        return current_->value_;
      }
      throw std::invalid_argument("Iterator points to nullptr!");
    }
    ListIterator& operator++() {
      current_ = current_->next_;
      return *this;
    };
    ListIterator& operator--() {
      current_ = current_->prev_;
      return *this;
    };
    ListIterator operator+(const int n) {
      Node* tmp = current_;
      for (int i = 0; i < n; ++i) {
        current_ = current_->next_;
      }
      ListIterator it(tmp);
      return it;
    };
    ListIterator operator-(const int n) {
      Node* tmp = current_;
      for (int i = 0; i < n; ++i) {
        current_ = current_->prev_;
      }
      ListIterator it(tmp);
      return it;
    };
    bool operator!=(ListIterator other) { return current_ != other.current_; };
    bool operator==(ListIterator other) { return current_ == other.current_; };

   private:
    Node* current_ = nullptr;
    friend class list<value_type>;  // необходимо френдить, так как в функции
                                    // листа приваты итератора не видно
  };

  template <typename value_type>
  class ListConstIterator : public ListIterator<value_type> {
   public:
    ListConstIterator(ListIterator<value_type> other)
        : ListIterator<value_type>(other){};
    const_reference operator*() {
      return ListIterator<value_type>::operator*();
    };
  };

  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  // List Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
  iterator insert(iterator pos, const_reference value);

  // List Modifiers
  void clear();
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();

  // Help functions
  void print_list();

  // Bonus functions
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args);

  template <typename... Args>
  void insert_many_back(Args&&... args);

  template <typename... Args>
  void insert_many_front(Args&&... args);

 private:
  Node* head_;
  Node* tail_;
  Node* end_;
  size_type size_;

  // Help functions
  void rewrite_end();
};
}  // namespace s21

// Realisation
namespace s21 {
// List Functions
template <typename value_type>
list<value_type>::list()
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  end_ = new Node(size());
  rewrite_end();
};

template <typename value_type>
list<value_type>::list(size_type n) : list<value_type>::list() {
  for (size_type i = 0; i < n; ++i) {
    push_back(0);
  }
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items)
    : list<value_type>::list() {
  for (const auto& item : items) {
    push_back(item);
  }
}

template <typename value_type>
list<value_type>::list(const list& l) : list<value_type>::list() {
  if (this != &l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
      push_back(*it);
    }
  }
}

template <typename value_type>
list<value_type>::list(list&& l)
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  if (this != &l) {
    this->swap(l);
  }
}

template <typename value_type>
s21::list<value_type> s21::list<value_type>::operator=(const list& l) {
  if (this != &l) {
    clear();
    for (auto it = l.begin(); it != l.end(); ++it) {
      push_back(*it);
    }
  }
  return *this;
}

template <typename value_type>
s21::list<value_type> s21::list<value_type>::operator=(list&& l) {
  if (this != &l) {
    clear();
    this->swap(l);
  }
  return *this;
}

template <typename value_type>
list<value_type>::~list() {
  clear();
  if (end_) {
    delete end_;
  }
}

// List Modifiers
template <typename value_type>
void list<value_type>::pop_back() {
  Node* tmp = tail_;
  if (empty()) {
    throw std::out_of_range(
        "Unable to remove the element from empty container");
  } else if (size() == 1) {
    tmp = tail_;
    tail_ = nullptr;
    head_ = nullptr;
  } else if (size() > 1) {
    tmp = tail_;
    tail_ = tail_->prev_;
    tail_->next_ = nullptr;
  }
  delete tmp;
  --size_;
  rewrite_end();
}

template <typename value_type>
void list<value_type>::pop_front() {
  if (empty()) {
    throw std::out_of_range(
        "Unable to remove the element from empty container");
  }
  Node* tmp = head_;
  if (size() == 1) {
    tail_ = nullptr;
    head_ = nullptr;
  } else if (size() > 0) {
    head_ = head_->next_;
    head_->prev_ = nullptr;
  }
  delete tmp;
  --size_;
  rewrite_end();
}

template <typename value_type>
void list<value_type>::push_back(const_reference value) {
  Node* last = new Node(value);
  if (empty()) {
    head_ = last;
    tail_ = last;
  } else {
    tail_->next_ = last;
    last->prev_ = tail_;
    tail_ = last;
  }
  ++size_;
  rewrite_end();
}

template <typename value_type>
void list<value_type>::push_front(const_reference value) {
  Node* last = new Node(value);
  if (empty()) {
    head_ = last;
    tail_ = last;
  } else {
    head_->prev_ = last;
    last->next_ = head_;
    head_ = last;
  }
  ++size_;
  rewrite_end();
}

template <typename value_type>
void list<value_type>::swap(list& other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(end_, other.end_);
  std::swap(size_, other.size_);
}

template <typename value_type>
void list<value_type>::merge(list& other) {
  if (!other.empty() && !this->empty()) {
    if (other.size() && this->size()) {
      for (iterator it = other.begin(); it != other.end(); ++it) {
        push_back(*it);
      }
      rewrite_end();
      sort();
    }
  }
}

template <typename value_type>
void list<value_type>::unique() {
  if (!empty()) {
    iterator it = begin();
    ++it;
    for (; it != end(); ++it) {
      if (*it == it.current_->prev_->value_) {
        iterator deleted = (it - 1);
        erase(deleted);
      }
    }
  }
}

template <typename value_type>
void list<value_type>::reverse() {
  if (!empty()) {
    iterator it = begin();
    for (size_type el = 0; el < size() + 1; ++el) {
      std::swap(it.current_->prev_, it.current_->next_);
      ++it;
    }
  }
  std::swap(head_, tail_);
}

template <typename value_type>
void list<value_type>::splice(const_iterator pos, list& other) {
  if (!other.empty()) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
      insert(pos, *it);
    }
    other.clear();
  }
}

template <typename value_type>
void list<value_type>::sort() {
  if (size()) {
    for (iterator it1 = begin(); it1 != end(); ++it1) {
      for (iterator it2 = begin(); it2 != end(); ++it2) {
        if (*it2 > *it1) {
          std::swap(*it1, *it2);
        }
      }
    }
  }
}

// List Element access
template <typename value_type>
typename list<value_type>::const_reference list<value_type>::front() {
  return head_->value_;
};

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::back() {
  return tail_->value_;
};

// List Iterators
template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
  return iterator(head_);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
  return iterator(end_);
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::begin() const {
  return const_iterator(head_);
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::end() const {
  return const_iterator(end_);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  Node* newNode = new Node(value);
  Node* curNode = pos.current_;
  if (empty()) {
    newNode->next_ = end_;
    newNode->prev_ = end_;
    head_ = newNode;
    tail_ = newNode;
  } else {
    if (curNode == head_) {
      head_ = newNode;
    } else if (curNode == end_) {
      tail_ = newNode;
    }
    newNode->next_ = curNode;
    newNode->prev_ = curNode->prev_;
    curNode->prev_->next_ = newNode;
    curNode->prev_ = newNode;
  }
  ++size_;
  rewrite_end();
  return iterator(newNode);
}

template <typename value_type>
void list<value_type>::erase(iterator pos) {
  Node* curNode = pos.current_;
  if (empty() || curNode == end_) {
    throw std::invalid_argument("Erase error");
  }
  if (curNode == head_) {
    if (curNode->next_ && curNode->next_ != end_) {
      head_ = curNode->next_;
    } else {
      head_ = end_;
    }

  } else if (curNode == tail_) {
    if (curNode->prev_ && curNode->prev_ != end_) {
      tail_ = curNode->prev_;
    } else {
      tail_ = end_;
    }
  }
  curNode->prev_->next_ = curNode->next_;
  curNode->next_->prev_ = curNode->prev_;
  --size_;
  curNode->next_ = nullptr;
  curNode->prev_ = nullptr;
  curNode->value_ = 0;
  delete curNode;
}

// List Capacity
template <typename value_type>
bool list<value_type>::empty() {
  return size_ == 0 ? true : false;
};

template <typename value_type>
typename list<value_type>::size_type list<value_type>::size() {
  return size_;
};

template <typename value_type>
typename list<value_type>::size_type list<value_type>::max_size() {
  int arch = sizeof(void*) == 4 ? 31 : 63;

  auto size = std::pow(2, arch) / sizeof(Node);
  return size;
};

template <typename value_type>
void list<value_type>::clear() {
  while (!empty()) {
    pop_back();
  }
}

template <typename value_type>
void list<value_type>::rewrite_end() {
  if (end_) {
    end_->next_ = head_;
    end_->prev_ = tail_;
    end_->value_ = size();
  }
  if (head_) {
    head_->prev_ = end_;
  }
  if (tail_) {
    tail_->next_ = end_;
  }
}

template <typename value_type>
void list<value_type>::print_list() {
  if (size()) {
    iterator it = begin();
    while (it != end()) {
      std::cout << *it << " ";
      ++it;
    }
    std::cout << std::endl;
  }
}

// Bonus part

template <typename value_type>
template <typename... Args>
typename list<value_type>::iterator list<value_type>::insert_many(
    const_iterator pos, Args&&... args) {
  iterator it = pos;
  (insert(it, args), ...);

  return it;
}

template <typename value_type>
template <typename... Args>
void list<value_type>::insert_many_back(Args&&... args) {
  (push_back(args), ...);
}

template <typename value_type>
template <typename... Args>
void list<value_type>::insert_many_front(Args&&... args) {
  (push_front(args), ...);
}
}  // namespace s21

#endif  // SRC_HEADERS_S21_LIST_H_