#include "testing.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>

void testing::createTestRec(){
	
	// GL_TRIANGLE_STRIP
	glBegin(GL_TRIANGLE_STRIP);
	//glColor3d(1, 0, 1);
	glVertex3d(-1, -1, 0); //T0
	//glColor3d(0, 0, 1);
	glVertex3d(-1, 0, 0); //T1
	//glColor3d(0, 1, 0);
	glVertex3d(0, 0, 0); //T2
	//glColor3d(1, 0, 0);
	glVertex3d(0, -1, 0); //T3
	glEnd();
	//.....
}