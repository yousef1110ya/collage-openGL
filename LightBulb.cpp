#include "LightBulb.h"
#include "globals.h"
#include <cmath>
#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <glu.h>	 // Header File For The GLu32 Library
#include <glaux.h>	 // Header File For The Glaux Library



LightBulb::LightBulb(float x , float y , float z ){
	this->X = x;
	this->Y = y;
	this->Z = z;
	this->isOn = false;
}


bool LightBulb::lightStillIn(GLfloat lightPosition[]){
	
	 float theX = lightPosition[0] - cameraX;
	float theX2 = theX * theX;
	float theY = lightPosition[1] - cameraY;
	float theY2 = theY * theY;
	float theZ = lightPosition[2] - cameraZ;
	float theZ2 = theZ * theZ;
	float distance = sqrt(theX2 + theY2 + theZ2);

	if(distance < renderDistance){
		return true;
	}

	return false;

}
bool LightBulb::check(){
	/*
	*	IN HERE I WILL CALCULATE THE DISTANCE OF THE LIGHT FROM THE CAMERA AND THEN IF IT'S LESS THAN THE RENDER DISTANCE THEN TURN OFF THE LIGHT
	*/
	float theX = this->X - cameraX;
	float theX2 = theX * theX;
	float theY = this->Y - cameraY;
	float theY2 = theY * theY;
	float theZ = this->Z - cameraZ;
	float theZ2 = theZ * theZ;
	float distance = sqrt(theX2 + theY2 + theZ2);

	if(distance < renderDistance){
		return true;
	}

	return false;

}

void LightBulb::changeLightPositionToBulb(){
	if(this->check()){
		if(	!occupiedLights[0] || !lightStillIn(Light0Pos)){
			Light0Pos[0] = this->X; 
			Light0Pos[1] = this->Y ;
			Light0Pos[2] = this->Z ;
			Light0Pos[3] = 1.0f;
			glLightfv(GL_LIGHT0,GL_POSITION,Light0Pos);
			glLightfv(GL_LIGHT0,GL_AMBIENT,LightAmb);
			glLightfv(GL_LIGHT0,GL_DIFFUSE,LightDiff);
			glLightfv(GL_LIGHT0,GL_SPECULAR,LightSpec);
			glEnable(GL_LIGHT0);
			occupiedLights[0] = true;
			this->resetLights();
			return ;
		}
		if(	!occupiedLights[1] || !lightStillIn(Light1Pos)){
			Light1Pos[0] = this->X; 
			Light1Pos[1] = this->Y ;
			Light1Pos[2] = this->Z ;
			Light1Pos[3] = 1.0f;
			glLightfv(GL_LIGHT1,GL_POSITION,Light1Pos);
			glLightfv(GL_LIGHT1,GL_AMBIENT,LightAmb);
			glLightfv(GL_LIGHT1,GL_DIFFUSE,LightDiff);
			glLightfv(GL_LIGHT1,GL_SPECULAR,LightSpec);
			glEnable(GL_LIGHT1);
			occupiedLights[1] = true;
			this->resetLights();
			return ;
		}
		if(	!occupiedLights[2] || !lightStillIn(Light2Pos)){
			Light2Pos[0] = this->X; 
			Light2Pos[1] = this->Y ;
			Light2Pos[2] = this->Z ;
			Light2Pos[3] = 1.0f;
			glLightfv(GL_LIGHT2,GL_POSITION,Light2Pos);
			glLightfv(GL_LIGHT2,GL_AMBIENT,LightAmb);
			glLightfv(GL_LIGHT2,GL_DIFFUSE,LightDiff);
			glLightfv(GL_LIGHT2,GL_SPECULAR,LightSpec);
			glEnable(GL_LIGHT2);
			occupiedLights[2] = true;
			this->resetLights();
			return ;
		}
		if(	!occupiedLights[3] || !lightStillIn(Light3Pos)){
			Light3Pos[0] = this->X; 
			Light3Pos[1] = this->Y ;
			Light3Pos[2] = this->Z ;
			Light3Pos[3] = 1.0f;
			glLightfv(GL_LIGHT3,GL_POSITION,Light3Pos);
			glLightfv(GL_LIGHT3,GL_AMBIENT,LightAmb);
			glLightfv(GL_LIGHT3,GL_DIFFUSE,LightDiff);
			glLightfv(GL_LIGHT3,GL_SPECULAR,LightSpec);
			glEnable(GL_LIGHT3);
			occupiedLights[3] = true;
			this->resetLights();
			return ;
		}
	
	
	
	
	
	
	
	
	}


}



void LightBulb::resetLights(){
	if (!lightStillIn(Light3Pos)){
		occupiedLights[3] = true;
	}
	if (!lightStillIn(Light2Pos)){
		occupiedLights[2] = true;
	}
	if (!lightStillIn(Light1Pos)){
		occupiedLights[1] = true;
	}
	if (!lightStillIn(Light0Pos)){
		occupiedLights[0] = true;
	}

}