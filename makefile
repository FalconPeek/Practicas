# =========================
# Makefile simple funcional
# =========================
# Uso:
#   make run
#       -> compila y ejecuta main.c
#
#   make ./archivo.c
#       -> compila y ejecuta ./archivo.c
#
#   make clean
#       -> borra la carpeta build/
#
# Estructura de build:
#   build/obj/*.o   objetos compilados
#   build/bin/*     ejecutables generados
#
# Requisitos:
#   - cc / gcc disponible en WSL
#   - este makefile guardado con tabs en las recetas

CC      := cc
CFLAGS  := -std=c99 -Wall -Wextra -Wpedantic -O2 -I./includes -I./TAD
BUILD   := build
OBJDIR  := $(BUILD)/obj
BINDIR  := $(BUILD)/bin

# Todos los .c que existan en la carpeta actual
SRCS    := $(wildcard *.c)

# Módulos = todos los .c que no se llamen main.c (para poder linkear funciones comunes)
MODULES := $(filter-out %main.c,$(SRCS))

# Target por defecto si hacés sólo "make"
.DEFAULT_GOAL := help

help:
	@echo "Comandos disponibles:"
	@echo "  make run                -> compila y ejecuta main.c"
	@echo "  make ./archivo.c        -> compila y ejecuta ese .c como main"
	@echo "  make clean              -> borra build/"
	@echo ""
	@echo "Ejemplos:"
	@echo "  make run"
	@echo "  make ./main.c"
	@echo "  make ./otro_main.c"

# ------------------------------
# make run  -> usa main.c
# ------------------------------
run:
	@$(MAKE) --no-print-directory _exec FILE="main.c"

# -----------------------------------------
# make ./archivo.c  -> usa ese archivo .c
# Este patrón capta cualquier objetivo que termine en .c
# Ej: make ./test.c  o make demo.c
# -----------------------------------------
%.c:
	@$(MAKE) --no-print-directory _exec FILE="$@"

# ------------------------------
# clean  -> rm -rf build
# ------------------------------
clean:
	rm -rf $(BUILD)

# -----------------------------------------
# _exec:
#   1. Crea build/
#   2. Compila todos los módulos comunes (los .c que NO sean el main elegido)
#   3. Compila el main elegido
#   4. Linkea todo en un binario único
#   5. Ejecuta el binario
# -----------------------------------------
_exec:
	@set -e; \
	mkdir -p "$(OBJDIR)" "$(BINDIR)"; \
	echo "[build] $$FILE"; \
	mods=""; \
	for f in $(MODULES); do \
		if [ "$$f" != "$$FILE" ]; then \
			obj="$(OBJDIR)/$${f%.c}.o"; \
			echo "  CC $$f -> $$obj"; \
			$(CC) $(CFLAGS) -c "$$f" -o "$$obj"; \
			mods="$$mods $$obj"; \
		fi; \
	done; \
	mainobj="$(OBJDIR)/$${FILE%.c}.o"; \
	echo "  CC $$FILE -> $$mainobj"; \
	$(CC) $(CFLAGS) -c "$$FILE" -o "$$mainobj"; \
	bin="$(BINDIR)/$${FILE%.c}"; \
	echo "  LD $$bin"; \
	$(CC) "$$mainobj" $$mods -o "$$bin"; \
	echo "[run] $$bin"; \
	echo ----------------------------------------------------------------------------------------------------------------------; \
	"$$bin"
