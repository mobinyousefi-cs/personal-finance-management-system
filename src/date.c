/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      date.c
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Implementation of lightweight date utilities.
 * ===========================================================
 */

#include "date.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

int date_from_string(const char *str, Date *out)
{
    if (!str || !out) {
        return -1;
    }

    int y = 0, m = 0, d = 0;
    if (sscanf(str, "%d-%d-%d", &y, &m, &d) != 3) {
        return -1;
    }
    if (y < 1900 || m < 1 || m > 12 || d < 1 || d > 31) {
        return -1;
    }

    out->year = y;
    out->month = m;
    out->day = d;
    return 0;
}

void date_to_string(const Date *date, char *buffer, size_t buf_size)
{
    if (!date || !buffer || buf_size == 0) {
        return;
    }
    snprintf(buffer, buf_size, "%04d-%02d-%02d", date->year, date->month, date->day);
}

Date date_today(void)
{
    Date d;
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    if (lt) {
        d.year = lt->tm_year + 1900;
        d.month = lt->tm_mon + 1;
        d.day = lt->tm_mday;
    } else {
        d.year = 1970;
        d.month = 1;
        d.day = 1;
    }
    return d;
}

int date_compare(const Date *a, const Date *b)
{
    if (!a || !b) {
        return 0;
    }
    if (a->year != b->year) {
        return (a->year < b->year) ? -1 : 1;
    }
    if (a->month != b->month) {
        return (a->month < b->month) ? -1 : 1;
    }
    if (a->day != b->day) {
        return (a->day < b->day) ? -1 : 1;
    }
    return 0;
}
