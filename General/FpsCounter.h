#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H
#include <iostream>
using namespace std;
class FpsCounter{
	int currentTime,frame,oldTime,totalTime; //total time her 2000 ms de bir 0 lan�r

public:
	int fps;
	FpsCounter();
	
	void SetTime(int time);
	void UpFrame();//frame say�s�n� 1 artt�r�r
	void updateTime();
	int frameTime();
	
};

#endif