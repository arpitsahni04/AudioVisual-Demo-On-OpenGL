#pragma once

#include "utils.h"


class SpaceShip {


protected:
	GLuint ship;
	float SpaceShip_x, SpaceShip_y;
	int ship_wid, ship_hei;
	double time_last_move = 2;
	double time_last_move1 = 15;
	double time_last_move2 = 23;

public:
	SpaceShip(); // loads files and inits configs

	void Move(float x=0, float y =0); // Moves the spaceship 
	
	void paint(double time); // Paints the SpaceShip






};