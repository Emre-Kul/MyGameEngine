#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H
#include <iostream>
using namespace std;
class FpsCounter{
	int currentTime,frame,oldTime,totalTime; //total time her 2000 ms de bir 0 lanýr

public:
	int fps;
	FpsCounter();
	
	void SetTime(int time);
	void UpFrame();//frame sayýsýný 1 arttýrýr
	void updateTime();
	int frameTime();
	
};

#endif