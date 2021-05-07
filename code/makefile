CC = gcc
EXEC = exec
CFLAGS = -std=gnu11 -Wall -Wextra -pedantic-errors -O0 -g -o $(EXEC)
OBJS = main.o parser/parser.o operations/operations.o stack/stack.o control_types.o
TARGET = exec
LIBS = -lm

run: $(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $@ $^ $(LIBS)

rem:
	rm exec

# gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O0 -g operations/*.c stack/*.c parser/*.c *.c -lm