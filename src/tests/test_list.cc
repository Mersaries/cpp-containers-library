#include <gtest/gtest.h>

#include <iostream>
#include <list>
#include <string>

#include "../headers/s21_list.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(ListTest, BasicListOperations_1) {
  s21::list<int> l_int_1;
  std::list<int> l_int_2;

  s21::list<char> l_char_1;
  std::list<char> l_char_2;

  s21::list<double> l_double_1;
  std::list<double> l_double_2;

  l_int_1.push_back(123);
  l_int_2.push_back(123);

  l_char_1.push_back('H');
  l_char_2.push_back('H');

  l_double_1.push_back(3.14);
  l_double_2.push_back(3.14);

  EXPECT_EQ(l_int_1.size(), l_int_2.size());
  EXPECT_EQ(l_char_1.size(), l_char_2.size());
  EXPECT_EQ(l_double_1.size(), l_double_2.size());

  EXPECT_EQ(l_int_1.front(), l_int_2.front());
  EXPECT_EQ(l_char_1.front(), l_char_2.front());
  EXPECT_EQ(l_double_1.front(), l_double_2.front());
  EXPECT_EQ(l_int_1.front(), l_int_1.front());
  EXPECT_EQ(l_int_2.front(), l_int_2.front());

  l_char_1.push_front('F');
  l_char_1.push_back('G');
  l_char_2.push_front('F');
  l_char_2.push_back('G');
  EXPECT_EQ(l_char_1.front(), l_char_2.front());
  EXPECT_EQ(l_char_1.back(), l_char_2.back());
  EXPECT_EQ(l_char_1.size(), l_char_2.size());

  l_char_1.pop_back();
  l_char_2.pop_back();
  EXPECT_EQ(l_char_1.front(), l_char_2.front());
  EXPECT_EQ(l_char_1.back(), l_char_2.back());
  EXPECT_EQ(l_char_1.size(), l_char_2.size());

  l_char_1.pop_front();
  l_char_2.pop_front();
  EXPECT_EQ(l_char_1.front(), l_char_2.front());
  EXPECT_EQ(l_char_1.back(), l_char_2.back());
  EXPECT_EQ(l_char_1.size(), l_char_2.size());

  l_char_1.pop_front();
  l_char_2.pop_front();
  EXPECT_EQ(l_char_1.size(), l_char_2.size());
  EXPECT_ANY_THROW(l_char_1.pop_front());

  l_char_1.push_front('F');
  l_char_1.push_back('G');
  l_char_2.push_front('F');
  l_char_2.push_back('G');
  EXPECT_EQ(l_char_1.size(), l_char_2.size());
  l_char_1.clear();
  l_char_2.clear();
  EXPECT_EQ(l_char_1.size(), l_char_2.size());
}

TEST(ListTest, BasicListOperations_2) {
  s21::list<int> l_int_1(6);
  std::list<int> l_int_2(6);

  EXPECT_EQ(l_int_1.front(), l_int_2.front());
  EXPECT_EQ(l_int_1.back(), l_int_2.back());
  EXPECT_EQ(l_int_1.size(), l_int_2.size());
  l_int_1.clear();
  l_int_2.clear();

  s21::list<char> l_char_1(10);
  std::list<char> l_char_2(10);
  EXPECT_EQ(l_char_1.front(), l_char_2.front());
  EXPECT_EQ(l_char_1.back(), l_char_2.back());
  EXPECT_EQ(l_char_1.size(), l_char_2.size());
  l_char_1.clear();
  l_char_2.clear();

  s21::list<double> l_double_1(10);
  std::list<double> l_double_2(10);
  EXPECT_EQ(l_double_1.front(), l_double_2.front());
  EXPECT_EQ(l_double_1.back(), l_double_2.back());
  EXPECT_EQ(l_double_1.size(), l_double_2.size());
  l_double_1.clear();
  l_double_2.clear();
}

TEST(ListTest, BasicListOperations_3) {
  s21::list<int> l_int_1 = {};

  EXPECT_EQ(l_int_1.size(), 0);
  EXPECT_ANY_THROW(l_int_1.pop_front());
  EXPECT_ANY_THROW(l_int_1.pop_back());
}

TEST(ListTest, BasicListOperations_4) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2(l_int_1);

  auto it2 = l_int_2.begin();
  for (auto it1 = l_int_1.begin(); it1 != l_int_1.end(); ++it1) {
    EXPECT_EQ(*it1, *it2);
    ++it2;
  }

  s21::list<int> l_int_3(l_int_3);
}

TEST(ListTest, BasicListOperations_5) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2(std::move(l_int_1));

  auto it2 = l_int_2.begin();
  for (auto it1 = l_int_1.begin(); it1 != l_int_1.end(); ++it1) {
    EXPECT_EQ(*it1, *it2);
    ++it2;
  }

  s21::list<int> l_int_3(l_int_3);
}

TEST(ListTest, BasicListOperations_6) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2(std::move(l_int_1));

  auto it2 = l_int_2.begin();
  for (auto it1 = l_int_1.begin(); it1 != l_int_1.end(); ++it1) {
    EXPECT_EQ(*it1, *it2);
    ++it2;
  }

  s21::list<int> l_int_3(l_int_3);
}

TEST(ListTest, BasicListOperations_7) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2(std::move(l_int_2));
  s21::list<int> l_int_3(l_int_3);

  auto it2 = l_int_2.begin();
  EXPECT_ANY_THROW(*it2);
}

TEST(ListTest, BasicListOperations_8) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_3 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2;
  l_int_2 = std::move(l_int_1);

  auto it2 = l_int_2.begin();
  for (auto it3 = l_int_3.begin(); it3 != l_int_3.end(); ++it3) {
    EXPECT_EQ(*it3, *it2);
    ++it2;
  }
  EXPECT_EQ(l_int_1.size(), 0);
  auto it1 = l_int_1.begin();
  EXPECT_ANY_THROW(*it1);
}

TEST(ListTest, IteratorListTest_1) {
  s21::list<int> l_int_1;
  std::list<int> l_int_2 = {1, 2, 3, 4, 5, 6};

  l_int_1.push_back(1);
  l_int_1.push_back(2);
  l_int_1.push_back(3);
  l_int_1.push_back(4);
  l_int_1.push_back(5);
  l_int_1.push_back(6);

  s21::list<int>::iterator it1(l_int_1.begin());
  auto it2 = l_int_2.begin();

  EXPECT_EQ(*l_int_1.begin(), 1);
  EXPECT_EQ(it1 == l_int_1.begin(), true);
  EXPECT_EQ(it1 == l_int_1.end(), false);

  while (it1 != l_int_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  // std::for_each(l_int_1.begin(), l_int_1.end(), [](const int n) { std::cout
  // << n << ' '; }); std::for_each(l_int_2.begin(), l_int_2.end(), [](const int
  // n) { std::cout << n << ' '; });
}

TEST(ListTest, IteratorListTest_2) {
  s21::list<double> l_double_1{3.21, 5.321, 6534.6, 4.44, 321.43};
  l_double_1.clear();
  auto it1 = l_double_1.begin();
  EXPECT_ANY_THROW(*it1);
}

TEST(ListTest, IteratorListTest_3) {
  s21::list<double> l_double_1{3.21, 5.321, 6534.6, 4.44, 321.43};
  s21::list<double>::const_iterator it1 = l_double_1.begin();
  EXPECT_EQ((*it1), 3.21);
}

TEST(ListTest, IteratorListTest_4) {
  s21::list<double> l_double_1{3.21, 5.321, 6534.6, 4.44, 321.43};
  s21::list<double>::iterator it1 = (l_double_1.begin() - 2);
  it1 + 3;
  EXPECT_EQ(*it1, 4.44);
}

TEST(ListTest, ReverseListTest) {
  s21::list<int> l_int_1;
  std::list<int> l_int_2 = {1, 2, 3, 4, 5, 6};

  l_int_1.push_back(1);
  l_int_1.push_back(2);
  l_int_1.push_back(3);
  l_int_1.push_back(4);
  l_int_1.push_back(5);
  l_int_1.push_back(6);

  l_int_1.reverse();
  l_int_2.reverse();

  s21::list<int>::iterator it1(l_int_1.begin());
  auto it2 = l_int_2.begin();

  EXPECT_EQ(*l_int_1.begin(), 6);
  EXPECT_EQ(it1 == l_int_1.begin(), true);
  EXPECT_EQ(it1 == l_int_1.end(), false);

  while (it1 != l_int_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }

  s21::list<int> l_int_3;
  l_int_3.reverse();
}

TEST(ListTest, SortListTest) {
  s21::list<int> l_int_1 = {1, 4, 0, 4, -45, 6};
  std::list<int> ll_int_1 = {1, 4, 0, 4, -45, 6};
  ll_int_1.sort();
  l_int_1.sort();

  s21::list<int> l_int_2 = {1};
  std::list<int> ll_int_2 = {1};
  ll_int_2.sort();
  l_int_2.sort();

  auto ll_iter1 = ll_int_1.begin();
  for (s21::list<int>::iterator it1 = l_int_1.begin(); it1 != l_int_1.end();
       ++it1) {
    EXPECT_EQ(*it1, *ll_iter1);
    ++ll_iter1;
  }

  auto ll_iter2 = ll_int_2.begin();
  for (s21::list<int>::iterator it2 = l_int_2.begin(); it2 != l_int_2.end();
       ++it2) {
    EXPECT_EQ(*it2, *ll_iter2);
    ++ll_iter2;
  }

  s21::list<int> l_int_3 = {};
  l_int_3.sort();
}

TEST(ListTest, InitializationListTest) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};

  s21::list<int>::iterator it_1 = l_int_1.begin();
  for (int i = 1; i <= static_cast<int>(l_int_1.size()); i++) {
    EXPECT_EQ(*it_1, i);
    ++it_1;
  }

  s21::list<int> l_int_2 = {};
  s21::list<int>::iterator it_2 = l_int_2.begin();
  for (int i = 1; i <= static_cast<int>(l_int_2.size()); i++) {
    EXPECT_EQ(*it_2, i);
    ++it_2;
  }
}

TEST(ListTest, SpliceListTest) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2 = {100, 2, 3, 4, 5, 12345};
  s21::list<int> l_int_3 = {};

  s21::list<int>::const_iterator it = l_int_1.begin();
  s21::list<int>::iterator it2 = l_int_2.end();
  --it2;

  l_int_1.splice(it, l_int_2);
  std::string str1 = "100, 2, 3, 4, 5, 12345, 1, 2, 3, 4, 5, 6, ";

  std::string ss = "";
  for (auto it1 = l_int_1.begin(); it1 != l_int_1.end(); ++it1) {
    ss += std::to_string(*it1) + ", ";
  }
  EXPECT_EQ(ss, str1);

  l_int_1.splice(it, l_int_3);
}

TEST(ListTest, InsertList) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2 = {};

  l_int_1.insert(l_int_1.begin(), 4);
  auto it = l_int_1.begin();
  EXPECT_EQ(*it, 4);

  l_int_2.insert(l_int_2.begin(), 333);
  auto it2 = l_int_2.begin();
  EXPECT_EQ(*it2, 333);
}

TEST(ListTest, InsertManyBackList) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2 = {100, 2, 3, 4, 5, 12345};
  s21::list<int> l_int_3 = {100};

  l_int_3.insert_many_back(77);
  l_int_2.insert_many_back(1, 2, 3, 4);
  l_int_1.insert_many_back(33, 22, 11, 55);

  std::string str1 = "1, 2, 3, 4, 5, 6, 33, 22, 11, 55, ";
  std::string str2 = "100, 2, 3, 4, 5, 12345, 1, 2, 3, 4, ";
  std::string str3 = "100, 77, ";

  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);

  ss = "";
  for (auto it = l_int_2.begin(); it != l_int_2.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str2);

  ss = "";
  for (auto it = l_int_3.begin(); it != l_int_3.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str3);
}

TEST(ListTest, InsertManyFrontList) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2 = {100, 2, 3, 4, 5, 12345};
  s21::list<int> l_int_3 = {100};

  l_int_3.insert_many_front(77);
  l_int_2.insert_many_front(1, 2, 3, 4);
  l_int_1.insert_many_front(33, 22, 11, 55);

  std::string str1 = "55, 11, 22, 33, 1, 2, 3, 4, 5, 6, ";
  std::string str2 = "4, 3, 2, 1, 100, 2, 3, 4, 5, 12345, ";
  std::string str3 = "77, 100, ";

  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);

  ss = "";
  for (auto it = l_int_2.begin(); it != l_int_2.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str2);

  ss = "";
  for (auto it = l_int_3.begin(); it != l_int_3.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str3);
}

TEST(ListTest, InsertManyList) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  std::string str1 = "1, 2, 3, 4, 5, 6, 777, 666, 555, ";

  auto it = l_int_1.end();
  l_int_1.insert_many(it, 777, 666, 555);

  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, SwapList) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2 = {333, 444};
  l_int_1.swap(l_int_2);

  std::string str1 = "333, 444, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);

  std::string str2 = "1, 2, 3, 4, 5, 6, ";
  ss = "";
  for (auto it2 = l_int_2.begin(); it2 != l_int_2.end(); ++it2) {
    ss += std::to_string(*it2) + ", ";
  }
  EXPECT_EQ(ss, str2);

  EXPECT_EQ(l_int_1.size(), 2);
  EXPECT_EQ(l_int_2.size(), 6);
}

TEST(ListTest, MergeList1) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2 = {333, 444};

  l_int_1.merge(l_int_2);

  std::string str1 = "1, 2, 3, 4, 5, 6, 333, 444, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, MergeList2) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2 = {};

  l_int_1.merge(l_int_2);

  std::string str1 = "1, 2, 3, 4, 5, 6, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, MergeList3) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2 = {1, 1, 2, 3, 6};

  l_int_1.merge(l_int_2);

  std::string str1 = "1, 1, 1, 2, 2, 3, 3, 4, 5, 6, 6, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, MergeList4) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2 = {4};

  l_int_1.merge(l_int_2);

  std::string str1 = "1, 2, 3, 4, 4, 5, 6, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, MergeList5) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};
  s21::list<int> l_int_2 = {};

  l_int_1.merge(l_int_2);

  std::string str1 = "1, 2, 3, 4, 5, 6, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, MaxSizeList) {
  s21::list<int> l_int_1 = {};
  std::list<int> l_int_2 = {};
  EXPECT_DOUBLE_EQ(l_int_1.max_size(), l_int_2.max_size());
}

TEST(ListTest, EraseList1) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};

  l_int_1.erase(l_int_1.begin());
  std::string str1 = "2, 3, 4, 5, 6, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, EraseList2) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};

  auto it = l_int_1.begin();
  l_int_1.erase(++it);
  std::string str1 = "1, 3, 4, 5, 6, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, EraseList3) {
  s21::list<int> l_int_1 = {1, 2, 3, 4, 5, 6};

  auto it = l_int_1.begin();
  l_int_1.erase(++ ++it);
  std::string str1 = "1, 2, 4, 5, 6, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, EraseList4) {
  s21::list<int> l_int_1 = {};

  auto it = l_int_1.begin();
  EXPECT_ANY_THROW(l_int_1.erase(it));
}

TEST(ListTest, EraseList5) {
  s21::list<int> l_int_1 = {1};

  auto it = l_int_1.begin();
  l_int_1.erase(it);
  std::string str1 = "";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, EraseList6) {
  s21::list<int> l_int_1 = {1, 2, 3};

  auto it = l_int_1.end();
  l_int_1.erase(--it);
  std::string str1 = "1, 2, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, EraseList7) {
  s21::list<int> l_int_1 = {1, 2};

  auto it = l_int_1.end();
  l_int_1.erase(--it);
  std::string str1 = "1, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, UniqueList1) {
  s21::list<int> l_int_1 = {1, 1, 2, 3, 2, 6};

  l_int_1.unique();

  std::string str1 = "1, 2, 3, 2, 6, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, UniqueList2) {
  s21::list<int> l_int_1 = {};

  l_int_1.unique();
  auto it = l_int_1.begin();
  EXPECT_ANY_THROW(*it);
}

TEST(ListTest, UniqueList3) {
  s21::list<int> l_int_1 = {1, 2, 3, 2, 6};

  l_int_1.unique();

  std::string str1 = "1, 2, 3, 2, 6, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}

TEST(ListTest, UniqueList4) {
  s21::list<int> l_int_1 = {1, 2, 3, 3, 3, 3, 3, 3, 3, 2, 6};

  l_int_1.unique();

  std::string str1 = "1, 2, 3, 2, 6, ";
  std::string ss = "";
  for (auto it = l_int_1.begin(); it != l_int_1.end(); ++it) {
    ss += std::to_string(*it) + ", ";
  }
  EXPECT_EQ(ss, str1);
}