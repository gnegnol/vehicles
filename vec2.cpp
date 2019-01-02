#include "vec2.h"

int vec2::getCompx(){
	return end.getx() - start.getx();
}
int vec2::getCompy(){
	return end.gety() - start.gety();
}

//costruttore
vec2::vec2(int startx, int starty, int endx, int endy){
	start.set(startx, starty);
	end.set(endx, endy);
}
vec2::vec2(){
	start.set(0,0);
	end.set(0,0);
}

void vec2::setup(point _s, point _e){
	start.set(_s.getx(), _s.gety());
	end.set(_e.getx(), _e.gety());
}

float vec2::lenght(){
	return(sqrt(start.getx()*start.getx()+start.gety()*start.gety()));
}

void vec2::add(vec2 b){
	end.set(end.getx() + b.end.getx(), end.gety() + b.end.gety());
}

void vec2::sub(vec2 b){
	end.set(end.getx() - b.end.getx(), end.gety() - b.end.gety());
}

void vec2::mul(float _m){
	end.set(end.getx() + (vec2::getCompx() * _m), end.gety() + ( vec2::getCompy() *  _m));
}