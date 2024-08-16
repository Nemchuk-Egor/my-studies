CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
FILE = test1.txt test2.txt
PATTERNS = patterns.reg
CHECK=2>&1 valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all
ERROR = ERROR

SHELL := /bin/bash

all: s21_grep test_diff

s21_grep: s21_grep.o s21_grep_lib.o
	$(CC) $(CFLAGS) -o $@ $^

s21_grep.o: s21_grep.c
	$(CC) $(CFLAGS) -c $< -o $@

s21_grep_lib.o: s21_grep_lib.c
	$(CC) $(CFLAGS) -c $< -o $@

test_diff:
	diff -s <(./s21_grep CAT $(FILE)) <(grep CAT $(FILE))
	diff -s <(./s21_grep -v CAT $(FILE)) <(grep -v CAT $(FILE))
	diff -s <(./s21_grep -i CAT $(FILE)) <(grep -i CAT $(FILE))
	diff -s <(./s21_grep -iv CAT $(FILE)) <(grep -iv CAT $(FILE))
	diff -s <(./s21_grep -in CAT $(FILE)) <(grep -in CAT $(FILE))
	diff -s <(./s21_grep -ie "^CAT" $(FILE)) <(grep -ie "^CAT" $(FILE))
	diff -s <(./s21_grep -ince "^CAT" $(FILE)) <(grep -ince "^CAT" $(FILE))
	diff -s <(./s21_grep -lh gre $(FILE)) <(grep -lh gre $(FILE))
	diff -s <(./s21_grep -hc e $(FILE)) <(grep -hc e $(FILE))
	diff -s <(./s21_grep -oi cat $(FILE)) <(grep -oi cat $(FILE))
	diff -s <(./s21_grep -oinc cat $(FILE)) <(grep -oinc cat $(FILE))
	diff -s <(./s21_grep -e CAT -e cat $(FILE)) <(grep -e CAT -e cat $(FILE))
	diff -s <(./s21_grep -s cat badfile ) <(grep -s cat badfile)
	diff -s <(./s21_grep -f $(PATTERNS) $(FILE)) <(grep -f $(PATTERNS) $(FILE))

	# # echo "Testing for memory leaks"
	$(CHECK) ./s21_grep cat *txt | grep -E $(ERROR)
	$(CHECK) ./s21_grep -e cat -e grep $(FILE) | grep -E $(ERROR)
	$(CHECK) ./s21_grep -f $(PATTERNS) $(FILE) | grep -E $(ERROR)
	

clean:
	rm -f *.o s21_grep