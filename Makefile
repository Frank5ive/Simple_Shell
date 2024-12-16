CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -I include
SRC = src/main.c src/shell.c src/redirection.c src/piping.c
OBJ = $(SRC:.c=.o)
TARGET = simple_shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
