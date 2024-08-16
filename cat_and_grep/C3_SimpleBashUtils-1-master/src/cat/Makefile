CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
FILE = test_case_cat.txt
SHELL := /bin/bash

all: s21_cat

s21_cat: s21_cat.o s21_cat_lib.o
	$(CC) $(CFLAGS) -o $@ $^

s21_cat.o: s21_cat.c
	$(CC) $(CFLAGS) -c $< -o $@

s21_cat_lib.o: s21_cat_lib.c
	$(CC) $(CFLAGS) -c $< -o $@

run_script:
	./s21_cat_test.sh

test_diff:
	diff <(./s21_cat  $(FILE)) <(cat  $(FILE))
	diff <(./s21_cat -b $(FILE)) <(cat -b $(FILE))
	diff <(./s21_cat -E $(FILE)) <(cat -E $(FILE))
	diff <(./s21_cat -e $(FILE)) <(cat -e $(FILE))
	diff <(./s21_cat -n $(FILE)) <(cat -n $(FILE))
	diff <(./s21_cat -s $(FILE)) <(cat -s $(FILE))
	diff <(./s21_cat -T $(FILE)) <(cat -T $(FILE))
	diff <(./s21_cat -t $(FILE)) <(cat -t $(FILE))
	diff <(./s21_cat -v $(FILE)) <(cat -v $(FILE))

clean:
	rm -f *.o s21_cat