#include "point.h"

point::point(int _x, int _y){
	x=_x;
	y=_y;
}
point::point(){
	x=0;
	y=0;
}

int point::getx(){
	return x;
}
int point::gety(){
	return y;
}

void point::set(int _x, int _y){
	x=_x;
	y=_y;
}
