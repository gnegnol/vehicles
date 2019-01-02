#pragma once
#include <math.h>

class vec2 {
	int x;
	int y;

public:
	//constructors

	//empty constructor
	vec2();
	//cartesian constructor
	vec2(int, int);
	//polar constructor
	vec2(float, float);
	
	//methods
	int getx();
	int gety();
	//cartesian
	void set(int, int);
	//polar
	void set(float, float);

	void mul(float);
	void add(vec2);
	void sub(vec2);

	float getAngle();
	float getMagnitude();
};