/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Преобразует строку в целое положительное число
 */
int parse_convert(char* str, int *out);


/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Сохраняет содержимое в уазанный файл
 */
void save(text txt, char *filename);

/**
 * Двигает курсор в указанное место
 */
int move(text txt, int line, int pos);

/**
 * Двигает курсор на 1 влево если это возможно
 */
int mcb(text txt);

/**
 * Удаление последней строки текста
 */
int rt(text txt);

/**
 * Выводит содержимое указанного файла на экран в обратном порядке
 */
void showrev(text txt);


#endif
