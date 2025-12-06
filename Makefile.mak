# ============================================================
# Project:   Personal Finance Management System (C)
# File:      Makefile
# Author:    Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
# Created:   2025-12-06
# License:   MIT License
# ============================================================
# Description:
#   Build configuration for the PFMS console application.
#   Usage:
#       make        # build the pfms binary
#       make clean  # remove objects and binary
# ============================================================

CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -Iinclude
LDFLAGS :=

SRC_DIR := src
OBJ_DIR := obj
BIN     := pfms

SRC := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/date.c \
	$(SRC_DIR)/transaction.c \
	$(SRC_DIR)/persistence.c \
	$(SRC_DIR)/report.c \
	$(SRC_DIR)/input.c \
	$(SRC_DIR)/finance_app.c

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN)
