#ifndef GLOBALS_H
#define GLOBALS_H

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


extern float cameraX;
extern float cameraY;
extern float cameraZ;

extern void create2sidesWall(float width , float height , float depth , int texture1 , int texture2 , int stripeTexture);



#endif // GLOBALS_H
