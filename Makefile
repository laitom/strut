CC=gcc
FLAGS=-c -Wall
LIBS=-lm

test_strut: strut.o test_strut.o
	$(CC) strut.o test_strut.o -o test_strut

strut.o: strut.c strut.h
	$(CC) $(FLAGS) $(LIBS) strut.c

test_strut.o: test_strut.c
	$(CC) $(FLAGS) $(LIBS) test_strut.c

clean:
	rm *.o test_strut
