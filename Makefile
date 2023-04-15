CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

OBJ = main.o
HDR = bibliotecas/file.h bibliotecas/ponto.h bibliotecas/retas.h

all: hipercampos

hipercampos: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o hipercampos

main.o: main.c $(HDR)
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f $(OBJ) hipercampos output.txt
