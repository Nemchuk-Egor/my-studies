#ifndef S21_CAT_LIB_H
#define S21_CAT_LIB_H

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения флагов командной строки
typedef struct {
    int b, n, s, E, T, v; // Флаги для опций командной строки
} Flag;

// Прототипы функций
void scan_flag(int argc, char **argv, Flag *flags); // Функция для сканирования и установки флагов
void print_error(const char *filename, int error_code); // Функция для вывода сообщений об ошибках
void print_file(const char *filename, Flag *flags); // Функция для печати содержимого файла с учетом флагов
void print_v(char c); // Вспомогательная функция для обработки и вывода управляющих символов

#endif  // S21_CAT_LIB_H