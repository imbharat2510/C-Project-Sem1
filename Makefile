CC := gcc
CFLAGS := -Iinclude -Wall -Wextra -g
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, src/%.o, $(SRC))
TARGET := program

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f src/*.o $(TARGET)

