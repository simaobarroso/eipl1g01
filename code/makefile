CC=gcc
CFLAGS=-Wall -Wextra
run: Main.c stack.c types.c operations/operations.h parser/parser.h
	$(CC) -o exec -g *.c */*.c -lm $< $(CFLAGS)
rem: exec
	rm exec
