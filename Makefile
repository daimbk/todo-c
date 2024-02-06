CC = gcc
CFLAGS = -Wall -g
INCLUDES = -Iinclude

INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# source files
INCLUDE_FILES = $(wildcard $(INCLUDE_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

EXECUTABLE = $(BIN_DIR)/todo

.PHONY: all clean format

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES) | $(BIN_DIR)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# INSTALL_DIR = ~/.todo
# install:
# 	@mkdir -p $(INSTALL_DIR)

# 	@# copy the executable to install dir
# 	@cp $(EXECUTABLE) $(INSTALL_DIR)/todo

# 	@echo "alias todo='$(INSTALL_DIR)/todo'" >> ~/.bashrc

# 	@echo "\ntodo installed successfully"
# 	@echo "Restart terminal session"
# 	@echo "Run 'todo help' to get started"

format:
	@clang-format -i $(INCLUDE_FILES) $(SRC_FILES)

clean:
	@rm -rf $(EXECUTABLE) $(BUILD_DIR) $(BIN_DIR)
