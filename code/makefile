CC=gcc
CFLAGS=-Wall -Wextra
run: types.c stack.c operations/operations.h parser/parser.h
	$(CC) $(CFLAGS) -o exec -g *.c operations/*.c parser/*.c -lm
rem: exec
	rm exec