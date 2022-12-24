#include "SpaceShip.h"

SpaceShip::SpaceShip()
{	// init spaceship coordinates
	int wid, hei;
	FsGetWindowSize(wid, hei);
	SpaceShip_x = wid / 2;
	SpaceShip_y = hei / 2;

	YsRawPngDecoder theDecoder;
	std::string filename = "Interstellar ship.png";
	if (theDecoder.Decode(filename.c_str()) == YSERR) {
		std::cout << "Error reading filename";
	}
	ship_wid = theDecoder.wid;
	ship_hei = theDecoder.hei;
	utils::loadTexture(theDecoder, ship);


}

void SpaceShip::Move(float x, float y)
{	// Function to move spaceship by giving a velocity
	SpaceShip_x += x;
	SpaceShip_y += y;
	// diag down right
}

void SpaceShip::paint(double time)
{	// function to paint the SpaceShip's various states

	// SpaceShip on Earth
	if (time < 15)
	{
		float angle = (time - 15) * 5;

		// Function to Adjust Spaceship position based on
		// velocity and time
		if (time - time_last_move > 0.1) {
			if (SpaceShip_x > 110) {
				Move(-2.2, 0.5);
			}
			time_last_move = time;
		}
		// Alpha Blending Spaceship object 
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		utils::showImage(ship, SpaceShip_x, SpaceShip_y, 150, 150, angle);
		glDisable(GL_BLEND);
	}


	// SpaceShip in Stair Loop
	else if (time > 15 && time < 19) {

		double reduction = (int)time % 10;

		// Angle to provide angular velocity
		float angle = (time - 15) * (100 - reduction);

		if (time - time_last_move1 > 0.1) {
			int wid, hei;
			FsGetWindowSize(wid, hei);
			Move(4.2,-0.5);
			time_last_move1 = time;
		}
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		utils::showImage(ship, SpaceShip_x, SpaceShip_y, 150, 150, angle);
		glDisable(GL_BLEND);
	}
	// move upto wormhole
	else if (time > 19 && time < 27) {
		double reduction = (int)time % 10;

		float angle = (time - 15) * (100 - reduction);
		if (time - time_last_move2 > 0.1) {
			Move(7, 0);
			time_last_move2 = time;
		}
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		utils::showImage(ship, SpaceShip_x, SpaceShip_y, 150, 150, angle);
		glDisable(GL_BLEND);
	}
	// dodge
	else if (time > 27 && time < 40) {
		float angle = (time - 5) * 5;

		if (time - time_last_move > 0.1) {
			if (SpaceShip_y > 50) {
				Move(-4.6, -4.8);
			}
			time_last_move = time;
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		utils::showImage(ship, SpaceShip_x, SpaceShip_y, 150, 150, angle);
		glDisable(GL_BLEND);

	}
	// in other dimension
	else if (time > 40 && time < 60) {

		double reduction = (int)time % 10;

		float angle = (time - 5) * (100+reduction);


		if (time - time_last_move > 1) {
			int wid, hei;
			FsGetWindowSize(wid, hei);
			SpaceShip_x = wid / 2 - 50;
			SpaceShip_y = hei / 2;
			Move(0);
			time_last_move = time;
		}
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		utils::showImage(ship, SpaceShip_x-50, SpaceShip_y, 150, 150, angle);
		glDisable(GL_BLEND);
	}
}




