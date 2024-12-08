CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: s21_grep

clean:
	rm -f s21_grep

rebuild: clean all

tests:
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep
	bash test/diff_grep.sh
	rm s21_grep
	
s21_grep:
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep
