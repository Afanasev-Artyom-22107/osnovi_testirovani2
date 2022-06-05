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
 * Удаляет последнюю строку файла
 */
int rt(text txt) 
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return 0;
    } 
    if (txt -> length == 1) { // если текста нету
        remove_all(txt);
        return 0;
    }

    node *current = txt -> end; // берём последнюю строку
    current = current -> previous; // берём предпоследнюю
    current -> next = NULL; // следующей нету
    txt -> end = current; // теперь последняя - прошлая предпоследняя
    return 1;
}

