#include "vehicle.h"

#ifndef Desire_MIN
#define Desire_MIN -1
#endif // !Desire_MIN
#ifndef Desire_MAX
#define Desire_MAX 1
#endif // !Desire_MAX

vehicle::vehicle(point _pos, point _vel, vec2 _acc, point* _target, float _foodDesire, float _badDesire){
	pos.set(_pos.getx(), pos.gety());
	vel.setup(pos, _vel);
	acc = _acc;
	target[0] =  _target[0];//food
	target[1] = _target[1];//bad
	if(_foodDesire && _badDesire){
		desire[0]=_foodDesire;
		desire[1]=_badDesire;
	}else{
		for(int i; i<2; i++)
		{
			desire[i]= Desire_MIN + rand()% Desire_MAX;//some error, debug
		}
	}
}

void vehicle::update(vec2 _des, point _food, point _bad){
	pos.set(
				pos.getx() + vel.getCompx(),
				pos.gety() + vel.getCompy()
	);
	vel.add(acc);
	acc.add(_des);
	target[0]=_food;
	target[1]=_bad;
}

vec2 vehicle::getDesireVec(point _pos, point _food, point _bad){
	//pointer to food+pointer away from bad calculating magnitude from desire of both (maybe distance as well?)
	vec2 toFood(_pos.getx(), _pos.gety(), _food.getx(), _food.gety());
	vec2 toBad(_pos.getx(), _pos.gety(), _bad.getx(), _bad.gety());
	toFood.mul(desire[0]);
	toBad.mul(desire[1]);
	toFood.add(toBad);
	return toFood;
}

point vehicle::getPos(){
	return pos;
}