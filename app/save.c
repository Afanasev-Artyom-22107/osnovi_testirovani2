/**
 * save.c - функция сохранения текста в файл
 * 
 * Copyright (c) 2022, Afanasev Artem
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include "common.h"
#include "text.h"

/**
 * Записывает строку в конец файла
 */
void print_line(int index, char *line, int cursor, void *data) {
    UNUSED(index);
    UNUSED(cursor);
    
    FILE *f = (FILE*)data;

    if (fprintf(f, "%s", line) < 0) {
        printf("The line cannot be wrote\n");
    }

    return;
}

/**
 * Сохраняет содержимое в указанный файл
 */
void save(text txt, char *filename) {
    FILE *f;
    
    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }
    void *data = (void*)f;

    process_forward(txt, print_line, data);

    fclose(f);
}
