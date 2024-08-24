#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../headers/s21_queue.h"

TEST(TestQueue, BasicQueueOperations_1) {
  s21::queue<int> qu1;

  for (int i = 0; i < 5; ++i) {
    qu1.push(i + 1);
  }

  EXPECT_EQ(qu1.size(), 5);

  int element = 1;
  while (!qu1.empty()) {
    EXPECT_EQ(qu1.front(), element);
    qu1.pop();
    ++element;
  }
}

TEST(TestQueue, BasicQueueOperations_2) {
  s21::queue<int> qu1 = {1, 2, 3, 4, 5};

  EXPECT_EQ(qu1.size(), 5);

  int element = 1;
  while (!qu1.empty()) {
    EXPECT_EQ(qu1.front(), element);
    qu1.pop();
    ++element;
  }
}

TEST(TestQueue, BasicQueueOperations_3) {
  s21::queue<int> qu1 = {};

  EXPECT_EQ(qu1.size(), 0);

  qu1.push(2);
  EXPECT_EQ(qu1.front(), 2);
  EXPECT_EQ(qu1.back(), 2);
  EXPECT_EQ(qu1.size(), 1);
}

TEST(TestQueue, BasicQueueOperations_4) {
  s21::queue<int> qu1 = {1, 2, 3, 4, 5};

  EXPECT_EQ(qu1.size(), 5);

  qu1.push(2);
  EXPECT_EQ(qu1.front(), 1);
  EXPECT_EQ(qu1.back(), 2);
  EXPECT_EQ(qu1.size(), 6);
}

TEST(TestQueue, BasicQueueOperations_5) {
  s21::queue<int> qu1{1, 2, 3, 4, 5};
  s21::queue<int> qu2(qu1);

  EXPECT_EQ(qu1.size(), 5);

  while (!qu1.empty()) {
    EXPECT_EQ(qu1.front(), qu2.front());
    EXPECT_EQ(qu1.back(), qu2.back());
    qu1.pop();
    qu2.pop();
  }

  EXPECT_EQ(qu1.size(), qu2.size());
  EXPECT_EQ(qu1.empty(), qu2.empty());
}

TEST(TestQueue, BasicQueueOperations_6) {
  s21::queue<int> qu1{1, 2, 3, 4, 5};
  s21::queue<int> qu2(std::move(qu1));

  EXPECT_EQ(qu2.size(), 5);
  EXPECT_EQ(qu1.size(), 0);

  int element = 1;
  while (!qu2.empty()) {
    EXPECT_EQ(element, qu2.front());
    qu2.pop();
    ++element;
  }

  EXPECT_EQ(qu2.size(), qu2.size());
  EXPECT_EQ(qu1.empty(), qu2.empty());
}

TEST(TestQueue, BasicQueueOperations_7) {
  s21::queue<int> qu1{1, 2, 3, 4, 5};
  s21::queue<int> qu2;
  qu2 = std::move(qu1);

  EXPECT_EQ(qu2.size(), 5);
  EXPECT_EQ(qu1.size(), 0);

  int element = 1;
  while (!qu2.empty()) {
    EXPECT_EQ(element, qu2.front());
    qu2.pop();
    ++element;
  }

  EXPECT_EQ(qu2.size(), qu2.size());
  EXPECT_EQ(qu1.empty(), qu2.empty());
}

TEST(TestQueue, BasicqueueOperations_8) {
  s21::queue<int> qu1{1, 2, 3, 4, 5};
  s21::queue<int> qu2{333, 444, 555};

  EXPECT_EQ(qu2.size(), 3);
  EXPECT_EQ(qu1.size(), 5);

  qu1.swap(qu2);

  EXPECT_EQ(qu2.size(), 5);
  EXPECT_EQ(qu1.size(), 3);

  int element = 1;
  while (!qu2.empty()) {
    EXPECT_EQ(element, qu2.front());
    qu2.pop();
    ++element;
  }

  EXPECT_EQ(qu1.front(), 333);
  qu1.pop();
  EXPECT_EQ(qu1.front(), 444);
  qu1.pop();
  EXPECT_EQ(qu1.front(), 555);
  qu1.pop();

  EXPECT_EQ(qu2.size(), qu2.size());
  EXPECT_EQ(qu1.empty(), qu2.empty());
}

TEST(TestQueue, InsertManyBackQueue1) {
  s21::queue<int> qu1;
  EXPECT_EQ(qu1.empty(), true);
  EXPECT_EQ(qu1.size(), 0);

  qu1.insert_many_back(1, 2, 3, 4, 5);

  EXPECT_EQ(qu1.size(), 5);

  int element = 1;
  while (!qu1.empty()) {
    EXPECT_EQ(qu1.front(), element);
    qu1.pop();
    ++element;
  }

  EXPECT_ANY_THROW(qu1.pop());
}

TEST(TestQueue, InsertManyBackQueue2) {
  s21::queue<int> qu1;
  EXPECT_EQ(qu1.empty(), true);
  EXPECT_EQ(qu1.size(), 0);

  qu1.insert_many_back(0);

  EXPECT_EQ(qu1.size(), 1);

  int element = 0;
  while (!qu1.empty()) {
    EXPECT_EQ(qu1.front(), element);
    EXPECT_EQ(qu1.back(), element);
    qu1.pop();
    ++element;
  }

  EXPECT_ANY_THROW(qu1.pop());
}