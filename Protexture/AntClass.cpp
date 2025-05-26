#include <iostream>
#include <string>
#include <math.h>
#include <texture.h>
#include <fstream>
#include "heightMap.h"
#include "tgaLoader.h"
#include <gl.h>	
#include "AntHeader.h"

Ant::Ant()
{

	health = 1;
	hit = false;
	ant = Model_3DS();
	char a[] = "ANT_BLK.3DS";
	ant.Load(a);
	tex.LoadBMP("black_ant.bmp");

	ant.Materials[0].tex = tex;
	//ant.Materials[1].tex=tex;
	glDisable(GL_TEXTURE_2D);

}
////////////////////////////actual function
void Ant::generate(double ant_x, double ant_y, double ant_z, double ant_scale)
{
	glColor3f(0.9f,0.0f, 0);
	glPushMatrix();
	//glScaled(1,5,1);
	ant.pos.x = ant_x;
	ant.pos.y = ant_y;
	ant.pos.z = ant_z;
	ant.scale = ant_scale;
	ant.Draw();
	glPopMatrix();
}
////////////////////////////death function
void Ant::die(int health)
{
	//model should disappear and a spot under it should replace it
	if (health == 0)
	{
		ant.visible = false;
	}
}
///////////////////////////movement
void move()
{

}
