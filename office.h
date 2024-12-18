#ifndef OFFICE_H
#define OFFICE_H

class office{
public:
	void createChair(float cx , float cy , float cz , float width , float height , float depth  ,int seatTex , int standTex );
	void createDesk(float cx , float cy , float cz , float width , float height  , float depth , int texture1 , int topTexture);
	void createLamp( int standTex , int lampTex);
	void createOffice();

};

#endif // OFFICE_H