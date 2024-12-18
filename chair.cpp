#include "chair.h"
#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <glu.h>	 // Header File For The GLu32 Library
#include <glaux.h>	 // Header File For The Glaux Library
#include <cmath>
#include <texture.h>
void chair::createChair(float x1, float y1, float z1, float width, float hieght, int texture)
{
      /*
		INSIDE THIS SECTION WE WILL CREATE THE BASE OF THE CHAIR AND IN THE OTHER 2 SECTIONS WE WILL CREATE THE 
		LEG AND THE SEAT 
	  */
	// front face 
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+0.4*width,y1 + 0.0f, z1+0.0f);   // A
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+ 0.6*width,y1 + 0.0f,z1+ 0.0f);	 // B
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+ 0.6*width, y1 + hieght/7,z1+ 0.0f);	 // C
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+ 0.4*width,y1 + hieght/7,z1+ 0.0f );	 // D
    glEnd();
    glPopMatrix();
   // back Face
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+0.4*width,y1 + 0.0f, z1+width);	// E
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+ 0.6*width,y1 + 0.0f,z1+ width);	  // F
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+ 0.6*width, y1 + hieght/7,z1+ width);	  // G
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+ 0.4*width,y1 + hieght/7,z1+ width);		// H
    glEnd();
    glPopMatrix();	
	// top face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+ 0.4*width,y1 + hieght/7,z1+ 0.0f );	 // D
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+ 0.6*width, y1 + hieght/7,z1+ 0.0f);	 // C
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+ 0.6*width, y1 + hieght/7,z1+ width);	  // G
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+ 0.4*width,y1 + hieght/7,z1+ width);		// H
    glEnd();
    glPopMatrix();
	// left face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+ 0.6*width,y1 + 0.0f,z1+ 0.0f);	 // B
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+ 0.6*width, y1 + hieght/7,z1+ 0.0f);	 // C
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+ 0.6*width, y1 + hieght/7,z1+ width);	  // G
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+ 0.6*width,y1 + 0.0f,z1+ width);	  // F
    glEnd();
    glPopMatrix();
	// RIGHT face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+0.4*width,y1 + 0.0f, z1+0.0f);   // A
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+ 0.4*width,y1 + hieght/7,z1+ 0.0f );	 // D
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+ 0.4*width,y1 + hieght/7,z1+ width);		// H
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+0.4*width,y1 + 0.0f, z1+width);	// E
    glEnd();
    glPopMatrix();
	// THE SECOND PART OF THE BASE
	// front face 
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1,y1 , z1+0.4*width);   // A
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1,y1 ,z1+ 0.6*width);	 // B
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1, y1 + hieght/7,z1+ 0.6*width);	 // C
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1,y1 + hieght/7,z1+ 0.4*width );	 // D
    glEnd();
    glPopMatrix();
	// BACK face 
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+width,y1 , z1+0.4*width);   //  E
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+width,y1 ,z1+ 0.6*width);	 //   F
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+width, y1 + hieght/7,z1+ 0.6*width);	 // G
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+width,y1 + hieght/7,z1+ 0.4*width );	 // H
    glEnd();
    glPopMatrix();
	// top face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1,y1 + hieght/7,z1+ 0.4*width );	 // D
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1, y1 + hieght/7,z1+ 0.6*width);	 // C
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+width, y1 + hieght/7,z1+ 0.6*width);	 // G
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+width,y1 + hieght/7,z1+ 0.4*width );	 // H
    glEnd();
    glPopMatrix();
	// left face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1,y1 ,z1+ 0.6*width);	 // B
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1, y1 + hieght/7,z1+ 0.6*width);	 // C
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+width, y1 + hieght/7,z1+ 0.6*width);	 // G
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+width,y1 ,z1+ 0.6*width);	 //   F
    glEnd();
    glPopMatrix();
	// RIGHT face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1,y1 , z1+0.4*width);   // A
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1,y1 + hieght/7,z1+ 0.4*width );	 // D
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+width,y1 + hieght/7,z1+ 0.4*width );	 // H
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+width,y1 , z1+0.4*width);   //  E
    glEnd();
    glPopMatrix();
	/*
	*	THIS IS THE SECOND SECTION 
	*   IN THIS SECTION WE WILL CREATE THE LEG OF THE CHAIR WITH THE SAME TEXTURE
	*/
	// the bottom face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+0.4*width,y1 + hieght/7 , z1+0.4*width);   // AL
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+0.6*width,y1 + hieght/7 , z1+0.4*width);	 // BL
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+0.6*width,y1 + hieght/7 , z1+0.6*width);	 // CL
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+0.4*width,y1 + hieght/7 , z1+0.6*width);   //  DL
    glEnd();
    glPopMatrix();
	// the Top face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+0.4*width,y1 + 0.85*hieght , z1+0.4*width);   // EL
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+0.6*width,y1 + 0.85*hieght , z1+0.4*width);	 // FL
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+0.6*width,y1 + 0.85*hieght , z1+0.6*width);	 // GL
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+0.4*width,y1 + 0.85*hieght , z1+0.6*width);   //  HL
    glEnd();
    glPopMatrix();
	// the right face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+0.6*width,y1 + hieght/7 , z1+0.4*width);	 // BL
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+0.6*width,y1 + hieght/7 , z1+0.6*width);	 // CL
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+0.6*width,y1 + 0.85*hieght , z1+0.6*width);	 // GL
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+0.6*width,y1 + 0.85*hieght , z1+0.4*width);	 // FL
    glEnd();
    glPopMatrix();
	// the LEFT face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+0.4*width,y1 + hieght/7 , z1+0.4*width);   // AL
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+0.4*width,y1 + hieght/7 , z1+0.6*width);   //  DL
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+0.4*width,y1 + 0.85*hieght , z1+0.6*width);   //  HL
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+0.4*width,y1 + 0.85*hieght , z1+0.4*width);   // EL
    glEnd();
    glPopMatrix();
	// the BACK face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+0.4*width,y1 + hieght/7 , z1+0.4*width);   // AL
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+0.6*width,y1 + hieght/7 , z1+0.4*width);	 // BL
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+0.6*width,y1 + 0.85*hieght , z1+0.4*width);	 // FL
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+0.4*width,y1 + 0.85*hieght , z1+0.4*width);   // EL
    glEnd();
    glPopMatrix();
	// the FRONT face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+0.4*width,y1 + hieght/7 , z1+0.6*width);   //  DL
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+0.6*width,y1 + hieght/7 , z1+0.6*width);	 // CL
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+0.6*width,y1 + 0.85*hieght , z1+0.6*width);	 // GL
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+0.4*width,y1 + 0.85*hieght , z1+0.6*width);   //  HL
    glEnd();
    glPopMatrix();
	/*
	*	THE THIRD SECTION
	*	IN THIS SECTION WE WILL CREATE THE MAIN SEAT FOR ALL THE VISITORS TO SET AT ANY TIME AND THIS REST IS FOR THE COMMENT LENGRH
	*/
	// the Bottom face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1,y1 +0.85*hieght , z1);   //  AS
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+width,y1 + 0.85*hieght , z1);	 // BS
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+width,y1 + 0.85*hieght , z1+width);	 // CS
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1,y1 + 0.85*hieght , z1+width);   //  DS
    glEnd();
    glPopMatrix();
	// the TOP face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1,y1 +hieght , z1);   //  ES
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+width,y1 + hieght , z1);	 // FS
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+width,y1 + hieght , z1+width);	 // GS
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1,y1 + hieght , z1+width);   //  HS
    glEnd();
    glPopMatrix();
	// the BACK face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1,y1 +0.85*hieght , z1);   //  AS
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+width,y1 + 0.85*hieght , z1);	 // BS
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+width,y1 + hieght , z1);	 // FS
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1,y1 +hieght , z1);   //  ES
    glEnd();
    glPopMatrix();
	// the FRONT face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1,y1 + 0.85*hieght , z1+width);   //  DS
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+width,y1 + 0.85*hieght , z1+width);	 // CS
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+width,y1 + hieght , z1+width);	 // GS
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1,y1 + hieght , z1+width);   //  HS
    glEnd();
    glPopMatrix();
	// the RIGHT face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1+width,y1 + 0.85*hieght , z1);	 // BS
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1+width,y1 + 0.85*hieght , z1+width);	 // CS
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1+width,y1 + hieght , z1+width);	 // GS
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1+width,y1 + hieght , z1);	 // FS
    glEnd();
    glPopMatrix();
	// the LEFT face 
	glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1,y1 +0.85*hieght , z1);   //  AS
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1,y1 + 0.85*hieght , z1+width);   //  DS
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x1,y1 + hieght , z1+width);   //  HS
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1,y1 +hieght , z1);   //  ES
    glEnd();
    glPopMatrix();
}