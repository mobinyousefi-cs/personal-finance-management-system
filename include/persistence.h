/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      persistence.h
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   In-memory container and file persistence for transactions.
 * ===========================================================
 */

#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <stddef.h>
#include "transaction.h"

/**
 * Dynamic array of transactions.
 */
typedef struct TransactionList {
    Transaction *items;
    size_t size;
    size_t capacity;
    int next_id;
} TransactionList;

void tx_list_init(TransactionList *list);
void tx_list_free(TransactionList *list);

/** Add a transaction (copy) to the list and return pointer to stored element. */
Transaction *tx_list_add(TransactionList *list, const Transaction *src);

/** Find a transaction by id or return NULL. */
Transaction *tx_list_find_by_id(TransactionList *list, int id);

/** Load transactions from CSV file into list (existing items are cleared). */
int tx_list_load(TransactionList *list, const char *filename);

/** Save transactions from list to CSV file. */
int tx_list_save(const TransactionList *list, const char *filename);

#endif /* PERSISTENCE_H */
