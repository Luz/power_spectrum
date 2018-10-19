all: main
	./main
main: main.c
	gcc -o main main.c -lfftw3
clean:
	rm -f main
