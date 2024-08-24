#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../headers/s21_stack.h"

TEST(TestStack, BasicStackOperations_1) {
  s21::stack<int> st1;

  for (int i = 1; i < 6; ++i) {
    st1.push(i);
  }

  EXPECT_EQ(st1.size(), 5);

  int element = 5;
  while (!st1.empty()) {
    EXPECT_EQ(st1.top(), element);
    st1.pop();
    --element;
  }
}

TEST(TestStack, BasicStackOperations_2) {
  s21::stack<int> st1 = {1, 2, 3, 4, 5};

  EXPECT_EQ(st1.size(), 5);

  int element = 5;
  while (!st1.empty()) {
    EXPECT_EQ(st1.top(), element);
    st1.pop();
    --element;
  }
}

TEST(TestStack, BasicStackOperations_3) {
  s21::stack<int> st1 = {};

  EXPECT_EQ(st1.size(), 0);

  st1.push(2);
  EXPECT_EQ(st1.top(), 2);
  EXPECT_EQ(st1.size(), 1);
}

TEST(TestStack, BasicStackOperations_4) {
  s21::stack<int> st1{1, 2, 3, 4, 5};

  EXPECT_EQ(st1.size(), 5);

  int element = 5;
  while (!st1.empty()) {
    EXPECT_EQ(st1.top(), element);
    st1.pop();
    --element;
  }

  EXPECT_ANY_THROW(st1.pop());
}

TEST(TestStack, BasicStackOperations_5) {
  s21::stack<int> st1{1, 2, 3, 4, 5};
  s21::stack<int> st2(st1);

  EXPECT_EQ(st1.size(), 5);

  while (!st1.empty()) {
    EXPECT_EQ(st1.top(), st2.top());
    st1.pop();
    st2.pop();
  }

  EXPECT_EQ(st1.size(), st2.size());
  EXPECT_EQ(st1.empty(), st2.empty());
}

TEST(TestStack, BasicStackOperations_6) {
  s21::stack<int> st1{1, 2, 3, 4, 5};
  s21::stack<int> st2(std::move(st1));

  EXPECT_EQ(st2.size(), 5);
  EXPECT_EQ(st1.size(), 0);

  int element = 5;
  while (!st2.empty()) {
    EXPECT_EQ(element, st2.top());
    st2.pop();
    --element;
  }

  EXPECT_EQ(st2.size(), st2.size());
  EXPECT_EQ(st1.empty(), st2.empty());
}

TEST(TestStack, BasicStackOperations_7) {
  s21::stack<int> st1{1, 2, 3, 4, 5};
  s21::stack<int> st2;
  st2 = std::move(st1);

  EXPECT_EQ(st2.size(), 5);
  EXPECT_EQ(st1.size(), 0);

  int element = 5;
  while (!st2.empty()) {
    EXPECT_EQ(element, st2.top());
    st2.pop();
    --element;
  }

  EXPECT_EQ(st2.size(), st2.size());
  EXPECT_EQ(st1.empty(), st2.empty());
}

TEST(TestStack, BasicStackOperations_8) {
  s21::stack<int> st1{1, 2, 3, 4, 5};
  s21::stack<int> st2{333, 444, 555};

  EXPECT_EQ(st2.size(), 3);
  EXPECT_EQ(st1.size(), 5);

  st1.swap(st2);

  EXPECT_EQ(st2.size(), 5);
  EXPECT_EQ(st1.size(), 3);

  int element = 5;
  while (!st2.empty()) {
    EXPECT_EQ(element, st2.top());
    st2.pop();
    --element;
  }

  EXPECT_EQ(st1.top(), 555);
  st1.pop();
  EXPECT_EQ(st1.top(), 444);
  st1.pop();
  EXPECT_EQ(st1.top(), 333);
  st1.pop();

  EXPECT_EQ(st2.size(), st2.size());
  EXPECT_EQ(st1.empty(), st2.empty());
}

TEST(TestStack, InsertManyFrontStack1) {
  s21::stack<int> st1;
  EXPECT_EQ(st1.empty(), true);
  EXPECT_EQ(st1.size(), 0);

  st1.insert_many_front(1, 2, 3, 4, 5);

  EXPECT_EQ(st1.size(), 5);

  int element = 5;
  while (!st1.empty()) {
    EXPECT_EQ(st1.top(), element);
    st1.pop();
    --element;
  }

  EXPECT_ANY_THROW(st1.pop());
}

TEST(TestStack, InsertManyFrontStack2) {
  s21::stack<int> st1;
  EXPECT_EQ(st1.empty(), true);
  EXPECT_EQ(st1.size(), 0);

  st1.insert_many_front(0);

  EXPECT_EQ(st1.size(), 1);

  int element = 0;
  while (!st1.empty()) {
    EXPECT_EQ(st1.top(), element);
    st1.pop();
    --element;
  }

  EXPECT_ANY_THROW(st1.pop());
}