CC = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -pedantic-errors -O0 -g -o
OBJS = control_types.c global_arrays.c guiao1.c guiao2.c guiao3.c guiao4.c guiao5.c main.c parser.c stack.c
TARGET = exec
LIBS = -lm

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $@ $^ $(LIBS)

rem:
	rm exec

# gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O0 -g operations/*.c stack/*.c parser/*.c *.c -lm