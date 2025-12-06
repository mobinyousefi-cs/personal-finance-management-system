/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      report.h
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Reporting utilities for summarizing financial health.
 * ===========================================================
 */

#ifndef REPORT_H
#define REPORT_H

#include "persistence.h"

typedef struct SummaryReport {
    double total_income;
    double total_expense;
    double total_investment;
    double net_cashflow;
} SummaryReport;

void report_compute_overall(const TransactionList *list, SummaryReport *out);
void report_compute_monthly(const TransactionList *list, int year, int month, SummaryReport *out);
void report_print(const SummaryReport *report, const char *title);

#endif /* REPORT_H */
