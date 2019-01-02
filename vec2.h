#pragma once
#include "point.h"
#include "math.h"

class vec2{
	point start;
	point end;

public:

	int getCompx();
	int getCompy();

	//costruttore
	vec2(int startx, int starty, int endx, int endy);
	vec2();

	void setup(point, point);

	float lenght();

	void add(vec2);

	void sub(vec2);

	void mul(float);
};