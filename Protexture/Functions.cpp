#include "FuncHeader.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <cmath>
#include <texture.h>
#include <fstream>

Function::Function()
{
	light_saber = Model_3DS();
	char w[] = "Lightsaber.3DS";
	light_saber.Load(w);
	lb.LoadBMP("lb.bmp");
	lb.Use();
	light_saber.Materials[0].tex = lb;

}

void Function::room(int wall, int ground)
{

	/////////////////////////////////////bgs
	glPushMatrix();
	{
		glScaled(4, 4, 2);
		////////////////////////////////////////////////////////ground
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ground);
		glBegin(GL_QUADS);
		{
			glColor3d(0.6, 0.6, 0.6);
			glTexCoord2f(1, 1);
			glVertex3d(-30, 0, 0);
			//
			glTexCoord2f(0, 1);
			glVertex3d(-30, 0, -30);
			//
			glTexCoord2f(0, 0);
			glVertex3d(30, 0, -30);
			//
			glTexCoord2f(1, 0);
			glVertex3d(30, 0, 0);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//////////////////////////////////////////////////////////wall
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, wall);
		glBegin(GL_QUADS);
		{
			glBindTexture(GL_TEXTURE_2D, wall);
			glColor3d(0.5, 0.5, 0.5);
			glTexCoord2f(1, 0);
			glVertex3d(30, 0, -30);

			glTexCoord2f(0, 1);
			glVertex3d(-30, 0, -30);

			glColor3f(1, 1, 1);

			glTexCoord2f(0, 0);
			glVertex3d(-30, 30, -30);

			glTexCoord2f(1, 1);
			glVertex3d(30, 30, -30);

		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	//line in between
	glLineWidth(25);
	glBegin(GL_LINES);
	{
		glColor3d(0.4, 0.2, 0.1);
		glVertex3d(-30, 0, -30);
		glVertex3d(30, 0, -30);

	}
	glEnd();
	glPopMatrix();

}
//////////////////////////////////////////////////////table
void Function::table()
{

	glPushMatrix();
	{
		//glScalef(1,1.5,1);
		glTranslatef(0, 0, -5);
		glBegin(GL_QUADS);
		{
			//glColor3f(0,0.1,0.2);
			glColor3f(0, 0, 0.2);
			glVertex3d(18, 15, -29);
			glVertex3d(18, 15, -5);
			glVertex3d(-18, 15, -5);
			glVertex3d(-18, 15, -29);
		}
		glEnd();
		///legs
		glLineWidth(15);
		glBegin(GL_LINES);
		{

			glVertex3d(15, 15, -29);
			glVertex3d(15, 0, -29);

			glVertex3d(15, 15, -5);
			glVertex3d(15, 0, -5);

			glVertex3d(-15, 15, -5);
			glVertex3d(-15, 0, -5);

			glVertex3d(-15, 15, -29);
			glVertex3d(-15, 0, -29);

			glVertex3d(17, 15, -5);
			glVertex3d(-17, 15, -5);

		}
		glEnd();

	}
	glPopMatrix();
}
/////////////////////////////////////monitor
void Function::monitor()
{
	glPushMatrix();
	{
		////////////////////////////////screen
		glBegin(GL_QUADS);
		{
			glColor3f(0, 0, 0);
			glVertex3d(13, 18, -26);
			glVertex3d(13, 26, -26);
			glVertex3d(-6, 26, -26);
			glVertex3d(-6, 18, -26);
		}
		glEnd();
		///////////////glass
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glBegin(GL_QUADS);
		{
			glColor4f(1, 1, 1, 0.1);
			glVertex3d(12.5, 18.5, -25.7);
			glVertex3d(12.5, 25.5, -25.7);
			glVertex3d(-5.5, 25.5, -25.7);
			glVertex3d(-5.5, 18.5, -25.7);
		}
		glEnd();
		glDisable(GL_BLEND);
		///////////////stand
		glColor3f(0, 0, 0);
		glLineWidth(15);

		glBegin(GL_LINES);
		{
			glVertex3d(3.5, 15.2, -26.2);
			glVertex3d(3.5, 18, -26.2);

			glVertex3d(1, 15.5, -26.2);
			glVertex3d(6, 15.5, -26.2);

		}
		glEnd();
		////////////////details
		glLineWidth(2);
		glBegin(GL_LINES);
		{
			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
			//glColor3f(1,0.2,0.2);
			glVertex3d(13, 18, -26);
			glVertex3d(13, 26, -26);
			glVertex3d(-6, 26, -26);
			glVertex3d(-6, 18, -26);
		}
		glEnd();
	}
	glPopMatrix();
}
//////////////////
void Function::drawSphere(double r, int lats, int longs) {
	//The parameters lat defines how many horizontal lines you want to have in
	//your sphere and lon how many vertical lines.
	//r is the radius of your sphere.
	float M_PI = 3.14;
	int i, j;
	for (i = 0; i <= lats; i++) {
		double lat0 = M_PI * (-0.5 + (double)(i - 1) / lats);
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = M_PI * (-0.5 + (double)i / lats);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);

		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= longs; j++) {
			double lng = 2 * M_PI * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(r * x * zr0, r * y * zr0, r * z0);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(r * x * zr1, r * y * zr1, r * z1);
		}
		glEnd();
	}
}
///////////////////////////////////////////mouse
void Function::mouse_keyboard(int kb)
{
	glPushMatrix();
	{
		glColor3f(1, 0, 0.2);
		glPointSize(2);
		glBegin(GL_POINTS); {glColor3ub(rand() % 255, rand() % 255, rand() % 255); glVertex3d(13.5, 16, -21.8); }glEnd();

		glColor3f(0, 0, 0);
		glTranslated(14, 15.3, -24);
		drawSphere(1, 15, 15);
	}
	glPopMatrix();

	glPushMatrix();
	{
		//////////////////keyboard
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, kb);
		glBegin(GL_QUADS);
		{
			glColor3f(1, 1, 1);
			glTexCoord2f(0, 0); glVertex3d(-4, 16.5, -10);//bottom right
			glTexCoord2f(0, 1); glVertex3d(-4, 16.5, -15); //top right
			glTexCoord2f(1, 1); glVertex3d(8, 16.5, -15);//top left
			glTexCoord2f(1, 0); glVertex3d(8, 16.5, -10);//bottom left
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//other faces
		glBegin(GL_QUADS);
		{
			glColor3f(0, 0, 0);
			//back
			glVertex3d(-4, 16.2, -15);
			glVertex3d(-4, 16.5, -15);
			glVertex3d(8, 16.5, -15);
			glVertex3d(8, 16.2, -15);
			//right
			glVertex3d(8, 16.2, -10);
			glVertex3d(8, 16.5, -10);
			glVertex3d(8, 16.5, -15);
			glVertex3d(8, 16.2, -15);
			//left
			glVertex3d(-4, 16.2, -10);
			glVertex3d(-4, 16.5, -10);
			glVertex3d(-4, 16.5, -15);
			glVertex3d(-4, 16.2, -15);
			//front
			glVertex3d(-4, 16.2, -10);
			glVertex3d(-4, 16.5, -10);
			glVertex3d(8, 16.5, -10);
			glVertex3d(8, 16.2, -10);
			//bottom
			glVertex3d(-4, 16.2, -10);
			glVertex3d(-4, 16.2, -15);
			glVertex3d(8, 16.2, -15);
			glVertex3d(8, 16.2, -10);
		}
		glEnd();
	}
	glPopMatrix();

}
///////////////////////////////////////////case
void Function::pc_case()
{
	glPushMatrix();
	{
		//glTranslated(-15,15.3,-20);

		glBegin(GL_QUADS);
		{
			glColor3f(0, 0, 0);
			//front
			glVertex3d(-16, 15.3, -9);
			glVertex3d(-16, 20, -9);
			glVertex3d(-6, 20, -9);
			glVertex3d(-6, 15.3, -9);
			//back
			glVertex3d(-16, 15.3, -26);
			glVertex3d(-16, 20, -26);
			glVertex3d(-6, 20, -26);
			glVertex3d(-6, 15.3, -26);
			//up
			glVertex3d(-16, 20, -9);
			glVertex3d(-16, 20, -26);
			glVertex3d(-6, 20, -9);
			glVertex3d(-6, 20, -26);
			//left
			glVertex3d(-16, 15.3, -9);
			glVertex3d(-16, 15.3, -26);
			glVertex3d(-16, 20, -26);
			glVertex3d(-16, 20, -9);
			//right
			glVertex3d(-6, 15.3, -9);
			glVertex3d(-6, 15.3, -26);
			glVertex3d(-6, 20, -26);
			glVertex3d(-6, 20, -9);
			//bottom
			glVertex3d(-6, 15.3, -9);
			glVertex3d(-16, 15.3, -9);
			glVertex3d(-16, 15.3, -26);
			glVertex3d(-6, 15.3, -26);
		}
		glEnd();
		///////////details
		glLineWidth(5);
		glBegin(GL_LINES);
		{
			//glColor3f(1,0.2,0.2);
			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
			glVertex3d(-7, 17, -8.8);
			glVertex3d(-7, 18, -8.8);

			glVertex3d(-9, 16, -8.8);
			glVertex3d(-9, 19, -8.8);

			glVertex3d(-10, 16, -8.8);
			glVertex3d(-10, 19, -8.8);

			glColor3f(0, 1, 0);
			glVertex3d(-14, 17.5, -8.8);
			glVertex3d(-14, 19, -8.8);

		}
		glEnd();

		glPointSize(7);
		glBegin(GL_POINTS);
		{
			glColor3f(0, 1, 0);
			glVertex3d(-14, 17, -8.8);
		}
		glEnd();
		//
		glLineWidth(2);
		glBegin(GL_LINES);
		{
			//glColor3f(1,0,0.2);
			glColor3ub(rand() % 255, rand() % 255, rand() % 255);

			glVertex3d(-6, 20, -8.9);
			glVertex3d(-6, 15.3, -8.9);

			glVertex3d(-16, 20, -8.9);
			glVertex3d(-16, 15.3, -8.9);

			glVertex3d(-6, 20, -8.9);
			glVertex3d(-16, 20, -8.9);

			glVertex3d(-6, 15.3, -8.9);
			glVertex3d(-16, 15.3, -8.9);

			glVertex3d(-6, 20, -25.9);
			glVertex3d(-16, 20, -25.9);

			glVertex3d(-16, 20, -8.9);
			glVertex3d(-16, 20, -25.9);

			glVertex3d(-6, 20, -8.9);
			glVertex3d(-6, 20, -25.9);

			glVertex3d(-6, 20, -25.9);
			glVertex3d(-6, 15.3, -25.9);
		}
		glEnd();


	}
	glPopMatrix();
}
////////////////////////////////////////////////////////////////text
int		loop1;
int		loop2;
GLuint	base;
bool	ap;
GLuint	texture[2];


void Function::BuildFont(int font)									// Build Our Font Display List
{
	base = glGenLists(256);									// Creating 256 Display Lists
	glBindTexture(GL_TEXTURE_2D, font);				// Select Our Font Texture
	for (loop1 = 0; loop1<256; loop1++)						// Loop Through All 256 Lists
	{
		float cx = float(loop1 % 16) / 16.0f;						// X Position Of Current Character
		float cy = float(loop1 / 16) / 16.0f;						// Y Position Of Current Character

		glNewList(base + loop1, GL_COMPILE);					// Start Building A List
		glBegin(GL_QUADS);								// Use A Quad For Each Character
		glTexCoord2f(cx, 1.0f - cy - 0.0625f);			// Texture Coord (Bottom Left)
		glVertex2d(0, 16);							// Vertex Coord (Bottom Left)
		glTexCoord2f(cx + 0.0625f, 1.0f - cy - 0.0625f);	// Texture Coord (Bottom Right)
		glVertex2i(16, 16);							// Vertex Coord (Bottom Right)
		glTexCoord2f(cx + 0.0625f, 1.0f - cy);			// Texture Coord (Top Right)
		glVertex2i(16, 0);							// Vertex Coord (Top Right)
		glTexCoord2f(cx, 1.0f - cy);					// Texture Coord (Top Left)
		glVertex2i(0, 0);							// Vertex Coord (Top Left)
		glEnd();										// Done Building Our Quad (Character)
		glTranslated(15, 0, 0);							// Move To The Right Of The Character
		glEndList();										// Done Building The Display List
	}														// Loop Until All 256 Are Built
}

void Function::KillFont()										// Delete The Font From Memory
{
	glDeleteLists(base, 256);								// Delete All 256 Display Lists
}

void Function::glPrint(int x, int y, int set, const char *fmt, ...)	// Where The Printing Happens
{
	char		text[256];									// Holds Our String
	va_list		ap;											// Pointer To List Of Arguments

	if (fmt == NULL)										// If There's No Text
		return;												// Do Nothing

	va_start(ap, fmt);										// Parses The String For Variables
	vsprintf(text, fmt, ap);							// And Converts Symbols To Actual Numbers
	va_end(ap);												// Results Are Stored In Text

	if (set>1)												// Did User Choose An Invalid Character Set?
	{
		set = 1;												// If So, Select Set 1 (Italic)
	}
	glEnable(GL_TEXTURE_2D);								// Enable Texture Mapping
	glLoadIdentity();										// Reset The Modelview Matrix
	glTranslated(x, y, 0);									// Position The Text (0,0 - Bottom Left)
	glListBase(base - 32 + (128 * set));							// Choose The Font Set (0 or 1)

	if (set == 0)												// If Set 0 Is Being Used Enlarge Font
	{
		glScalef(1.5f, 2.0f, 1.0f);							// Enlarge Font Width And Height
	}

	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);		// Write The Text To The Screen
	glDisable(GL_TEXTURE_2D);								// Disable Texture Mapping
}

void Function::glass(int t1, int t2, int t3)
{
	glPushMatrix();
	{
		///////////astro
		glTranslated(-3, 2, 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, t1);
		glBegin(GL_QUADS);
		{
			glColor3d(1, 1, 1);
			glTexCoord2f(0, 0); glVertex3d(-20, 20, -29);
			//
			glTexCoord2f(0, 1); glVertex3d(-20, 25, -29);
			//
			glTexCoord2f(1, 1); glVertex3d(-25, 25, -29);
			//
			glTexCoord2f(1, 0); glVertex3d(-25, 20, -29);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
		///////////cupcake
		glTranslated(-2, 0, 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, t2);
		glBegin(GL_QUADS);
		{
			glColor3d(1, 1, 1);
			glTexCoord2f(0, 0); glVertex3d(-25, 25, -29);
			//
			glTexCoord2f(0, 1); glVertex3d(-25, 30, -29);
			//
			glTexCoord2f(1, 1); glVertex3d(-30, 30, -29);
			//
			glTexCoord2f(1, 0); glVertex3d(-30, 25, -29);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
		///////////music
		glTranslated(-2, 3, 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, t3);
		glBegin(GL_QUADS);
		{
			glColor3d(1, 1, 1);
			glTexCoord2f(0, 0); glVertex3d(-20, 10, -29);
			//
			glTexCoord2f(0, 1); glVertex3d(-20, 15, -29);
			//
			glTexCoord2f(1, 1); glVertex3d(-25, 15, -29);
			//
			glTexCoord2f(1, 0); glVertex3d(-25, 10, -29);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);

		///////////////glass

		glTranslated(0, -2, 0);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		//shade?
		glBegin(GL_QUADS);
		{
			glColor4f(0.1, 0.1, 0.1, 0.2);
			glVertex3d(-30.5, 10.5, -29.5);
			glVertex3d(-30.5, 30.5, -29.5);
			glVertex3d(-10.5, 30.5, -29.5);
			glVertex3d(-10.5, 10.5, -29.5);
		}
		glEnd();
		//actual glass
		glBegin(GL_QUADS);
		{
			glColor4f(1, 1, 1, 0.3);
			glVertex3d(-30.5, 10.5, -28.5);
			glVertex3d(-30.5, 30.5, -28.5);
			glVertex3d(-10.5, 30.5, -28.5);
			glVertex3d(-10.5, 10.5, -28.5);
		}
		glEnd();

		//affect
		//line 1
		glLineWidth(25);
		glBegin(GL_LINES);
		{
			glColor4f(1, 1, 1, 0.5);
			glVertex3d(-24, 30.5, -28.3);
			glVertex3d(-16, 10.5, -28.3);
		}
		glEnd();
		//2		
		glLineWidth(15);
		glBegin(GL_LINES);
		{
			glColor4f(1, 1, 1, 0.5);
			glVertex3d(-21, 30.5, -28.3);
			glVertex3d(-13, 10.5, -28.3);
		}
		glEnd();

		glDisable(GL_BLEND);

	}
	glPopMatrix();
}

void Function::fake_text(int error, int enter)
{
	glPushMatrix();
	{
		//////////////////error
		glTranslated(0.1, 0.8, 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, error);
		glBegin(GL_QUADS);
		{
			glColor3f(1, 1, 1);
			glTexCoord2f(0, 0); glVertex3d(-2, 18, -25);
			glTexCoord2f(0, 1); glVertex3d(-2, 24, -25);
			glTexCoord2f(1, 1); glVertex3d(8, 24, -25);
			glTexCoord2f(1, 0); glVertex3d(8, 18, -25);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
	//////////////////enter
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, enter);
		glBegin(GL_QUADS);
		{
			glColor3f(1, 1, 1);
			glTexCoord2f(0, 0); glVertex3d(8, 20, 8);//bottom right
			glTexCoord2f(0, 1); glVertex3d(8, 24, 8); //top right
			glTexCoord2f(1, 1); glVertex3d(16, 24, 8);//top left
			glTexCoord2f(1, 0); glVertex3d(16, 20, 8);//bottom left
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

}

void Function::cylinder(float ni, float nsc)
{
#define DEF_D 5
#define PI 3.1415926535898
	float j = 0, i = 0, k = 0, lol = 1;
	int th = 0;
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
	glPushMatrix();
	{
		//top and bottom circles
		glTranslated(0, -2, -10);
		for (i = 0; i <= ni; i += 0.005)
		{
			glBegin(GL_TRIANGLE_FAN);
			{
				glVertex3f(0, i, 0);

				for (k = 0; k <= 360; k += DEF_D)
				{
					glVertex3f(nsc*Cos(k), i * 2, nsc*Sin(k)); //cos and sine to widen the cylinder
				}
			}
			glEnd();
		}
	}
	glPopMatrix();
}

//////////////

void Function::weapon(double l_x, double l_y, double l_z, double l_scale)
{
	glColor3f(0.7, 1, 0);
	lb.Use();
	glPushMatrix();
	light_saber.pos.x = l_x;
	light_saber.pos.y = l_y;
	light_saber.pos.z = l_z;
	light_saber.scale = l_scale;
	light_saber.Draw();
	glPopMatrix();
	glColor3d(0, 0, 0);

}

void Function::player(float legx, float legz, float weabonx, float weaponR)
{
	glColor3f(1, 1, 1);
	glPushMatrix();
	{
		//left leg
		glPushMatrix();
		{
			glTranslated(legx -2, -7, legz +0.5);
			drawSphere(1.3, 20, 30);
		}
		glPopMatrix();
		//right leg
		glPushMatrix();
		{
			glTranslated(legx +2, -7,legz-0.5);
			drawSphere(1.3, 20, 30);
		}
		glPopMatrix();
		//torso
		glTranslated( legx, 0,  legz);
		drawSphere(3.3, 50, 20);
		//head
		glPushMatrix();
		glTranslated(0, 6, 0);
		drawSphere(2.1, 30, 30);
		glPopMatrix();
		
		//right arm
		glPushMatrix();
		{
			glTranslated(weabonx, 0, 0);
			drawSphere(1.2, 20, 30);
			glRotated(180, 1, 0, 0);
			glRotated(weaponR, 0, 1, 0);
			glRotated( weaponR, 1, 0, 0);
			weapon(0, 0, 3, 1.2);

		}
		glPopMatrix();
		//left arm
		glPushMatrix();
		{
			glColor3f(1, 1, 1);
			glTranslated(-4.4, 0, 0);
			drawSphere(1.2, 20, 30);

		}
		glPopMatrix();
	}
	glPopMatrix();
}

