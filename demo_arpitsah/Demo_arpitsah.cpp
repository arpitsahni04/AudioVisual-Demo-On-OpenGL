/*  Arpit Sahni
	24-780-B, Carnegie Mellon
	Oct. 11, 2022

	Demo
*/
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <fstream>
#include "fssimplewindow.h"
#include "yssimplesound.h"
#include "yspng.h"
#include "background.h"
#include "SpaceShip.h"


using namespace std;


int main(void)
{
	//Init
	FsOpenWindow(0, 0, 800, 600, 1, "SpaceShipping");
	background background1;
	SpaceShip SpaceShip1;
	double time = 0.0;
	int key = FSKEY_NULL;
	int mouseEvent, leftButton, middleButton, rightButton, locX, locY;

	// Create Sound Playing Objects
	YsSoundPlayer player1;
	YsSoundPlayer::SoundData myWav1; // Background
	YsSoundPlayer::SoundData myWav2; // Explosion sound
	YsSoundPlayer::SoundData myWav3; // Suspense Sound
	YsSoundPlayer::SoundData myWav4; // Screaming Sound
	if (YSOK != myWav1.LoadWav("bg.wav"))
	{
		printf("Failed to read the BG file ");
		return 1;
	}
	if (YSOK != myWav2.LoadWav("explosion1.wav"))
	{
		printf("Failed to read the BG file ");
		return 1;
	}
	if (YSOK != myWav3.LoadWav("Goat Scream.wav"))
	{
		printf("Failed to read the BG file ");
		return 1;
	}
	if (YSOK != myWav4.LoadWav("Suspense.wav"))
	{
		printf("Failed to read the BG file ");
		return 1;
	}
	player1.Start();

	player1.PlayBackground(myWav1);

	FsPollDevice();
	// main loop
	time = player1.GetCurrentPosition(myWav1);
	while (FSKEY_ESC != key && time <62)
	{
		time = player1.GetCurrentPosition(myWav1);
		FsPollDevice();
		// Mouse Position getter for drawing
		if (FSMOUSEEVENT_MOVE == FsGetMouseEvent(leftButton, middleButton, rightButton, locX, locY))
		{
			if (locX <= 1025 && locY <= 600)
				cout << "locX: " << locX << " locY: " << locY << endl;

		}

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		// take care of window resizing
		int wid, hei;
		FsGetWindowSize(wid, hei);
		glViewport(0, 0, wid, hei);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, (float)wid - 1.f, (float)hei - 1.f, 0, -1, 1); 
		// after converting to float don't subtract int

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glColor4d(1.0, 1.0, 1.0, 1.0);
		// this color will "tint" the image

		glEnable(GL_TEXTURE_2D);
		// enable texture mapping
		// draw all the stuff
		// clear screen in each iteration

		// Paint objexts
		background1.paint(time);
		SpaceShip1.paint(time);
		background1.draw_dialogue(time);
		// Sounds
		if (time > 60 && !player1.IsPlaying(myWav2)) {
			player1.PlayOneShot(myWav2);
		}
		if (time > 57 && !player1.IsPlaying(myWav3)) {
			player1.PlayOneShot(myWav3);
		}
		if (time > 42 && !player1.IsPlaying(myWav4)) {
			player1.PlayOneShot(myWav4);
		}

		utils::drawTimer(time);
		FsSwapBuffers(); // transfer all stuff to frame buffer
		FsSleep(15);
	}
	player1.End();
	return 0;
}