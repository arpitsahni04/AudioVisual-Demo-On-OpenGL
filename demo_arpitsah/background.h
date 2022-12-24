#pragma once

#include "utils.h"
#include "yssimplesound.h"
#include "GraphicFont.h"
class background {

protected:
    GLuint BG1;
    GLuint BG2;
    GLuint Wormhole;
    GLuint Asteroid;
    GLuint assignment;
    GLuint Logo;
    GLuint frames[15];
    GLuint Explosion[51];
    GLuint BG3;
    int curFrame = 0;
    int curFrame_explosion = 0;
    double time_last_frame = 15;
    double time_last_explosion= 60;
    double time_last_assignment = 50;
    int asteroid_y = 5;
    int assignment_y = 100;
    double time_last_asteriod = 18;
    int BG_wid, BG_hei, BG2_wid, BG2_hei, Wormhole_wid, Wormhole_hei;
    double Worm_hole_angle = 0.0;
    //OldEnglishFont Thefont;
    ComicSansFont Thefont;


public:
	background();

	void paint(double time);

    void draw_dialogue(double time);


};
