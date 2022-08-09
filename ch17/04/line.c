/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* line.c (Chapter 15, page 364) */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

int line_len = 0;
int num_words = 0;

struct node {
    struct node *next;
    char words[];
}*line = NULL;

void clear_line(void)
{
    struct node *temp;
    while (line != NULL)
    {
        temp = line->next;
        free(line);
        line = temp;
    }
}

void add_word(const char *word)
{
    struct node *new_word, **p = &line;
    if ((new_word = malloc(sizeof(struct node) + strlen(word) + 1) == NULL)
        {
        printf("malloc error.\n");
        exit(EXIT_FAIlLURE);
    }
        
        strcpy(new_word->words, word);
        new_word->next = NULL;
        
        while (*pp != NULL)
        {
        *pp = (*pp)->next;
    }
        *pp = new_word;
        line_len+= strlen(word);
        if (num_words > 0)
        {
        line_len++;
    }
        num_words++;
    
        }
        
        int space_remaining(void)
        {
        return MAX_LINE_LEN - line_len;
    }
        
        void write_line(void)
        {
        int extra_spaces, spaces_to_insert, i, j;
        
        extra_spaces = MAX_LINE_LEN - line_len;
        for (i = 0; i < line_len; i++) {
            if (line[i] != ' ')
                putchar(line[i]);
            else {
                spaces_to_insert = extra_spaces / (num_words - 1);
                for (j = 1; j <= spaces_to_insert + 1; j++)
                    putchar(' ');
                extra_spaces -= spaces_to_insert;
                num_words--;
            }
        }
        putchar('\n');
    }
        
        void flush_line(void)
        {
        if (line_len > 0)
            puts(line);
    }
