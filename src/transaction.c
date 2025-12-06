/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      transaction.c
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Implementation of transaction utilities.
 * ===========================================================
 */

#include "transaction.h"

#include <stdio.h>

const char *transaction_type_to_string(TransactionType type)
{
    switch (type) {
    case TXN_INCOME:
        return "INCOME";
    case TXN_EXPENSE:
        return "EXPENSE";
    case TXN_INVESTMENT:
        return "INVESTMENT";
    default:
        return "UNKNOWN";
    }
}

int transaction_type_from_int(int value, TransactionType *out)
{
    if (!out) {
        return -1;
    }
    switch (value) {
    case 1:
        *out = TXN_INCOME;
        return 0;
    case 2:
        *out = TXN_EXPENSE;
        return 0;
    case 3:
        *out = TXN_INVESTMENT;
        return 0;
    default:
        return -1;
    }
}

void transaction_print(const Transaction *t)
{
    if (!t) {
        return;
    }

    char date_buf[16];
    date_to_string(&t->date, date_buf, sizeof(date_buf));

    printf("%-4d | %s | %-10s | %-12s | %10.2f | %s\n",
           t->id,
           date_buf,
           transaction_type_to_string(t->type),
           t->category,
           t->amount,
           t->description);
}
