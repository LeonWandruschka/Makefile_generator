
build: str.o files.o
	gcc main.c str.o files.o -o main


str.o:
	gcc str.c -c

files.o:
	gcc files.c -c

clean:
	rm main
	rm str.o
	rm files.o

rebuild: clean build