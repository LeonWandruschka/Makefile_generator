#This file was automatically created!
#For more information go to: https://github.com/LeonWandruschka/Makefile_generator 
 
build: str.o files.o createmakefile.o 
	gcc main.c str.o files.o createmakefile.o -o Make_Generator

str.o:
	gcc str.c -c

files.o:
	gcc files.c -c

createmakefile.o:
	gcc createmakefile.c -c

clean:
	rm Make_Generator
	rm str.o
	rm files.o
	rm createmakefile.o

rebuild: clean build