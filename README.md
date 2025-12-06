# Personal Finance Management System (PFMS)

A clean, modular, and production‑ready **Personal Finance Management System** written in C.
This project demonstrates professional‑grade software engineering practices, including:

* Modular architecture
* Dynamic memory management
* CSV-based persistence
* Robust input validation
* Reporting and aggregation utilities
* Maintainable and extensible codebase compatible with Linux, macOS, and Windows builds

---

## Table of Contents

* [Project Overview](#project-overview)
* [Features](#features)
* [Directory Structure](#directory-structure)
* [Build Instructions](#build-instructions)
* [Usage](#usage)
* [Data Persistence](#data-persistence)
* [Example Output](#example-output)
* [Future Improvements](#future-improvements)
* [License](#license)
* [Author](#author)

---

## Project Overview

The **Personal Finance Management System (PFMS)** helps users track income, expenses, and investments while providing detailed summaries of financial health.
The project is designed for clarity, extensibility, and compliance with academic and professional coding standards.
It fully aligns with the coding style expectations for a **Master’s-level Computer Science project**.

---

## Features

### Core Functionality

* Add **Income**, **Expense**, or **Investment** transactions
* Each transaction stores:

  * Date (ISO format: YYYY-MM-DD)
  * Type (income, expense, investment)
  * Category (e.g., Salary, Rent, Food)
  * Description
  * Amount
* Auto-generated unique IDs for all transactions

### Reporting

* **Overall Summary**:

  * Total Income
  * Total Expense
  * Total Investments
  * Net Cash Flow
* **Monthly Summary** for any year/month combination

### Data Handling

* Dynamic in-memory transaction list
* CSV-based persistence (`transactions.csv`)
* Safe and validated user input operations

### Engineering Features

* Clean, modular structure (headers + source files)
* Error-safe input system
* Memory-safe dynamic container
* Professional Makefile
* Fully documented code files

---

## Directory Structure

```
personal-finance-management-system/
├─ src/
│  ├─ main.c
│  ├─ finance_app.c
│  ├─ date.c
│  ├─ transaction.c
│  ├─ persistence.c
│  ├─ report.c
│  └─ input.c
├─ include/
│  ├─ finance_app.h
│  ├─ date.h
│  ├─ types.h
│  ├─ transaction.h
│  ├─ persistence.h
│  ├─ report.h
│  └─ input.h
├─ data/
│  └─ transactions.csv (generated automatically)
├─ obj/ (created during build)
├─ Makefile
└─ README.md
```

---

## Build Instructions

### Requirements

* GCC or Clang
* Make
* POSIX-compatible environment (Linux, macOS, WSL, MinGW)

### Build

```bash
make
```

This generates the binary:

```
pfms
```

### Clean build output

```bash
make clean
```

---

## Usage

Run the system:

```bash
./pfms
```

The main menu includes:

```
1) Add income
2) Add expense
3) Add investment
4) List all transactions
5) Show overall summary
6) Show monthly summary
7) Save and exit
```

The system automatically loads data from:

```
data/transactions.csv
```

If the file does not exist, it will be created.

---

## Data Persistence

Transactions are stored in CSV format using the fields:

```
id;date;type;category;description;amount
```

Example entry:

```
3;2025-02-18;2;Food;Lunch and groceries;42.50
```

This makes it easy to inspect or analyze the data with Excel, Python, or other tools.

---

## Example Output

### Listing Transactions

```
ID   | Date       | Type       | Category     |     Amount | Description
-----+------------+------------+--------------+------------+---------------------------
1    | 2025-02-18 | INCOME     | Salary       |    8500.00 | Monthly salary
2    | 2025-02-20 | EXPENSE    | Rent         |    3200.00 | Apartment rent
3    | 2025-02-21 | EXPENSE    | Food         |      42.50 | Lunch and groceries
```

### Overall Summary

```
==== Overall summary ====
Total income:         8500.00
Total expenses:       3242.50
Total investments:       0.00
-------------------------------------
Net cash flow:        5257.50
```

---

## Future Improvements

Here are some possible Phase‑2 enhancements:

* Category-based monthly or annual reports
* Export reports to PDF
* Transaction deletion or editing
* Budgeting tools per category
* Sorting and filtering tools
* Graphical visualization (GTK, Qt, or web UI)
* Encryption support for financial data
* Multi-user profiles

---

## License

This project is licensed under the **MIT License**.
You are free to use, modify, and distribute it with proper attribution.

---

## Author

**Mobin Yousefi**
GitHub: [github.com/mobinyousefi-cs](https://github.com/mobinyousefi-cs)

---

If you want, I can also generate:

* A GitHub‑ready badge‑rich README
* A Persian README
* A CLI usage GIF or ASCII demo
* A Phase‑2 Roadmap
* VSCode workspace + debug configuration
* A manpage-style do
