#include <SDL2/SDL.h>
#include <iostream>
#include "vehicle.h"

#define TITLE "vehicles"
static int WIDTH=800;
static int HEIGHT=600;
static int VEHICLE_H=5;
static int VEHICLE_W=5;

//SDL variables
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;


bool init(){
	bool success =true;
	if(SDL_Init(SDL_INIT_VIDEO)!=0){
		success=false;
	}else{
		window=SDL_CreateWindow(TITLE,
						SDL_WINDOWPOS_UNDEFINED,
						SDL_WINDOWPOS_UNDEFINED,
						WIDTH,
						HEIGHT,
						0);
		if(window==nullptr){
			success=false;
		}
		renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
		if(renderer==nullptr){
			success=false;
		}
	}
	return success;
}

void close(){
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
}

void printPoint(point _p){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(renderer, _p.getx(), _p.gety());
	SDL_RenderPresent(renderer);
}

void printVehicle(vehicle _v){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_Rect rect;
	rect.x=_v.getPos().getx();
	rect.y=_v.getPos().gety();
	rect.h=VEHICLE_H;
	rect.w=VEHICLE_W;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

int main(){
	SDL_Event Events;
	bool q=true;
	int errCode=0;
	if(!init()){
		std::cerr<<"error in initialization"<<SDL_GetError()<<std::endl;
		errCode=-1;
	}else{
		//code
		vec2 e(0,0,0,0);
		point centre(WIDTH/2, HEIGHT/2);
		point start(rand()%WIDTH, rand()%HEIGHT);
		point targets[]={centre, point(0,0)};
		float foodD=1;
		float badD=0;
		vehicle testv(start, start, e, targets, foodD, badD);
		while(q){
			SDL_PollEvent(&Events);
			if(Events.type==SDL_QUIT){
				q=false;
			}
			printVehicle(testv);
			testv.update(testv.getDesireVec(testv.getPos(), centre, point(0,0)), centre, point(0,0));
	}
	}
	close();
	return errCode;
}