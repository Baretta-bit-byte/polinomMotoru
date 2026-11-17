CC = gcc
CFLAGS = -Wall -Wextra -g -fsanitize=address,undefined

polinom: main.c polynomial.c polynomial.h
	$(CC) $(CFLAGS) main.c polynomial.c -o polinom -lm

run: polinom
	./polinom

clean:
	rm -f polinom
