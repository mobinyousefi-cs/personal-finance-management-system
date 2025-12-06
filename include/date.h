/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      date.h
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Lightweight date handling utilities.
 * ===========================================================
 */

#ifndef DATE_H
#define DATE_H

#include <stddef.h>

/** Simple calendar date (no timezone). */
typedef struct Date {
    int year;
    int month;
    int day;
} Date;

/**
 * Parse a date from string in ISO format YYYY-MM-DD.
 *
 * @param str  Input string.
 * @param out  Parsed date on success.
 * @return 0 on success, non-zero on failure.
 */
int date_from_string(const char *str, Date *out);

/**
 * Format a date as ISO string YYYY-MM-DD.
 *
 * @param date     Date to format.
 * @param buffer   Destination buffer.
 * @param buf_size Buffer size.
 */
void date_to_string(const Date *date, char *buffer, size_t buf_size);

/**
 * Get today's date based on the system clock.
 */
Date date_today(void);

/**
 * Compare two dates.
 *
 * @return < 0 if a < b, 0 if equal, > 0 if a > b.
 */
int date_compare(const Date *a, const Date *b);

#endif /* DATE_H */
