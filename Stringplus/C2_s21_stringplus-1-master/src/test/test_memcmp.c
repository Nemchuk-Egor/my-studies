#include "test_string.h"

START_TEST(memcmp_1) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  char str1[] = "hello";
  char str2[] = "hello";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  char str1[] = "hello";
  char str2[] = "world";
  s21_size_t n = 5;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_4) {
  char str1[] = "a";
  char str2[] = "b";
  s21_size_t n = 1;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_5) {
  char str1[] = "abcdef";
  char str2[] = "abcxyz";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  char str1[] = "hello world";
  char str2[] = "hello";
  s21_size_t n = 6;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_7) {
  char str1[] = "\x01\x02\x03";
  char str2[] = "\x01\x02\x04";
  s21_size_t n = 3;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_8) {
  char str1[] = "-123";
  char str2[] = "-456";
  s21_size_t n = 3;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_9) {
  char str1[] = "123";
  char str2[] = "456";
  s21_size_t n = 3;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_10) {
  char str1[] = "3.14";
  char str2[] = "2.71";
  s21_size_t n = 4;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(memcmp_11) {
  char str1[] = "hello world";
  char str2[] = "hello   world";
  s21_size_t n = 11;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_12) {
  char str1[] = "hello world";
  char str2[] = "hello";
  s21_size_t n = 100;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s = suite_create("\033[46m-=S21_MEMCMP=-\033[0m");

  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);
  tcase_add_test(tc, memcmp_11);
  tcase_add_test(tc, memcmp_12);

  suite_add_tcase(s, tc);  // Добавление тестового случая в набор тестов

  return s;  // Возврат созданного набора тестов
}