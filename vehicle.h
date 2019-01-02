#pragma once
#include "vec2.h"

class vehicle{
	vec2 pos;
	vec2 vel;
	vec2 acc;
	vec2 target;
	float desire;

	vec2 getDesireVec(vec2);

public:

	vehicle(vec2, vec2, vec2, vec2, float);
	vehicle(vec2, vec2, vec2, vec2);

	void update(vec2, vec2);

	vec2 getPos();
};