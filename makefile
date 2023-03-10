# File needed to compile simply the programm
#
# @authors Alice MABILLE, Benjamin PAUMARD, Matthieu VAYSSE, Djilali BAHOUS
# @version 1.0.0
# @since JFebrary, 2023

# defining constants
# compiler
CC = gcc

# source folder
SRC_DIR := src

# binary build
BUILD_DIR := build

# output folder
OUTPUT_DIR := output

# define flags to be used
# CFLAGS :=

# LFLAGS :=

# define the C source files
SOURCES := $(wildcard $(SRC_DIR)/*.c)

# define the C object files 
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

all: $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(OUTPUT_DIR)/main
	@echo "✅ Build complete 🥳"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c clean create-build-dir create-output-dir
	@$(CC) -c $< -o $@

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c
	@$(CC) -c $< -o $@

create-build-dir:
	@mkdir build
	@echo "✅ Created build directory"

create-output-dir:
	@mkdir output
	@echo "✅ Created output directory"

clean:
	@rm -rf $(BUILD_DIR) $(OUTPUT_DIR)
	@echo "✅ Cleaned build and output directories 🗑️"

run:
	@echo "🚀 executing main programm"
	@./output/main

doxygen:
	@doxygen
	@echo "✅ Documentation generated 📚"