/*
 * ===========================================================
 * Project:   Personal Finance Management System (C)
 * File:      main.c
 * Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:   2025-12-06
 * License:   MIT License
 * ===========================================================
 * Description:
 *   Entry point of the Personal Finance Management System.
 *   Initializes the application and starts the main menu loop.
 * ===========================================================
 */

#include <stdio.h>
#include "finance_app.h"

int main(void)
{
    printf("===============================================\n");
    printf("  Personal Finance Management System (PFMS)\n");
    printf("===============================================\n\n");

    finance_app_run(DATA_FILE);

    printf("\nGoodbye. Stay financially healthy!\n");
    return 0;
}
