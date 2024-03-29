#Makefile
all: add-nbo

add-nbo: my_ntohl.o main.o
	g++ -o add-nbo main.o my_ntohl.o

main.o : my_ntohl.h main.cpp
	g++ -c -o main.o main.cpp

my_ntohl.o : my_ntohl.h my_ntohl.cpp
	g++ -c -o my_ntohl.o my_ntohl.cpp

clean:
	rm -f add-nbo
	rm -f *.o
