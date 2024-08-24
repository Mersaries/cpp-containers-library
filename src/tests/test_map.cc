#include <gtest/gtest.h>

#include <map>

#include "../headers/s21_map.h"

TEST(map_test, constr1) {
  s21::map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
  it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1).first, (*it2).first);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constr2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.size(), m2.size());
  m1.insert({1, 1});
  m2.insert({1, 1});
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constr3) {
  s21::map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  auto m11 = m1;
  auto m22 = m2;
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it2++, it1++)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constr4) {
  s21::map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  auto m11 = std::move(m1);
  auto m22 = std::move(m2);
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it2++, it1++)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constr5) {
  s21::map<int, int> m1 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {1, 2}, {3, 3}, {4, 4}, {5, 5}};
  s21::map<int, int> m11;
  std::map<int, int> m22;
  m11 = std::move(m1);
  m22 = std::move(m2);
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it2++, it1++)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constr6) {
  s21::map<int, int> test1;
  test1.insert(1, 2);
  test1.insert(2, 3);
  test1.insert(3, 4);
  s21::map<int, int> test2(test1);
  EXPECT_EQ(test2.at(1), 2);
  EXPECT_EQ(test2.at(2), 3);
  EXPECT_EQ(test2.at(3), 4);
}

TEST(map_test, at1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  for (size_t i = 1; i < m1.size(); i++) EXPECT_EQ(m1.at(i), m2.at(i));
}

TEST(map_test, at2) {  // exception leak
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  EXPECT_ANY_THROW(m1.at(0));
  EXPECT_ANY_THROW(m2.at(0));
}

TEST(map_test, at3) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.at(100), m2.at(100));
}

TEST(map_test, operator_sq1) {  // no exception leak
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1[100], m2[100]);
  EXPECT_NO_THROW(m1[-2] = 3);
  EXPECT_NO_THROW(m2[-2] = 3);
  EXPECT_NO_THROW(m1.at(-2) = 5);
  EXPECT_NO_THROW(m2.at(-2) = 5);
  EXPECT_EQ(m1.at(-2), m2.at(-2));
}

TEST(map_test, begin1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, begin2) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  auto it1 = m1.begin();
  EXPECT_EQ(it1.base(), m1.end().base());
}

TEST(map_test, end1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  auto it1 = m1.end();
  auto it2 = m2.end();
  it1--, it2--;
  EXPECT_EQ((*it2).second, (*it1).second);
}

TEST(map_test, end2) {
  s21::map<int, int> test({{1, 2}, {2, 3}, {3, 4}, {4, 5}});
  EXPECT_EQ((*(--test.end())).first, 4);
  EXPECT_EQ((*(--test.end())).second, 5);
}

TEST(map_test, empty1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, empty2) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, size1) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  std::pair<int, int> pair = {1, 1};
  m1.insert(pair);
  m2.insert(pair);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size2) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size3) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, clear1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear3) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, insert1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert3) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(3, 1).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert4) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(3, 1).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert5) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.insert_or_assign(3, 1).second, m2.insert_or_assign(3, 1).second);
  EXPECT_EQ(m1.at(3), m2.at(3));
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert6) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.insert_or_assign(2, 1).second, m2.insert_or_assign(2, 1).second);
  EXPECT_EQ(m1.at(2), m2.at(2));
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, erase1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.size(), m2.size());
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, erase2) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  s21::map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap2) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  s21::map<int, int> m11 = {
      {389, 12}, {3829, 12}, {111, 12}, {189, 12}, {11, 12}};
  std::map<int, int> m22 = {
      {389, 12}, {3829, 12}, {111, 12}, {189, 12}, {11, 12}};
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap3) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  s21::map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, merge1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  s21::map<int, int> m11 = {
      {389, 12}, {3829, 12}, {111, 12}, {189, 12}, {11, 12}};
  std::map<int, int> m22 = {
      {389, 12}, {3829, 12}, {111, 12}, {189, 12}, {11, 12}};
  m1.merge(m11);
  m2.merge(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, merge2) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  s21::map<int, int> m11 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m22 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.merge(m11);
  m2.merge(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, merge3) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  s21::map<int, int> m11 = {{389, 12}, {3829, 12}, {111, 12}, {189, 12},
                            {11, 12},  {1, 1},     {2, 2},    {100, 3},
                            {4, 4},    {5, 5}};
  std::map<int, int> m22 = {{389, 12}, {3829, 12}, {111, 12}, {189, 12},
                            {11, 12},  {1, 1},     {2, 2},    {100, 3},
                            {4, 4},    {5, 5}};
  m1.merge(m11);
  m2.merge(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); it1++, it2++)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, contains1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.contains(1), true);
}

TEST(map_test, contains2) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.contains(0), false);
}

TEST(map_test, contains3) {
  s21::map<int, int> test({{1, 2}, {2, 3}, {3, 4}, {4, 5}});
  EXPECT_EQ(test.contains(5), false);
}

TEST(map_test, insert_many) {
  s21::map<int, int> m1 = {{10, 10}, {13, 13}, {15, 15}};
  std::map<int, int> m2 = {{10, 10}, {13, 13}, {15, 15}};
  m1.insert_many(std::make_pair(5, 5));
  m2.emplace(std::make_pair(5, 5));
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  for (; it1 != m1.end() && it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(map_test, insert_many2) {
  s21::map<int, int> test({{1, 2}, {2, 3}, {3, 4}, {4, 5}});
  test.insert_many(std::make_pair(5, 6), std::make_pair(7, 8),
                   std::make_pair(9, 10));
  EXPECT_EQ(test.size(), 7);
  EXPECT_EQ(test[5], 6);
  EXPECT_EQ(test[7], 8);
  EXPECT_EQ(test[9], 10);
  EXPECT_EQ(test[1], 2);
}

TEST(map_test, insert_many3) {
  s21::map<int, int> m1;
  m1.insert_many(std::make_pair(1, 1));
  EXPECT_EQ(m1.contains(1), true);
}