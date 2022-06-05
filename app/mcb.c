/**
 * move.c -- реализует перемещение курсора по файлу
 *
 * Copyright (c) 2022, Afanasev Artem
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text.h"
#include "_text.h"


/**
 * Выводит содержимое указанного файла на экран
 */
int mcb(text txt) 
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return 0;
    } 

    txt -> cursor -> position = 
    (txt -> cursor -> position == 0) ? 0 : txt -> cursor -> position - 1;
    return 1;

}

