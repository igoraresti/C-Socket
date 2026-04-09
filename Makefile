CC = gcc
CFLAGS = -Iinclude -Wall
BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

CLIENT_SRC = $(SRC_DIR)/client/main.c
SERVER_SRC = $(SRC_DIR)/server/main.c

CLIENT_BIN = $(BIN_DIR)/client
SERVER_BIN = $(BIN_DIR)/server

.PHONY: all clean

all: $(CLIENT_BIN) $(SERVER_BIN)

$(CLIENT_BIN): $(CLIENT_SRC)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(SERVER_BIN): $(SERVER_SRC)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
