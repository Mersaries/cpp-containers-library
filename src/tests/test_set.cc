#include <gtest/gtest.h>

#include <set>

#include "../headers/s21_set.h"

TEST(set_test, constr1) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, constr2) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, constr3) {
  s21::set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  auto s11 = std::move(s1);
  auto s22 = std::move(s2);
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, constr4) {
  s21::set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  auto s11 = s1;
  auto s22 = s2;
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, constr5) {
  s21::set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  s21::set<int> s11;
  std::set<int> s22;
  s11 = std::move(s1);
  s22 = std::move(s2);
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, begin1) {
  s21::set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  auto it1 = s1.begin();
  auto it2 = s2.begin();
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, begin2) {
  s21::set<int> s1 = {1, 2, 3};
  s1.clear();
  auto it1 = s1.begin();
  EXPECT_EQ(it1.base(), s1.end().base());
}

TEST(set_test, end1) {
  s21::set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  auto it1 = s1.end();
  auto it2 = s2.end();
  it1--, it2--;
  EXPECT_EQ(*it2, *it1);
}

TEST(set_test, end2) {
  s21::set<int> mySet = {1, 2, 3, 4, 5};
  auto it = mySet.begin();
  int expectedValue = 1;
  while (it != mySet.end()) {
    EXPECT_EQ(*it, expectedValue);
    ++it;
    ++expectedValue;
  }
}

TEST(set_test, empty1) {
  s21::set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, empty2) {
  s21::set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, size1) {
  s21::set<int> s1;
  std::set<int> s2;
  s1.insert(1);
  s2.insert(1);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, size2) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, size3) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, clear1) {
  s21::set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear2) {
  s21::set<double> s1;
  std::set<double> s2;
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear3) {
  s21::set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, insert1) {
  s21::set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(3).second, s2.insert(3).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(3).first), *(s2.insert(3).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, insert2) {
  s21::set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(9).second, s2.insert(9).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(9).first), *(s2.insert(9).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, erase1) {
  s21::set<int> s{1, 2, 3};
  auto it = s.find(2);
  s.erase(it);
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(s.find(2), s.end());
}

TEST(set_test, erase2) {
  s21::set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s1.erase(s1.begin());
  s2.erase(s2.begin());
  auto it1 = s1.begin();
  auto it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap1) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s21::set<int> s11;
  std::set<int> s22;
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap2) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s21::set<int> s11 = {389, 3829, 111, 189, 11};
  std::set<int> s22 = {389, 3829, 111, 189, 11};
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap3) {
  s21::set<int> s1;
  std::set<int> s2;
  s21::set<int> s11;
  std::set<int> s22;
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge1) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s21::set<int> s11 = {389, 3829, 111, 189, 11};
  std::set<int> s22 = {389, 3829, 111, 189, 11};
  s1.merge(s11);
  s2.merge(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge2) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s21::set<int> s11 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s22 = {1, 2, 3, 4, 5, 6, 7, 8};
  s1.merge(s11);
  s2.merge(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge3) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s21::set<int> s11 = {1, 2, 3, 4, 5, 6, 7, 8, 389, 3829, 111, 189, 11};
  std::set<int> s22 = {1, 2, 3, 4, 5, 6, 7, 8, 389, 3829, 111, 189, 11};
  s1.merge(s11);
  s2.merge(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, find1) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(*(s1.find(3)), *(s2.find(3)));
  EXPECT_EQ(s1.find(0).base(), s1.end().base());
}

TEST(set_test, contains1) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.contains(1), true);
}

TEST(set_test, contains2) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.contains(0), false);
}

TEST(set_test, iter1) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.begin();
  auto it2 = s2.begin();
  for (int i = 0; i < 4; i++) it1++, it2++;
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, iter2) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.end();
  auto it2 = s2.end();
  for (int i = 0; i < 3; i++) --it1, --it2;
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, iter3) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.end();
  auto it2 = s1.end();
  EXPECT_EQ(it1 == it2, true);
}

TEST(set_test, iter4) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.end();
  auto it2 = s1.end();
  EXPECT_EQ(it1 != it2, false);
}

TEST(set_test, iter5) {
  s21::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.end();
  auto it2 = s1.end();
  it2++;
  EXPECT_EQ(it1 == it2, false);
}

TEST(set_test, insert_many1) {
  s21::set<int> my_set;
  auto res1 = my_set.insert_many(1);
  EXPECT_TRUE(res1[0].second);
  auto res2 = my_set.insert_many(2, 3, 4);
  EXPECT_TRUE(res2[0].second);
  EXPECT_TRUE(res2[1].second);
  EXPECT_TRUE(res2[2].second);
  auto res3 = my_set.insert_many(1, 2, 3);
  EXPECT_FALSE(res3[0].second);
  EXPECT_FALSE(res3[1].second);
  EXPECT_FALSE(res3[2].second);
}

TEST(set_test, insert_many2) {
  s21::set<int> test({1, 2, 3, 3, 3, 4, 5});
  auto result = test.insert_many(3, 6, 5, 3, 4, 7, 8, 8, 9, 10);
  EXPECT_EQ(test.size(), 10);
  EXPECT_FALSE(result[0].second);
  EXPECT_TRUE(result[1].second);
  EXPECT_FALSE(result[2].second);
  EXPECT_FALSE(result[3].second);
  EXPECT_FALSE(result[4].second);
  EXPECT_TRUE(result[5].second);
  auto iter = test.end();
  for (size_t i = test.size(); i > 0; --i) {
    --iter;
    EXPECT_EQ(*iter, i);
  }
}

TEST(set_test, insert_many3) {
  s21::set<std::string> my_set;
  auto res1 = my_set.insert_many("one");
  EXPECT_TRUE(res1[0].second);
  auto res2 = my_set.insert_many("two", "three", "four");
  EXPECT_TRUE(res2[0].second);
  EXPECT_TRUE(res2[1].second);
  EXPECT_TRUE(res2[2].second);
  auto res3 = my_set.insert_many("one", "two", "three");
  EXPECT_FALSE(res3[0].second);
  EXPECT_FALSE(res3[1].second);
  EXPECT_FALSE(res3[2].second);
}