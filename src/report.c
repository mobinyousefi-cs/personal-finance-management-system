/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      report.c
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Implementation of reporting utilities.
 * ===========================================================
 */

#include "report.h"

#include <stdio.h>
#include <string.h>

static void report_reset(SummaryReport *r)
{
    if (!r) {
        return;
    }
    r->total_income = 0.0;
    r->total_expense = 0.0;
    r->total_investment = 0.0;
    r->net_cashflow = 0.0;
}

void report_compute_overall(const TransactionList *list, SummaryReport *out)
{
    if (!list || !out) {
        return;
    }
    report_reset(out);

    for (size_t i = 0; i < list->size; ++i) {
        const Transaction *t = &list->items[i];
        switch (t->type) {
        case TXN_INCOME:
            out->total_income += t->amount;
            out->net_cashflow += t->amount;
            break;
        case TXN_EXPENSE:
            out->total_expense += t->amount;
            out->net_cashflow -= t->amount;
            break;
        case TXN_INVESTMENT:
            out->total_investment += t->amount;
            out->net_cashflow -= t->amount;
            break;
        default:
            break;
        }
    }
}

void report_compute_monthly(const TransactionList *list, int year, int month, SummaryReport *out)
{
    if (!list || !out) {
        return;
    }
    report_reset(out);

    for (size_t i = 0; i < list->size; ++i) {
        const Transaction *t = &list->items[i];
        if (t->date.year == year && t->date.month == month) {
            switch (t->type) {
            case TXN_INCOME:
                out->total_income += t->amount;
                out->net_cashflow += t->amount;
                break;
            case TXN_EXPENSE:
                out->total_expense += t->amount;
                out->net_cashflow -= t->amount;
                break;
            case TXN_INVESTMENT:
                out->total_investment += t->amount;
                out->net_cashflow -= t->amount;
                break;
            default:
                break;
            }
        }
    }
}

void report_print(const SummaryReport *report, const char *title)
{
    if (!report) {
        return;
    }

    if (title && title[0] != '\0') {
        printf("\n==== %s ====\n", title);
    }

    printf("Total income:      %12.2f\n", report->total_income);
    printf("Total expenses:    %12.2f\n", report->total_expense);
    printf("Total investments: %12.2f\n", report->total_investment);
    printf("-------------------------------------\n");
    printf("Net cash flow:     %12.2f\n", report->net_cashflow);
}
