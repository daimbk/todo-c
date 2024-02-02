CC = gcc
CFLAGS = -Iinclude

INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

TARGET = $(BIN_DIR)/todo

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

$(TARGET): $(OBJS) | $(BIN_DIR)
    @$(CC) $(CFLAGS) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
    @$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
    rm -f $(BUILD_DIR)/*.o $(BIN_DIR)/todo
