#include "vehicle.h"

#ifndef Desire_MIN
#define Desire_MIN -1
#endif // !Desire_MIN
#ifndef Desire_MAX
#define Desire_MAX 1
#endif // !Desire_MAX

vec2 vehicle::getDesireVec(vec2 _food){
	vec2 result;
	result=_food;
	result.mul(desire);
	return result;
}

vehicle::vehicle(vec2 _pos, vec2 _vel, vec2 _acc, vec2 _target, float _foodDesire) {
	pos.set(_pos.getx(), pos.gety());
	vel.set(_vel.getx, _vel.gety);
	acc = _acc;
	target = _target;
	desire = _foodDesire;
}

vehicle::vehicle(vec2 _pos, vec2 _vel, vec2 _acc, vec2 _target) {
	pos.set(_pos.getx(), pos.gety());
	vel.set(_vel.getx, _vel.gety);
	acc = _acc;
	target = _target;
	desire = Desire_MIN + rand() % Desire_MAX;
}


void vehicle::update(vec2 _des, vec2 _target){
	pos.add(vel);
	vel.add(acc);
	acc.add(getDesireVec(_des));
	target = _target;
}


vec2 vehicle::getPos(){
	return pos;
}