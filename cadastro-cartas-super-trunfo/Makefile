CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -MMD -MP

TARGET = cadastro-cartas-super-trunfo
SOURCES = main.c carta.c entrada.c comparacao.c
OBJECTS = $(SOURCES:.c=.o)
DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)

-include $(DEPS)

.PHONY: all run clean
