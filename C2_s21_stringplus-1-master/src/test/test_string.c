#include "test_string.h"

int main(void) {
  int failed = 0;

  Suite *s21_string_test[] = {test_strlen(),          test_strcspn(),
                              test_strchr(),          test_strrchr(),
                              test_strpbrk(),         test_strstr(),
                              test_memchr(),          test_strerror(),
                              test_memcpy(),          test_memmove(),
                              test_memset(),          test_strncmp(),
                              test_memcmp(),          test_strncpy(),
                              test_strncat(),         test_strtok(),
                              test_sprintf(),         test_printU(),
                              test_printCSP(),        test_to_lower(),
                              test_to_upper(),        test_trim(),
                              test_insert(),          test_sprintf_c(),
                              test_sprintf_signed(),  test_sprintf_e(),
                              test_sprintf_f(),       test_sprintf_hex(),
                              test_sprintf_HEX(),     test_sprintf_signed_i(),
                              test_sprintf_n(),       test_sprintf_octal(),
                              test_sprintf_percent(), test_sprintf_pointer(),
                              test_sprintf_string(),  test_sprintf_unsigned(),
                              test_sprintff(),        NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf("\033[41m-========= FAILED: %d ==========-\033[0m\n", failed);

  return failed == 0 ? 0 : 1;
}