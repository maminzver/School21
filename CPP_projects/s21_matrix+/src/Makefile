CPP = g++
CPPFLAGS = -std=c++17 -Wall -Werror -Wextra

LIB = ./Lib/*.cpp 
OBJECTS = *.o 
TEST = test.cpp 

CLANG_PATH = ../materials/linters/
CLANG_COPY = cp $(CLANG_PATH).clang-format .clang-format 

all: s21_matrix_oop.a test

test: s21_matrix_oop.a
	$(CPP) $(CPPFLAGS) -o tests test.cpp s21_matrix_oop.a -lgtest -lpthread
	./tests 

s21_matrix_oop.a: 
	$(CPP) $(CPPFLAGS) -Iinclude -c $(LIB)
	ar rc s21_matrix_oop.a *.o 
	ranlib s21_matrix_oop.a 


clean:
	rm -rf $(OBJECTS) *.a *.gch *.gcda *.gcno *.info tests .clang-format

clang:
	$(CLANG_COPY) && clang-format -n ./Lib/*.cpp *.cpp *.h
	$(CLANG_COPY) && clang-format -i ./Lib/*.cpp *.cpp *.h