#ifndef GLOBALS_H
#define GLOBALS_H
#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <glu.h>	 // Header File For The GLu32 Library
#include <glaux.h>	 // Header File For The Glaux Library
#include <cmath>


extern float i;
extern float j;
extern float k;
extern bool keys[256];

extern int mouseX;
extern int mouseY;
extern bool isClicked;
extern bool isRClicked;
extern int screenWidth;
extern int screenHight;


extern GLfloat LightAmb[];
extern GLfloat LightDiff[];
extern GLfloat LightSpec[];

extern GLfloat Light0Pos[];
extern GLfloat Light1Pos[];
extern GLfloat Light2Pos[];
extern GLfloat Light3Pos[];
extern GLfloat Light4Pos[];
extern GLfloat Light5Pos[];
extern GLfloat Light6Pos[];





/*
glLightfv(GL_LIGHT1,GL_POSITION,LightPos);
glLightfv(GL_LIGHT1,GL_AMBIENT,LightAmb);
glLightfv(GL_LIGHT1,GL_DIFFUSE,LightDiff);
glLightfv(GL_LIGHT1,GL_SPECULAR,LightSpec);
glEnable(GL_LIGHT1);
 */
extern bool occupiedLights[6];


extern float cameraX;
extern float cameraY;
extern float cameraZ;
extern float renderDistance;

extern void setRednerDistance(float distance);

extern void create2sidesWall(float width , float height , float depth , int texture1 , int texture2 , int stripeTexture);

extern void createWall(float width , float height , float depth );




#endif // GLOBALS_H
