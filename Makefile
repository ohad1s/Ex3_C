CC=gcc
FLAGS= -Wall -g

all:stringProg

stringProg: main.o libmy_str.a
	$(CC) $(FLAGS) -o stringProg main.o libmy_str.a

libmy_str.a: my_str.o
	ar -rcs libmy_str.a my_str.o

main.o: main.c my_str.h
	$(CC) $(FLAGS) -c main.c

my_str.o: my_str.c my_str.h
	$(CC) $(FLAGS) -c my_str.c

.PHONY: clean all

clean:
	rm -f *.o *.a stringProg