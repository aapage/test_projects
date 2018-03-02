program5.exe: SchoolClass.o RectangularEntityClass.o ColorClass.o PixelLocationClass.o HouseClass.o MapClass.o ParkClass.o RoadClass.o Main.o
	g++  ColorClass.o PixelLocationClass.o HouseClass.o MapClass.o ParkClass.o RectangularEntityClass.o SchoolClass.o RoadClass.o Main.o -o program5.exe

ColorClass.o:  ColorClass.cpp
	g++ -c  ColorClass.cpp -o  ColorClass.o

MapClass.o:  MapClass.cpp
	g++ -c MapClass.cpp -o  MapClass.o

ParkClass.o: ParkClass.cpp
	g++ -c ParkClass.cpp -o ParkClass.o

PixelLocationClass.o: PixelLocationClass.cpp	
	g++ -c PixelLocationClass.cpp -o PixelLocationClass.o

HouseClass.o: HouseClass.cpp
	g++ -c HouseClass.cpp -o HouseClass.o

RectangularEntityClass.o: RectangularEntityClass.cpp
	g++ -c RectangularEntityClass.cpp -o RectangularEntityClass.o

SchoolClass.o: SchoolClass.cpp
	g++ -c SchoolClass.cpp -o SchoolClass.o

RoadClass.o: RoadClass.cpp
	g++ -c RoadClass.cpp -o RoadClass.o

main.o: Main.cpp
	g++ -c Main.cpp -o Main.o


clean:
	rm -rf ColorClass.o HouseClass.o MapClass.o ParkClass.o PixelLocationClass.o SchoolClass.o RoadClass.o  Main.o program5.exe