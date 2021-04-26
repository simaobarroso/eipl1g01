CC=gcc
CFLAGS=-Wall -Wextra
run: Main.c operations.c parser.c stack.c
	$(CC) -o exec *.c -lm $< $(CFLAGS)
rem: exec
	rm exec