CC=gcc
CFLAGS=-Wall -Wextra
OTHER=-c $(CFLAGS)
DEPS= control_types.h stack/stack.h

run: main.o operations.o parser.o stack.o
	$(CC) $(CFLAGS) -o exec -g %.o $(DEPS) -lm

main.o: $(DEPS) main.c
	$(CC) $(OTHER) *.h main.c

stack.o: $(DEPS)
	$(CC) $(OTHER)

operations.o: $(DEPS) operations/%.c
	$(CC) $(OTHER) operations/%.c

parser.o: $(DEPS) parser/%.c
	$(CC) $(OTHER) parser/*.h

rem: exec
	rm exec