#pragma once
#include "Model_3DS.h"

class Function
{
public:
	int wall, ground;
	Model_3DS light_saber;//lightsaber
	GLTexture lb;


	void room(int wall, int ground);
	void table();
	void monitor();
	void drawSphere(double r, int lats, int longs);
	void mouse_keyboard(int kb);
	void pc_case();
	//text
	void BuildFont(int font);
	void KillFont();
	void glPrint(int x, int y, int set, const char *fmt, ...);
	//
	void glass(int t1, int t2, int t3);
	void fake_text(int error, int enter);
	void cylinder(float ni, float nsc);
	void weapon(double l_x, double l_y, double l_z, double l_scale);
	void player(float legx, float legz, float leg2x, float leg2z);
	Function();
};