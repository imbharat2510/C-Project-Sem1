CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/login.c src/borrower.c src/equipment.c src/inventory.c src/main.c
OBJ = $(SRC:.c=.o)
TARGET = app

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

