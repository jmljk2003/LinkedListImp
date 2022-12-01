CFLAGS = -Wall -g
LDLIBS = 

SRC = dict1.c dict2.c listops.c array.c data.c

OBJ = $(SRC:.c=.o)

EXE = dict1
EXE = dict2

dict1: dict1.o listops.o data.o
	gcc -o dict1 dict1.o listops.o data.o

dict2: dict2.o listops.o data.o array.o
	gcc -o dict2 dict2.o listops.o data.o array.o

dict1.o: dict1.c
	gcc -c dict1.c

listops.o: listops.c listops.h
	gcc -c listops.c

data.o: data.c data.h
	gcc -c data.c

array.o: array.c array.h
	gcc -c array.c 

clean:
	rm -f $(EXE) $(OBJ)