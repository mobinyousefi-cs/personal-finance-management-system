/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      finance_app.h
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   High-level application interface for the Personal Finance
 *   Management System. Declares the main application loop.
 * ===========================================================
 */

#ifndef FINANCE_APP_H
#define FINANCE_APP_H

#define DATA_FILE "data/transactions.csv"

/**
 * Run the Personal Finance Management System.
 *
 * @param data_file Path to the CSV file used for persistent storage.
 */
void finance_app_run(const char *data_file);

#endif /* FINANCE_APP_H */
