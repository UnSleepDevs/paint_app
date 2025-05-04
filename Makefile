# Compilador y flags
CC = gcc
CFLAGS = -Wunused-parameter -Wall -Wextra -std=c99 -I. -Isrc -Isrc/Paint -Isrc/Pixel
LDFLAGS = -lncursesw -lm

# Archivos fuente
SRC = \
    src/main.c \
    src/Cursor/cursor.c \
    src/Cursor/cursor_details.c \
    src/Cursor/cursor_keyboard.c \
    src/Paint/color.c \
    src/tui/ncurses_utils.c \
    src/tui/statusbar.c \
    src/tui/help.c \
    src/tui/goto.c \
    src/utils.c \
    src/Paint/paint.c \
    src/Paint/line_mode.c \
    src/Pixel/pixel.c \
    src/Pixel/pixel_list.c 

# Archivos objeto generados
OBJ = $(SRC:.c=.o)

# Ejecutable final
TARGET = paint_app

# Regla por defecto
all: $(TARGET)

# Cómo construir el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Regla general para compilar .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	rm -f $(OBJ) $(TARGET)

# Regla útil para debug
debug: CFLAGS += -g
debug: $(TARGET)

runkitty: $(TARGET)
	@echo "Opening in kitty"
	kitty "./$(TARGET)"

run: $(TARGET)
	@echo "Opening"
	bash -c "./$(TARGET);bash exec"
.PHONY: all clean debug
