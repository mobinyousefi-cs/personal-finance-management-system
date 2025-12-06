/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      input.c
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Implementation of safe console input utilities.
 * ===========================================================
 */

#include "input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_read_line(const char *prompt, char *buffer, size_t size)
{
    if (!buffer || size == 0) {
        return -1;
    }
    if (prompt) {
        printf("%s", prompt);
    }
    if (!fgets(buffer, (int)size, stdin)) {
        return -1;
    }
    size_t len = strlen(buffer);
    if (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == '\r')) {
        buffer[len - 1] = '\0';
    }
    return 0;
}

int input_read_int(const char *prompt, int min, int max, int *out)
{
    if (!out) {
        return -1;
    }

    char line[128];
    while (1) {
        if (input_read_line(prompt, line, sizeof(line)) != 0) {
            return -1;
        }
        char *endptr = NULL;
        long value = strtol(line, &endptr, 10);
        if (endptr == line || *endptr != '\0') {
            printf("Invalid integer. Please try again.\n");
            continue;
        }
        if (value < min || value > max) {
            printf("Value must be between %d and %d. Please try again.\n", min, max);
            continue;
        }
        *out = (int)value;
        return 0;
    }
}

int input_read_double(const char *prompt, double min, double max, double *out)
{
    if (!out) {
        return -1;
    }

    char line[128];
    while (1) {
        if (input_read_line(prompt, line, sizeof(line)) != 0) {
            return -1;
        }
        char *endptr = NULL;
        double value = strtod(line, &endptr);
        if (endptr == line || *endptr != '\0') {
            printf("Invalid number. Please try again.\n");
            continue;
        }
        if (value < min || value > max) {
            printf("Value must be between %.2f and %.2f. Please try again.\n", min, max);
            continue;
        }
        *out = value;
        return 0;
    }
}

int input_read_date(const char *prompt, Date *out)
{
    if (!out) {
        return -1;
    }

    char line[128];
    while (1) {
        if (input_read_line(prompt, line, sizeof(line)) != 0) {
            return -1;
        }
        if (line[0] == '\0') {
            *out = date_today();
            return 0;
        }
        if (date_from_string(line, out) == 0) {
            return 0;
        }
        printf("Invalid date format. Expected YYYY-MM-DD. Please try again.\n");
    }
}

void input_wait_for_enter(void)
{
    printf("\nPress ENTER to continue...");
    fflush(stdout);
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}
