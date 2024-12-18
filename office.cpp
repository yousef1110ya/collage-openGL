
#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <glu.h>	 // Header File For The GLu32 Library
#include <glaux.h>	 // Header File For The Glaux Library


#include "office.h"
#include "globals.h"
#include "chair.h"



// create an office chair
void office::createChair(float cx , float cy , float cz , float width , float height  , float depth,  int seatTex , int standTex  )	{
	/*
		THE CX , CY , CZ PRESENT THE POSITION OF THE CHAIR
		THE WIDTH IS THE SIZE OF THE CHAIR ON THE X AXIS
		THE HEIGHT IS THE SIZE OF THE CHAIR ON THE Y AXIS
		THE DEPTH IS THE SIZE OF THE CHAIR ON THE Z AXIS
		THE SEAT TEXTUR REPRESENT THE TEXTURE ON THE SEAT PLACE << MOSTLY A LEATHER TEXTURE >>
		THE STANDTEX REPRESENT THE TEXTURE OF THE STAND POLES <<  MOSTLY A METAL TEXTURE >>
	*/
	glPushMatrix();
	glTranslatef(cx, cy, cz); // To move all the chair to the point we want
	glPushMatrix();	 // the back seat
	glTranslatef(0 , 0.3*height , 0);
	create2sidesWall(0.25*width , 0.6*height , 	 depth , seatTex ,seatTex , seatTex);
	glPopMatrix();
	// the seat
	glPushMatrix();	 
	glTranslatef(0 , 0.3*height - 0.1*height , 0);
	create2sidesWall(width , 0.1*height , depth , seatTex , seatTex ,seatTex);
	glPopMatrix();
	// the stand poll
	glPushMatrix();	 
	glTranslatef(width*0.5 - 0.1*width , 0 , depth*0.5 -0.15*depth);
	create2sidesWall(width*0.2 , 0.3*height , 0.5*depth , standTex , standTex ,standTex);
	glPopMatrix();
	// the front poll
	glPushMatrix();	 
	glTranslatef(0 , 0 , depth*0.5 -0.15*depth);
	create2sidesWall(width , 0.1*height , 0.5*depth , standTex , standTex ,standTex);
	glPopMatrix();
	// the side poll
	glPushMatrix();	 
	glTranslatef(width*0.5 - 0.1*width , 0 , 0);
	create2sidesWall(width*0.2 , 0.1*height , depth , standTex , standTex ,standTex);
	glPopMatrix();
    glPopMatrix();

}
void office::createDesk(float cx , float cy , float cz , float width , float height  , float depth, int texture1 , int topTexture)	{
	  /*
		THE CX , CY , CZ PRESENT THE POSITION OF THE CHAIR
		THE WIDTH IS THE SIZE OF THE CHAIR ON THE X AXIS
		THE HEIGHT IS THE SIZE OF THE CHAIR ON THE Y AXIS
		THE DEPTH IS THE SIZE OF THE CHAIR ON THE Z AXIS
		THE TEXTURE1 REPRESENT THE TEXTURE ON THE SIDE PANELS OF THE CHAIR << MOSTLY A WOOD TEXTURE >>
		THE TOP TEXTURE REPRESENT THE TEXTURE OF THE TOP OF THE TABLE  <<  CAN BE ANOTHER TYPE OF WOOD OR A GLASS MATERIAL OR ANY CUSTOM ONE >>
	*/
	glPushMatrix();
	glTranslatef(cx, cy, cz); // To move all the chair to the point we want
	// the left panel
	glPushMatrix();	
	create2sidesWall(width/8 , height - height/8 , depth,texture1,texture1,texture1);
	glPopMatrix();
	// the right panel
	glPushMatrix();
	glTranslatef(width , 0,0);
	create2sidesWall( -width/8 , height - height/8 , depth,texture1,texture1,texture1);
	glPopMatrix();
	// the front panel
	glPushMatrix();
	glTranslatef(0 , height/4,depth);
	create2sidesWall( width , height*0.4  , -depth/8,texture1,texture1,texture1);
	glPopMatrix();
	// the top panel 
		glPushMatrix();
	glTranslatef(0 , height,0);
	create2sidesWall( width , -height/8  , depth,topTexture,topTexture,topTexture);
	glPopMatrix();
    glPopMatrix();

}
void office::createLamp( int standTex , int lampTex) {

}						 
void office::createOffice(){
	
}