CC=gcc
OBJECTS_MAIN_TRIE=mains.o trie.o
FLAGS= -Wall -g

all: txtfind isort

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

isort: isort.o
	$(CC) $(FLAGS) isort.o -o isort

txtfind: txtfind.o txtfind.h
	$(CC) $(FLAGS) txtfind.o -o txtfind

.PHONY: clean all

clean:
	rm -f *.o  *.out isort txtfind