#include "test_string.h"

START_TEST(memcpy_1) {
  char s1[] = "";
  char s2[1] = "";
  ck_assert_ptr_eq(memcpy(s2, s1, 0), s21_memcpy(s2, s1, 0));
  ck_assert_str_eq(s2, s1);
}
END_TEST

START_TEST(memcpy_2) {
  char s1[] = "A";
  char s2[2] = {0};
  ck_assert_ptr_eq(memcpy(s2, s1, 1), s21_memcpy(s2, s1, 1));
  ck_assert_str_eq(s2, s1);
}
END_TEST

START_TEST(memcpy_3) {
  char s1[] = "Hello, world!";
  char s2[14] = {0};
  ck_assert_ptr_eq(memcpy(s2, s1, 14), s21_memcpy(s2, s1, 14));
  ck_assert_str_eq(s2, s1);
}
END_TEST

START_TEST(memcpy_4) {
  char s1[1000] = {0};
  char s2[1000] = {0};
  for (int i = 0; i < 1000; i++) {
    s1[i] = (char)(i % 256);
  }
  ck_assert_ptr_eq(memcpy(s2, s1, 1000), s21_memcpy(s2, s1, 1000));
  ck_assert_mem_eq(s2, s1, 1000);
}
END_TEST

START_TEST(memcpy_5) {
  char s1[] = "No bytes copied";
  char s2[17] = "";
  ck_assert_ptr_eq(memcpy(s2, s1, 0), s21_memcpy(s2, s1, 0));
}
END_TEST

START_TEST(memcpy_6) {
  char s2[25] = "Hello";
  const char s1[] = "zzzzz_world";
  const char src[] = "zzzzz_world";
  char dest[25] = "Hello";
  ck_assert_str_eq(memcpy((void *)dest, src, 6), s21_memcpy(s2, s1, 6));
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("\033[42m-=S21_MEMCPY=-\033[0m");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  tcase_add_test(tc, memcpy_6);

  suite_add_tcase(s, tc);
  return s;
}