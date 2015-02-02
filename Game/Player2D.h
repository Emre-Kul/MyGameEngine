#ifndef PLAYER2D_H
#define PLAYER2D_H

#include "../Math/Vectors.h"
#include "../General/Sprite.h"
#include "../Physics/CollisionStack2D.h"
#include "../GUI/KeyController.h"
#include "../General/GeneralFunc.h"

class Player2D{
		Vector2 velocity,velocityGoal,acceleration;
		Vector3 rotation;
		SHP2Rectangle position;
		Sprite playerSprite;
		CollisionWall playerWall;
		void move(float t);
	public:
		Player2D();

		void setPosition(SHP2Rectangle pos);//need to set mid pos
		void setPosition(float minx,float miny,float maxx,float maxy);
		void move(KeyController &keyController,CollisionStack2D &map);//it will work for multible players to
		void setWallFalse();
				//inlines
		void draw(){playerSprite.draw();}
		void setVelocity(float x,float y){velocity.change(x,y);}
		void setVelocityGoal(float x,float y){velocityGoal.change(x,y);}
		void setAcceleration(float x,float y){acceleration.change(x,y);}
		void setSprite(Sprite &sprite){playerSprite = sprite;}
		
		Vector3& getRotation(){return rotation;}
		Vector2& getVelocity(){return velocity;}
		Vector2& getVelocityGoal(){return velocityGoal;}
		Vector2& getAcceleration(){return acceleration;}
		Sprite& getSprite(){return playerSprite;}
		SHP2Rectangle& getPosition(){return position;}
};

#endif 