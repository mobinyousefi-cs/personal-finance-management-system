/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      finance_app.c
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Main application loop and menu handling.
 * ===========================================================
 */

#include "finance_app.h"

#include <stdio.h>
#include <string.h>

#include "input.h"
#include "persistence.h"
#include "report.h"

static void print_transactions_header(void)
{
    printf("ID   | Date       | Type       | Category     |     Amount | Description\n");
    printf("-----+------------+------------+-------------+-----------+------------------------------\n");
}

static void list_all_transactions(const TransactionList *list)
{
    if (!list) {
        return;
    }
    if (list->size == 0) {
        printf("No transactions recorded yet.\n");
        return;
    }

    print_transactions_header();
    for (size_t i = 0; i < list->size; ++i) {
        transaction_print(&list->items[i]);
    }
}

static void add_transaction(TransactionList *list, TransactionType type)
{
    if (!list) {
        return;
    }

    Transaction t;
    memset(&t, 0, sizeof(t));
    t.type = type;

    printf("\nAdding new %s transaction\n", transaction_type_to_string(type));

    if (input_read_date("Date (YYYY-MM-DD, empty for today): ", &t.date) != 0) {
        printf("Failed to read date. Aborting.\n");
        return;
    }

    if (input_read_double("Amount: ", 0.01, 1e12, &t.amount) != 0) {
        printf("Failed to read amount. Aborting.\n");
        return;
    }

    if (input_read_line("Category (e.g., Salary, Rent, Food): ", t.category, sizeof(t.category)) != 0) {
        printf("Failed to read category. Aborting.\n");
        return;
    }
    if (t.category[0] == '\0') {
        strncpy(t.category, "General", sizeof(t.category) - 1);
        t.category[sizeof(t.category) - 1] = '\0';
    }

    if (input_read_line("Description: ", t.description, sizeof(t.description)) != 0) {
        printf("Failed to read description. Aborting.\n");
        return;
    }

    Transaction *stored = tx_list_add(list, &t);
    if (stored) {
        printf("Transaction added with ID %d.\n", stored->id);
    }
}

static void show_overall_summary(const TransactionList *list)
{
    SummaryReport r;
    report_compute_overall(list, &r);
    report_print(&r, "Overall summary");
}

static void show_monthly_summary(const TransactionList *list)
{
    int year = 0;
    int month = 0;
    if (input_read_int("Year (e.g., 2025): ", 1900, 3000, &year) != 0) {
        printf("Failed to read year.\n");
        return;
    }
    if (input_read_int("Month (1-12): ", 1, 12, &month) != 0) {
        printf("Failed to read month.\n");
        return;
    }

    SummaryReport r;
    report_compute_monthly(list, year, month, &r);

    char title[64];
    snprintf(title, sizeof(title), "Summary for %04d-%02d", year, month);
    report_print(&r, title);
}

static void print_main_menu(void)
{
    printf("\nMain menu:\n");
    printf("  1) Add income\n");
    printf("  2) Add expense\n");
    printf("  3) Add investment\n");
    printf("  4) List all transactions\n");
    printf("  5) Show overall summary\n");
    printf("  6) Show monthly summary\n");
    printf("  7) Save and exit\n");
}

void finance_app_run(const char *data_file)
{
    TransactionList list;
    tx_list_init(&list);

    if (tx_list_load(&list, data_file) == 0) {
        printf("Loaded %zu transactions from '%s'.\n", list.size, data_file);
    } else {
        printf("Starting with an empty transaction list.\n");
    }

    int running = 1;
    while (running) {
        print_main_menu();
        int choice = 0;
        if (input_read_int("\nSelect an option: ", 1, 7, &choice) != 0) {
            printf("Input error. Exiting.\n");
            break;
        }

        switch (choice) {
        case 1:
            add_transaction(&list, TXN_INCOME);
            break;
        case 2:
            add_transaction(&list, TXN_EXPENSE);
            break;
        case 3:
            add_transaction(&list, TXN_INVESTMENT);
            break;
        case 4:
            list_all_transactions(&list);
            break;
        case 5:
            show_overall_summary(&list);
            break;
        case 6:
            show_monthly_summary(&list);
            break;
        case 7:
            if (tx_list_save(&list, data_file) == 0) {
                printf("Data saved to '%s'.\n", data_file);
            } else {
                printf("Failed to save data to '%s'.\n", data_file);
            }
            running = 0;
            break;
        default:
            printf("Unknown option.\n");
            break;
        }

        if (running) {
            input_wait_for_enter();
        }
    }

    tx_list_free(&list);
}
