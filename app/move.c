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
int move(text txt, int line, int pos) 
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return 0;
    } 
    
    /* Стартуем с начальной строки текста */
    node* current = txt->begin;
    int index = 0;
    
    while (current) {
        if (index == line) {
            if (pos >= (int)strlen(current -> contents) || pos < 0) {
                return 1;
            } 
            else {
                txt->cursor->line = current;
                txt->cursor->position = pos;
                
                return 0;
            }
        }
        current = current->next;
        index++;
    }
    
    return 1;
}

