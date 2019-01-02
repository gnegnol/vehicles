#include "vec2.h"



				//constructors

	//empty constructor
vec2::vec2() {
	x = 0;
	y = 0;
}
	
	//cartesian constructor
vec2::vec2(int _x, int _y){		
	x = _x;
	y = _y;
}

	//polar constructor
vec2::vec2(float _angle, float _magnitude) {
	x = cos(_angle)*_magnitude;
	y = sin(_angle)*_magnitude;
}

				//methods

int vec2::getx() {
	return x;
}

int vec2::gety() {
	return y;
}
//cartesian
void vec2::set(int _x, int _y) {
	x = _x;
	y = _y;
}
//polar
void vec2::set(float _angle, float _module) {
	x = cos(_angle)*_magnitude;
	y = sin(_angle)*_magnitude;
}



void vec2::mul(float _m) {
	x *= _m;
	y *= _m;
}

void vec2::add(vec2 _adder) {
	x += _adder.getx;
	y += _adder.gety;
}


void vec2::sub(vec2 _adder) {
	x -= _adder.getx;
	y -= _adder.gety;
}



float vec2::getAngle() {
	return asin(y / vec2::getMagnitude());
}


float vec2::getMagnitude() {
	return sqrt(x * x + y * y);
}