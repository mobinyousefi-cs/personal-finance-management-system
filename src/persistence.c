/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      persistence.c
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Implementation of dynamic container and CSV persistence for
 *   financial transactions.
 * ===========================================================
 */

#include "persistence.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 32

static void tx_list_ensure_capacity(TransactionList *list, size_t min_capacity)
{
    if (list->capacity >= min_capacity) {
        return;
    }
    size_t new_capacity = list->capacity ? list->capacity * 2 : INITIAL_CAPACITY;
    if (new_capacity < min_capacity) {
        new_capacity = min_capacity;
    }
    Transaction *new_items = (Transaction *)realloc(list->items, new_capacity * sizeof(Transaction));
    if (!new_items) {
        fprintf(stderr, "[ERROR] Out of memory while resizing transaction list.\n");
        exit(EXIT_FAILURE);
    }
    list->items = new_items;
    list->capacity = new_capacity;
}

void tx_list_init(TransactionList *list)
{
    if (!list) {
        return;
    }
    list->items = NULL;
    list->size = 0;
    list->capacity = 0;
    list->next_id = 1;
}

void tx_list_free(TransactionList *list)
{
    if (!list) {
        return;
    }
    free(list->items);
    list->items = NULL;
    list->size = 0;
    list->capacity = 0;
    list->next_id = 1;
}

Transaction *tx_list_add(TransactionList *list, const Transaction *src)
{
    if (!list || !src) {
        return NULL;
    }
    tx_list_ensure_capacity(list, list->size + 1);
    Transaction *dst = &list->items[list->size++];
    *dst = *src;
    if (dst->id <= 0) {
        dst->id = list->next_id++;
    } else if (dst->id >= list->next_id) {
        list->next_id = dst->id + 1;
    }
    return dst;
}

Transaction *tx_list_find_by_id(TransactionList *list, int id)
{
    if (!list || id <= 0) {
        return NULL;
    }
    for (size_t i = 0; i < list->size; ++i) {
        if (list->items[i].id == id) {
            return &list->items[i];
        }
    }
    return NULL;
}

static int parse_csv_line(char *line, Transaction *out)
{
    /* CSV format: id;date;type;category;description;amount */
    char *token = NULL;
    char *rest = line;
    int field = 0;

    Transaction t;
    memset(&t, 0, sizeof(t));

    while ((token = strtok_r(rest, ";", &rest))) {
        switch (field) {
        case 0:
            t.id = atoi(token);
            break;
        case 1:
            if (date_from_string(token, &t.date) != 0) {
                return -1;
            }
            break;
        case 2:
            t.type = (TransactionType)atoi(token);
            break;
        case 3:
            strncpy(t.category, token, MAX_CATEGORY_LEN - 1);
            t.category[MAX_CATEGORY_LEN - 1] = '\0';
            break;
        case 4:
            strncpy(t.description, token, MAX_DESC_LEN - 1);
            t.description[MAX_DESC_LEN - 1] = '\0';
            break;
        case 5:
            t.amount = atof(token);
            break;
        default:
            break;
        }
        field++;
    }

    if (field < 6) {
        return -1;
    }

    *out = t;
    return 0;
}

int tx_list_load(TransactionList *list, const char *filename)
{
    if (!list || !filename) {
        return -1;
    }

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        /* File does not exist yet -> start with empty list. */
        tx_list_free(list);
        tx_list_init(list);
        return 0;
    }

    tx_list_free(list);
    tx_list_init(list);

    char buffer[512];
    while (fgets(buffer, sizeof(buffer), fp)) {
        /* Strip newline */
        size_t len = strlen(buffer);
        if (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == '\r')) {
            buffer[len - 1] = '\0';
        }

        Transaction t;
        if (parse_csv_line(buffer, &t) == 0) {
            tx_list_add(list, &t);
        }
    }

    fclose(fp);
    return 0;
}

int tx_list_save(const TransactionList *list, const char *filename)
{
    if (!list || !filename) {
        return -1;
    }
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "[ERROR] Cannot open '%s' for writing.\n", filename);
        return -1;
    }

    for (size_t i = 0; i < list->size; ++i) {
        const Transaction *t = &list->items[i];
        char date_buf[16];
        date_to_string(&t->date, date_buf, sizeof(date_buf));
        fprintf(fp, "%d;%s;%d;%s;%s;%.2f\n",
                t->id,
                date_buf,
                (int)t->type,
                t->category,
                t->description,
                t->amount);
    }

    fclose(fp);
    return 0;
}
