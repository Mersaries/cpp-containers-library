CXX = g++
CXXFLAGS = -std=c++17
EFLAGS = -Wall -Wextra -Werror
TESTFLAGS = -lpthread -lgtest -lgtest_main
TESTMEM = -fsanitize=address
TESTFILES = tests/test_*.cc
# TESTFILES = tests/test_vector.cc tests/test_array.cc tests/test_list.cc tests/test_stack.cc tests/test_queue.cc
DEBUG = -g


all: clean test

s21_containers: clean test

test: clean
	${CXX} ${CXXFLAGS} $(EFLAGS) $(DEBUG) $(TESTMEM) ${TESTFILES} -o test $(TESTMEM) ${TESTFLAGS}
	./test

valgrind: clean
	${CXX} ${CXXFLAGS} $(EFLAGS) $(DEBUG) ${TESTFILES} -o test ${TESTFLAGS}
	valgrind --leak-check=full -s ./test

gcov_report: clean
	$(CXX) $(EFLAGS) --coverage -g -O0 $(TESTFILES) -o gcov_report $(TESTFLAGS)
	./gcov_report
	lcov -t "gcov_report" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

gcov_report2: clean
	$(CXX) $(EFLAGS) --coverage -g -O0 $(TESTFILES) -o gcov_report $(TESTFLAGS)
	./gcov_report
	gcovr
	gcovr --filter headers/ --html-details coverage.html
	open coverage.html

check_style:
	cp ../materials/linters/.clang-format .
	clang-format -n tests/*.cc headers/*.h *.h
	# rm .clang-format

fix_style:
	cp ../materials/linters/.clang-format .
	clang-format -i tests/*.cc headers/*.h *.h
	# rm .clang-format

clean:
	rm -rf *.o *.gcno *.gcda *.css *.html *.info *.out gcov_report test .clang-format

rebuild: clean build

.PHONY:
	all clean test build rebuild