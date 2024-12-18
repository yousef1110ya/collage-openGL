#include "globals.h"
#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <glu.h>	 // Header File For The GLu32 Library
#include <glaux.h>	 // Header File For The Glaux Library
#include <cmath>

// keyboard variables
float i;      
float j;
float k;
bool keys[256];

// mouse variables
int mouseX;
int mouseY;
bool isClicked;
bool isRClicked;
int screenWidth;
int screenHight;

float cameraX = 0.0f; 
float cameraY = 0.0f; 
float cameraZ = 0.0f;

void create2sidesWall(float width , float height , float depth , int texture1 , int texture2 , int stripeTexture){
	glPushMatrix();
		glScalef(width , height ,depth);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture1);
    glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0,0,0);   // A
	glTexCoord2f(width, 0.0f);
    glVertex3f(1,0,0);	 // B
	glTexCoord2f(width, height);
	glVertex3f(1,1,0);	 // C
	glTexCoord2f(0.0f, height);
    glVertex3f(0,1,0);	 // D
    glEnd();
    glPopMatrix();
		// OTHER FACE 
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture2);
    glBegin(GL_QUADS);
	glNormal3f(1,0,0);
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0,0,depth);   // E
	glTexCoord2f(width, 0.0f);
    glVertex3f(1,0,depth);	 // F
	glTexCoord2f(width, height);
	glVertex3f(1,1,depth);	 // G
	glTexCoord2f(0.0f, height);
    glVertex3f(0,1,depth);	 // H
    glEnd();
    glPopMatrix();
	// Stripe Faces 
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, stripeTexture);
    glBegin(GL_QUADS);
	glNormal3f(0,0,1);
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1,0,0);	 // B
	glTexCoord2f(depth, 0.0f);
    glVertex3f(1,0,depth);	 // F
	glTexCoord2f(depth, height);
	glVertex3f(1,1,depth);	 // G
	glTexCoord2f(0.0f, height);
    glVertex3f(1,1,0);	 // C
    glEnd();
    glPopMatrix();
	// Stripe Faces  2
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, stripeTexture);
    glBegin(GL_QUADS);
	glNormal3f(0,1,0);
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1,1,0);	 // C
	glTexCoord2f(depth, 0.0f);
    glVertex3f(1,1,depth);	 // G
	glTexCoord2f(depth, height);
	glVertex3f(0,1,depth);	 // H
	glTexCoord2f(0.0f, height);
    glVertex3f(0,1,0);	 // D
    glEnd();
    glPopMatrix();
	// Stripe Faces 3
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, stripeTexture);
    glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0,0,depth);   // E
	glTexCoord2f(depth, 0.0f);
    glVertex3f(0,0,0);   // A
	glTexCoord2f(depth, height);
	glVertex3f(0,1,0);	 // D
	glTexCoord2f(0.0f, height);
    glVertex3f(0,1,depth);	 // H
    glEnd();
    glPopMatrix();
	// Stripe Faces 4
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, stripeTexture);
    glBegin(GL_QUADS);
	glNormal3f(0,-1,0);
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0,0,depth);   // E
	glTexCoord2f(depth, 0.0f);
    glVertex3f(0,0,0);   // A
	glTexCoord2f(depth, height);
	glVertex3f(1,0,0);	 // B
	glTexCoord2f(0.0f, height);
    glVertex3f(1,0,depth);	 // F
    glEnd();
    glPopMatrix();
	glPopMatrix();
}