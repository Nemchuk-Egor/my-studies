#include "test_string.h"

START_TEST(strlen_1) {
  char str[] = "Hello world\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  char str[] = "Hello world\n\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  char str[] = "a\n\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  char str[] = " \n\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_5) {
  char str[] = " \0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_6) {
  char str[] = "\n\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_7) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

// Создание и конфигурация набора тестов для s21_strlen
Suite *test_strlen(void) {
  Suite *s =
      suite_create("\033[44m-=S21_STRLEN=-\033[0m");  // Создание нового набора
                                                      // тестов с именем
  TCase *tc =
      tcase_create("strlen_tc");  // Создание нового тестового случая с именем

  // Добавление тестов в тестовый случай
  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strlen_4);
  tcase_add_test(tc, strlen_5);
  tcase_add_test(tc, strlen_6);
  tcase_add_test(tc, strlen_7);

  suite_add_tcase(s, tc);  // Добавление тестового случая в набор тестов

  return s;  // Возврат созданного набора тестов
}
