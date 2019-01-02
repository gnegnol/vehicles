output:main.cpp ./obj/vehicle.o ./obj/vec2.o ./obj/point.o
	g++ -g main.cpp ./obj/vehicle.o ./obj/vec2.o ./obj/point.o -o output -lSDL2 -I. -o a.out

./obj/vehicle.o:vehicle.cpp vehicle.h ./obj/vec2.o
	g++ -g -shared vehicle.cpp ./obj/vec2.o ./obj/point.o -I. -o ./obj/vehicle.o

./obj/vec2.o:vec2.cpp vec2.h ./obj/point.o
	g++ -g -shared vec2.cpp ./obj/point.o -I. -o ./obj/vec2.o

./obj/point.o:point.cpp point.h
	g++ -g -shared point.cpp -o ./obj/point.o

clean:
	rm ./obj/*.o a.out

test:
	g++ -g main.cpp vehicle.cpp vec2.cpp point.cpp -o test -lSDL2 -I.

test2:
	g++ -g point.cpp vec2.cpp vehicle.cpp main.cpp -o test2 -lSDL2 -I.