/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      types.h
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Common type declarations used across the PFMS project.
 * ===========================================================
 */

#ifndef TYPES_H
#define TYPES_H

#include "date.h"

/** Transaction type (category at high level). */
typedef enum TransactionType {
    TXN_INCOME = 1,
    TXN_EXPENSE = 2,
    TXN_INVESTMENT = 3
} TransactionType;

#endif /* TYPES_H */
