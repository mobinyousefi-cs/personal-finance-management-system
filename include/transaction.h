/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      transaction.h
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Transaction structure and related utilities.
 * ===========================================================
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "types.h"

#define MAX_CATEGORY_LEN 32
#define MAX_DESC_LEN     128

/**
 * A single financial transaction.
 */
typedef struct Transaction {
    int id;                     /**< Unique identifier. */
    Date date;                  /**< Date of transaction. */
    TransactionType type;       /**< Income, expense, or investment. */
    char category[MAX_CATEGORY_LEN];
    char description[MAX_DESC_LEN];
    double amount;              /**< Positive amount in chosen currency. */
} Transaction;

/** Print a transaction in a human-readable tabular form. */
void transaction_print(const Transaction *t);

/** Convert transaction type to string. */
const char *transaction_type_to_string(TransactionType type);

/** Parse transaction type from integer menu choice. */
int transaction_type_from_int(int value, TransactionType *out);

#endif /* TRANSACTION_H */
