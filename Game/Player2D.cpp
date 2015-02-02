#include "Player2D.h"
Player2D::Player2D(){
	playerWall.WALLTOP = false;
	playerWall.WALLRIGHT = false;
	playerWall.WALLLEFT = false;
	playerWall.WALLBOTTOM = false;
}
void Player2D::setWallFalse(){
	playerWall.WALLTOP = false;
	playerWall.WALLRIGHT = false;
	playerWall.WALLLEFT = false;
	playerWall.WALLBOTTOM = false;
}
void Player2D::setPosition(SHP2Rectangle pos){
    position = pos;
}
void Player2D::setPosition(float minx,float miny,float maxx,float maxy){
	SHP2Rectangle pos(minx,miny,maxx,maxy);
	position = pos;
}
void Player2D::move(KeyController &keyController,CollisionStack2D &map){
	float maxac = 0.001f;
	float force = 0.045f;
	if(keyController.isKeyPressed(GAME_KEY_UP))if(playerWall.WALLBOTTOM)velocity.y = force;
	if(keyController.isKeyPressed(GAME_KEY_RIGHT)) {acceleration.x = maxac;velocityGoal.x = 0.02f;}	
	else if(keyController.isKeyPressed(GAME_KEY_LEFT)) {acceleration.x = -maxac;velocityGoal.x = -0.02f;}
	if(keyController.isKeyReleased(GAME_KEY_UP))keyController.FreeKey(GAME_KEY_UP);
	if(keyController.isKeyReleased(GAME_KEY_RIGHT)){
		velocity.x = 0.0f;
		acceleration.x = 0.0f;
		keyController.FreeKey(GAME_KEY_RIGHT);
	}
	else if(keyController.isKeyReleased(GAME_KEY_LEFT)){
	    velocity.x = 0.0f;
		acceleration.x = 0.0f;
		keyController.FreeKey(GAME_KEY_LEFT); 
	}

	if(acceleration.x > 0.0f)
		if(velocity.x < velocityGoal.x) velocity.x += acceleration.x;
		else velocity.x = velocityGoal.x;
	
	if(acceleration.x < 0.0f)
		if(velocity.x > velocityGoal.x) velocity.x += acceleration.x;
		else velocity.x = velocityGoal.x;
	
	velocity.y += acceleration.y;
	setWallFalse();
	
	CollisionWall pWall;
	float coltime;
	
	if(map.rectangleTrace(getPosition(),pWall,velocity.x,velocity.y,coltime)){
		playerWall = pWall;
		move(coltime);
		if(playerWall.WALLBOTTOM || playerWall.WALLTOP)velocity.y = 0.0f;
		if(playerWall.WALLLEFT || playerWall.WALLRIGHT)velocity.x = 0.0f;
	}
	else move(1.0f);

	if(velocity.x < 0.0f)rotation.changeY(180.0f);
	else if(velocity.x > 0.0f)rotation.changeY(0.0f);
	
	/*
	if(playerWall.WALLBOTTOM){
		if(velocity.x != 0.0f)playerSprite.setFrameOrder(run,4);
		else if(velocity.x == 0.0f)playerSprite.setFrameOrder(wait);
	}
	else playerSprite.setFrameOrder(up);
	if(velocity.y < 0.0f)	{
		acceleration.changeY(gravity);//boosttan sonra eski haline döner	
		boost.setActive(false);
	}
	if(player2D.midPosition.y * 100.0f + 85.0f > point) point = (int)(player2D.midPosition.y * 100.0f + 85.0f);
	else if(player2D.midPosition.y * 100.0f + 85.0f < point-120) running = false;
	*/

	playerSprite.nextFrame();
	playerSprite.generateMesh(setToMid(position));

}//it will work for multible players to
void Player2D::move(float t){
		float firstPosX,firstPosY;
		Vector3 midPosition;
		midPosition = getMidPoint(position);
		
		firstPosX = midPosition.x;
		firstPosY = midPosition.y;

		if((velocity.y <= 0.0f && !playerWall.WALLBOTTOM) || (velocity.y >= 0.0f && !playerWall.WALLTOP))
		    midPosition.y += velocity.y;
		else midPosition.y += velocity.y*t;
		
	    if((velocity.x <= 0.0f && !playerWall.WALLLEFT) || (velocity.x >= 0.0f && !playerWall.WALLRIGHT))
		    midPosition.x += velocity.x;
		else midPosition.x += velocity.x*t;
		firstPosX = midPosition.x - firstPosX;
		firstPosY = midPosition.y - firstPosY;

		setPosition(position.vecMin.x + firstPosX,position.vecMin.y + firstPosY,
			position.vecMax.x + firstPosX,position.vecMax.y + firstPosY);
}
