# Set the C compiler
CC = gcc

all: readCSV.o
	./readCSV.o 20 8 matrix.csv

readCSV.o: readCSV.c
	$(CC) readCSV.c -o readCSV.o

clean:
	rm -f readCSV.o
