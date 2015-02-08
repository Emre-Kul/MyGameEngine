#ifndef PLAYER2D_H
#define PLAYER2D_H

#include "../Math/Vectors.h"
#include "../General/Sprite.h"
#include "../Physics/CollisionStack2D.h"
#include "../GUI/KeyController.h"
#include "../General/GeneralFunc.h"

class Player2D{

		Vector2 velocity,velocityGoal,acceleration,collNormal;
		
		Vector3 rotation;
		SHP2Rectangle position;

		Sprite playerSprite;
		
		void move(float t);
	public:
		
		Player2D(){}
		void setPosition(SHP2Rectangle pos);//need to set mid pos
		void setPosition(float minx,float miny,float maxx,float maxy);
		void move(KeyController &keyController,CollisionStack2D &map);//it will work for multible players to
		
				//inlines
		inline void setColNormal(Vector2 &vec){collNormal = vec;}
		inline void draw(){playerSprite.draw();}
		inline void setVelocity(float x,float y){velocity.change(x,y);}
		inline void setVelocityGoal(float x,float y){velocityGoal.change(x,y);}
		inline void setAcceleration(float x,float y){acceleration.change(x,y);}
		inline void setSprite(Sprite &sprite){playerSprite = sprite;}
		
		inline Vector3& getRotation(){return rotation;}
		inline Vector2& getVelocity(){return velocity;}
		inline Vector2& getVelocityGoal(){return velocityGoal;}
		inline Vector2& getAcceleration(){return acceleration;}
		inline Sprite& getSprite(){return playerSprite;}
		inline SHP2Rectangle& getPosition(){return position;}
};

#endif 