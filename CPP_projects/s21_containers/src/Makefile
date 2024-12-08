# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -I /usr/include/gtest

CLANG_PATH = ../materials/linters/
CLANG_COPY = cp $(CLANG_PATH).clang-format .clang-format


# Флаги для линковки
LDFLAGS = -lgtest -lpthread -lgtest_main

GCOVFLAGS = -fprofile-arcs -ftest-coverage

# Находим все файлы .cpp во вложенных директориях
SRC = $(shell find . -name "*.cpp")

# Создаем объектные файлы для каждого .cpp файла
OBJS = $(SRC:.cpp=.o)

# Целевое имя исполняемого файла
TARGET = test

UNAME = $(shell uname)

OPEN_REPORT :=
LEAKS :=

ifeq ($(UNAME), Linux)
OPEN_REPORT += xdg-open
LEAKS += valgrind --tool=memcheck --leak-check=yes
endif

ifeq ($(UNAME), Darwin)
OPEN_REPORT += open
LEAKS += leaks -atExit --
endif

# Правило по умолчанию
all: $(TARGET) 
	$(LEAKS) ./test

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS) 

# Правило для компиляции каждого .cpp в .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJS) $(TARGET) .clang-format

# Очистка только объектных файлов
clean_obj:
	rm -f $(OBJS)

clang:
	$(CLANG_COPY) && find . -type f \( -name "*.cpp" -o -name "*.h" \) -exec clang-format -i {} \;
	$(CLANG_COPY) && find . -type f \( -name "*.cpp" -o -name "*.h" \) -exec clang-format -n {} \;

