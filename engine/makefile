
CFLAGS= -g -Wall -Wextra

program4.exe: Object3dClass.o main.o
	g++  Object3dClass.o main.o -o engine.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

RiderClass.o: Object3dClass.cpp
	g++ -c  Object3dClass.cpp -o Object3dClass.o

clean:
	rm -rf main.o Object3dClass.o engine.exe

