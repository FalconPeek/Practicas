SHELL := /bin/sh

# ==== User configuration =====================================================
CC       ?= gcc
CSTD     ?= c11
CFLAGS   ?= -std=$(CSTD) -Wall -Wextra -Wpedantic -g
CPPFLAGS ?=
LDFLAGS  ?=
LDLIBS   ?=

# ==== Internal configuration =================================================
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj
BIN_DIR   := $(BUILD_DIR)/bin

# Header search paths (all project directories except the build folder)
INC_DIRS_RAW != find . -type d -not -path './$(BUILD_DIR)*' -not -path './.*'
INC_DIRS     := $(patsubst ./%,%,$(INC_DIRS_RAW))
CPPFLAGS     += $(addprefix -I,$(INC_DIRS))

# Gather module sources (translation units without a main function)
MODULE_SRC_RAW != sh -c 'find . -type f -name "*.c" -not -path "./$(BUILD_DIR)/*" -not -path "./.*" -print | while read -r file; do if ! grep -Eq "int[[:space:]]*main" "$$file"; then printf "%s\n" "$$file"; fi; done'
MODULE_SRC := $(patsubst ./%,%,$(MODULE_SRC_RAW))
MODULE_OBJ := $(MODULE_SRC:%.c=$(OBJ_DIR)/%.o)

.SECONDARY:

# Dependency files generated with -MMD -MP
DEPS := $(MODULE_OBJ:.o=.d)
DEPS += $(shell find $(OBJ_DIR) -type f -name '*.d' 2>/dev/null)

# Default target ----------------------------------------------------------------
.DEFAULT_GOAL := help

.PHONY: help
help:
	@echo "Usage:"
	@echo "  make path/to/file.c  # build and run the given translation unit"
	@echo "  make modules         # pre-build every reusable module"
	@echo "  make clean           # delete the build directory"

# Build every reusable module ---------------------------------------------------
.PHONY: modules
modules: $(MODULE_OBJ)

# Generic compilation rule ------------------------------------------------------
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

# Link rule: requested program + modules ---------------------------------------
$(BIN_DIR)/%: $(OBJ_DIR)/%.o $(MODULE_OBJ)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Allow `make something.c` ------------------------------------------------------
REQUESTED_SOURCES := $(filter %.c,$(MAKECMDGOALS))
RUN_PROG = $(patsubst %.c,%,$(patsubst ./%,%,$(SRC)))

.PHONY: $(REQUESTED_SOURCES)
$(REQUESTED_SOURCES):
	@$(MAKE) --no-print-directory __run SRC=$@

# Internal runner ---------------------------------------------------------------
.PHONY: __run
__run: $(BIN_DIR)/$(RUN_PROG)
	@echo "\n>> Running $(patsubst ./%,%,$(SRC))"
	./$(BIN_DIR)/$(RUN_PROG)

# Housekeeping -----------------------------------------------------------------
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Include auto-generated dependency files --------------------------------------
-include $(DEPS)
