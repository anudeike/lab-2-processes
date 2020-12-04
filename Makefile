# lab-2-Signals/Makefile
# Ikechukwu Anude

output: main.o
	gcc main.o -o output

main.o: main.c
	gcc -c main.c

clean:
	*.o