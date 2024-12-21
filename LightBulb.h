#ifndef LIGHTBULB_H
#define LIGHTBULB_H

#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <glu.h>	 // Header File For The GLu32 Library
#include <glaux.h>	 // Header File For The Glaux Library
#include <cmath>

class LightBulb{
public:
	float X,Y,Z;
	bool isOn;
	bool check();
	int occupiedLight;
	LightBulb(float x , float y, float z);
	void changeLightPositionToBulb();
	bool lightStillIn(GLfloat lightPosition[]);
	void resetLights();


};



#endif // LIGHTBULB_H