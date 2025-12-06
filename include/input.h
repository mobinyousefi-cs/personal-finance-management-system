/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      input.h
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Safe input utilities for console interaction.
 * ===========================================================
 */

#ifndef INPUT_H
#define INPUT_H

#include <stddef.h>
#include "date.h"

int input_read_line(const char *prompt, char *buffer, size_t size);
int input_read_int(const char *prompt, int min, int max, int *out);
int input_read_double(const char *prompt, double min, double max, double *out);
int input_read_date(const char *prompt, Date *out);
void input_wait_for_enter(void);

#endif /* INPUT_H */
