#include "background.h"
#include <string>
#include "ysglfontdata.h"
background::background()
{

	// Load all textures 
	YsRawPngDecoder theDecoder;

	theDecoder.Decode("BG.png");
	BG_wid = theDecoder.wid;
	BG_hei = theDecoder.hei;
	utils::loadTexture(theDecoder, BG1);

	theDecoder.Decode("BG2.png");
	utils::loadTexture(theDecoder, BG2);

	theDecoder.Decode("WormHole.png");
	utils::loadTexture(theDecoder, Wormhole);


	theDecoder.Decode("asteroidgray.png");
	utils::loadTexture(theDecoder, Asteroid);

	theDecoder.Decode("assignment.png");
	utils::loadTexture(theDecoder, assignment);

	theDecoder.Decode("cmu.png");
	utils::loadTexture(theDecoder, Logo);

	theDecoder.Decode("CMU_Build.png");
	utils::loadTexture(theDecoder, BG3);

	// load frames for stair steps
	for (int i = 0; i < 15; i++) {
		std::string filename = "frame_" + std::to_string(i) + "_delay-0.04s.png";
		if (theDecoder.Decode(filename.c_str()) == YSERR) {
			std::cout << "Error reading filename";
		}

		utils::loadTexture(theDecoder, frames[i]);
	}
	// load frames for Explosion
	for (int i = 0; i < 51; i++) {
		std::string filename = "explosion_" + std::to_string(i) + "_delay-0.1s.png";
		if (theDecoder.Decode(filename.c_str()) == YSERR) {
			std::cout << "Error reading filename";
		}

		utils::loadTexture(theDecoder, Explosion[i]);
	}

}



void background::paint(double time)
{
	// background picture of earth
	if (time < 15)
	{
		utils::showImage(BG2, 0, 0, 800, 600);
	}
	// inside blackhole
	else if (time > 15 and time < 40) {

		if (time - time_last_frame > 0.01) {

			curFrame++;
			curFrame = curFrame % 15;
			time_last_frame = time;
		}
		utils::showImage(frames[curFrame], 0, 0, 800, 600);
		// asteroid attack
		if (time > 18 and time < 29) {

			if (time - time_last_asteriod > 0.1) {
				asteroid_y += 5;
				time_last_asteriod = time;
			}

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			utils::showImage(Asteroid, 380, asteroid_y, 50, 50);
			glDisable(GL_BLEND);

		}

	}

	// Show Worm Hole Spinning
	if (time > 30 && time < 45) {

		float angle = (time - 30) * 50;
		// WormHole Appears
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		utils::showImage(Wormhole, 260, 25, 200, 200, angle);
		Worm_hole_angle += 0.01;
		glDisable(GL_BLEND);

	}
	// SHow CMU background
	if (time > 42 && time <60) {
		utils::showImage(BG3, 0, 0, 800, 600);

	}
	// Logo 
	if (time > 45 and time < 60) {
		utils::showImage(Logo, 320, 100, 100, 100);
	}

	// Assignement attack
	if (time > 50 && time < 60) {

		if (time - time_last_assignment > 0.2) {
			assignment_y += 5;
			time_last_assignment = time;
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		utils::showImage(assignment, 320, assignment_y, 50, 50);
		glDisable(GL_BLEND);
	}

	// Explosion
	else if (time > 60 and time < 80) {

		if (time - time_last_explosion > 0.01) {
			// cycling through the frames based on time
			curFrame_explosion++;
			curFrame_explosion = curFrame_explosion % 51;
			time_last_explosion = time;
		}
		utils::showImage(Explosion[curFrame_explosion], 0, 0, 800, 600);
	}

}


void background::draw_dialogue(double time)
{	// function to draw dialogues based on time
	if (time <= 10) {
		Thefont.setColorRGB(1, 0, 0);
		Thefont.drawText(" Earth is Done for!, We gotta get out", 30, 100, 0.3);
	}
	else if (time >= 10 && time <= 15) {
		Thefont.setColorRGB(1, 1, 0);
		Thefont.drawText("BRACE YOURSELF!", 30, 100, 0.3);
	}
	else if (time >= 25 && time <= 35) {
		Thefont.setColorRGB(1, 1, 0);
		Thefont.drawText("That Was Close, Close to being boring aha! "
			, 30, 100, 0.3);
	}
	else if (time >= 35 && time <= 40) {
		Thefont.setColorRGB(1, 1, 0);
		Thefont.drawText("Hey I gotta Jump in this Wormhole"
			, 30, 100, 0.3);
		Thefont.setColorRGB(1, 1, 0);
		Thefont.drawText("OR Imma LOOP Forever"
			, 30, 200, 0.3);
	}
	else if (time >= 40 && time <= 45) {
		Thefont.setColorRGB(1, 0.5, 0);
		Thefont.drawText("Got out Finally"
			, 30, 200, 0.3);
	}
	else if (time >= 50 && time <= 55) {
		Thefont.setColorRGB(1, 0.5, 0);
		Thefont.drawText("Huh there's a weird vibe here.. "
			, 30, 200, 0.3);
	}
	else if (time >= 55 && time <= 60) {
		Thefont.setColorRGB(1, 0.5, 0);
		Thefont.drawText("AYO CMU assignment!! Even after the world ended?"
			, 30, 200, 0.3);
		Thefont.setColorRGB(1, 0.5, 0);
		Thefont.drawText("And I'm in a different Dimension??"
			, 30, 250, 0.3);
	}
	else if (time >= 60 && time <= 70) {
		Thefont.setColorRGB(1, 0.2, 0);
		Thefont.drawText("AAAHHHH, This Never Ends!!!!"
			, 30, 400, 0.5);
	}
}





