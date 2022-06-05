/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text.h"
#include "_text.h"

static void show_line(int index, char *contents, int cursor, void *data);
/** 
 *  копипаста process_forward но в обратном порядке
 */
void process_forward_back(
    text txt,
    void (*process)(int index, char *contents, int cursor, void *data),
    void *data
);

/**
 * Выводит содержимое указанного файла на экран
 */
void showrev(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward_back(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    
    int slen = strlen(contents);
    int i = 0;

    for (i = 0; i < slen; i++) {
        if (i == cursor) printf("|");

        printf("%c", contents[i]);
    }
    if (i == cursor ) {
        printf("|");
    }
    printf("\n");
    return;
}

void process_forward_back(
    text txt,
    void (*process)(int index, char *contents, int cursor, void *data),
    void *data
)
{   
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с начальной строки текста */
    node *current = txt->end;
    int index = 0;
    int cursor_position = -1;
    
    /* К каждой строке текста применяем обработчик */
    while (current) {
        if (txt->cursor->line == current) 
            cursor_position = txt->cursor->position;
        else
            cursor_position = -1;
        process(index, current->contents, cursor_position, data);
        current = current->previous;
        index++;
    }
}
