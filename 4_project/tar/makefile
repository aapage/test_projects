
CFLAGS= -g -Wall -Wextra

program4.exe: ParkClass.o random.o EventListClass.o EventClass.o RiderClass.o main.o
	g++  ParkClass.o EventListClass.o random.o EventCLass.o RiderClass.o main.o -o parkSimulation.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

RiderClass.o: RiderClass.cpp
	g++ -c RiderClass.cpp -o RiderClass.o

EventClass.o: EventClass.cpp
	g++ -c EventClass.cpp -o EventClass.o

random.o: random.cpp
	g++ -c random.cpp -o random.o

EventListClass.o: EventListClass.cpp
	g++ -c EventListClass.cpp -o EventListClass.o

ParkClass.o: ParkClass.cpp
	g++ -c ParkClass.cpp -o ParkClass.o

clean:
	rm -rf main.o RiderClass.o EventClass.o EventListClass.o random.o ParkClass.o parkSimulation.exe

