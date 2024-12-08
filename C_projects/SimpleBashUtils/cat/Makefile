CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
TARGET1 = s21_cat


all: 
	$(CC) $(CFLAGS) s21_cat.c s21_cat.h -o $(TARGET1) 

clean:
	rm -rf $(TARGET1)

rebuild: clean all
