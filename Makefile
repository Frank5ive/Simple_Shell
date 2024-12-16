CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Iinclude
SRC = src/main.c src/shell.c
OBJ = $(SRC:.c=.o)
TARGET = simple_shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
