#include "FpsCounter.h"
FpsCounter::FpsCounter(){
		currentTime = frame = oldTime = totalTime = 0;
}
	
void FpsCounter::SetTime(int time){
	totalTime += time - currentTime;
	currentTime = time;
	if(totalTime >= 1000){
		frame = 0;
		totalTime = 0;
	}
	else if(totalTime > 0) fps = (frame*1000)/totalTime; 
}
void FpsCounter::UpFrame(){
	frame++;
}//frame sayýsýný 1 arttýrýr

int FpsCounter::frameTime(){
	return currentTime - oldTime;
}
void FpsCounter::updateTime(){
	oldTime = currentTime;
}