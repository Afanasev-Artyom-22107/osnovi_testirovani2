/**
 * functions.c -- функция для парсинга двух параметров
 *
 * Copyright (c) 2022, Afanasev Artem
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"

#define BAD 1
#define GOOD 0

/**
 * Преобразует пару чисел в строке в два целых неотрицательных числа
 */
int parse_convert(char *str, int* param) {
    param[0] = param[1] = 0;
    int count = 0;
    int i = 0;
    int len = strlen(str);

    for (i = 1; i < len; i++) {
        count += (str[i - 1] == ' ' && str[i] >= '0' && str[i] <= '9');
    }

    if (count != 1) 
        return BAD;
    
    for (i = 0; str[i] != ' '; i++) {
        if (str[i] < '0' || str[i] > '9') 
            return BAD;
        param[0] = param[0] * 10 + str[i] - '0';
        if (param[0] > MAXLINE) 
            return BAD;
    }

    for (i++; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return BAD;
        param[1] = param[1] * 10 + str[i] - '0';
        if (param[1] > MAXLINE) 
            return BAD;
    }
    
    return GOOD;

    
}