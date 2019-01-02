#pragma once
#include "vec2.h"

class vehicle{
	point pos;
	vec2 vel;
	vec2 acc;
	point target[2];
	float desire[2];

	public:
		vehicle(point,point, vec2, point*, float, float);

		void update(vec2, point, point);

		vec2 getDesireVec(point, point, point);

		point getPos();
};