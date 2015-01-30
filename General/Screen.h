#ifndef SCREEN_H
#define SCREEN_H


class  Screen
{
	int SCR_WIDTH,SCR_HEIGHT;
	float ratio;
public:
	 Screen();
	 Screen(int witdh,int height);	
	 
	 float getRatio(){return ratio;}
	 int getWidth(){return SCR_WIDTH;}
	 int getHeight(){return SCR_HEIGHT;}

private:

};


#endif
