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
bool occupiedLights[6]={false,false,false,false,false,false};

float renderDistance = 10.0f;

 GLfloat LightAmb[] = {1.0f,1.0f,1.0f,1.0f};
 GLfloat LightDiff[] = {0.6f,0.6f,0.6f,1.0f};
 GLfloat LightSpec[] = {0.2f,0.2f,0.2f,1.0f};


GLfloat Light0Pos[] = {1.0f,1.0f,1.0f,1.0f};
GLfloat Light1Pos[] = {1.0f,1.0f,1.0f,1.0f};
GLfloat Light2Pos[] = {1.0f,1.0f,1.0f,1.0f};
GLfloat Light3Pos[] = {1.0f,1.0f,1.0f,1.0f};
GLfloat Light4Pos[] = {1.0f,1.0f,1.0f,1.0f};
GLfloat Light5Pos[] = {1.0f,1.0f,1.0f,1.0f};
GLfloat Light6Pos[] = {1.0f,1.0f,1.0f,1.0f};




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
	glVertex3f(0,0,1);   // E
	glTexCoord2f(width, 0);
    glVertex3f(1,0,1);	 // F
	glTexCoord2f(width, height);
	glVertex3f(1,1,1);	 // G
	glTexCoord2f(0.0f, height);
    glVertex3f(0,1,1);	 // H
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
    glVertex3f(1,0,1);	 // F
	glTexCoord2f(depth, height);
	glVertex3f(1,1,1);	 // G
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
    glVertex3f(1,1,1);	 // G
	glTexCoord2f(depth, height);
	glVertex3f(0,1,1);	 // H
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
	glVertex3f(0,0,1);   // E
	glTexCoord2f(depth, 0.0f);
    glVertex3f(0,0,0);   // A
	glTexCoord2f(depth, height);
	glVertex3f(0,1,0);	 // D
	glTexCoord2f(0.0f, height);
    glVertex3f(0,1,1);	 // H
    glEnd();
    glPopMatrix();
	// Stripe Faces 4
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, stripeTexture);
    glBegin(GL_QUADS);
	glNormal3f(0,-1,0);
    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0,0,1);   // E
	glTexCoord2f(depth, 0.0f);
    glVertex3f(0,0,0);   // A
	glTexCoord2f(depth, height);
	glVertex3f(1,0,0);	 // B
	glTexCoord2f(0.0f, height);
    glVertex3f(1,0,1);	 // F
    glEnd();
    glPopMatrix();
	glPopMatrix();
}

void setRednerDistance(float distance){
	renderDistance = distance;
}


void createWall(float width , float height , float depth )	{

   glPushMatrix();
		glScalef(width , height ,depth);
	glPushMatrix();
    glBegin(GL_QUADS);
	glColor3d(1,1,1);
	glNormal3f(-1,0,0);

    glVertex3f(0,0,0);   // A

    glVertex3f(1,0,0);	 // B

	glVertex3f(1,1,0);	 // C

    glVertex3f(0,1,0);	 // D
    glEnd();
    glPopMatrix();
		// OTHER FACE 
	glPushMatrix();
		glColor3d(1,1,1);
    glBegin(GL_QUADS);
	glNormal3f(1,0,0);

	glVertex3f(0,0,1);   // E

    glVertex3f(1,0,1);	 // F
	glTexCoord2f(width, height);

	glTexCoord2f(0.0f, height);

    glEnd();
    glPopMatrix();
	// Stripe Faces 
	glPushMatrix();
   	glColor3d(1,1,1);
    glBegin(GL_QUADS);
	glNormal3f(0,0,1);

	glVertex3f(1,0,0);	 // B

    glVertex3f(1,0,1);	 // F

	glVertex3f(1,1,1);	 // G

    glVertex3f(1,1,0);	 // C
    glEnd();
    glPopMatrix();
	// Stripe Faces  2
	glPushMatrix();
		glColor3d(1,1,1);
    glBegin(GL_QUADS);
	glNormal3f(0,1,0);

	glVertex3f(1,1,0);	 // C

    glVertex3f(1,1,1);	 // G

	glVertex3f(0,1,1);	 // H

    glVertex3f(0,1,0);	 // D
    glEnd();
    glPopMatrix();
	// Stripe Faces 3
	glPushMatrix();
		glColor3d(1,1,1);
    glBegin(GL_QUADS);
	glNormal3f(0,0,-1);

	glVertex3f(0,0,1);   // E

    glVertex3f(0,0,0);   // A

	glVertex3f(0,1,0);	 // D

    glVertex3f(0,1,1);	 // H
    glEnd();
    glPopMatrix();
	// Stripe Faces 4
	glPushMatrix();
		glColor3d(1,1,1);
    glBegin(GL_QUADS);
	glNormal3f(0,-1,0);

	glVertex3f(0,0,1);   // E

    glVertex3f(0,0,0);   // A

	glVertex3f(1,0,0);	 // B

    glVertex3f(1,0,1);	 // F
    glEnd();
    glPopMatrix();
	glPopMatrix();

}