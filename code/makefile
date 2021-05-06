CC = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -pedantic-errors -O0 -g
OBJS = main.o parser/parser.o operations/operations.o stack/stack.o control_types.o
TARGET = exec
LIBS = -lm

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o exec $@ $^ $(LIBS)

operations/operations.o: 
	$(CC) $(CFLAGS) *.c $(LIBS)

parser/parser.o:
	$(CC) $(CFLAGS) *.c $(LIBS)

rem:
	rm exec

# gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O0 -g operations/*.c stack/*.c parser/*.c *.c -lm