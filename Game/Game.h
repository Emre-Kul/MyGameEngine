#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <time.h>

#include "../General/Screen.h"
#include "../General/Camera.h"
#include "../General/TextureManager.h"
#include "../General/SpriteManager.h"
#include "../General/GeneralFunc.h"

#include "../GUI/MouseController.h"

#include "../Renderer/ShaderProgram.h"

#include "BackGround.h"
#include "Player2D.h"


class Game{
		
	public:
		bool running,paused;
		Screen screen;
		TextureManager textureManager;
		SpriteManager spriteManager;
		ShaderProgram textureShaderProgram,colorShaderProgram;
		Camera camera;
		
		KeyController keyController;
		MouseController mouseController;

		void prepareShaders();

		Game(){}
		
					//virtuals
		virtual void initOpengl();
		virtual void render(){}
		virtual void update(){}
					 //inlines
		inline void setScreen(Screen &scr){screen = scr;}
		inline void setCamera(Camera &cmr){camera = cmr;}
		inline void run(){running = true;}
		inline void stop(){running = false;}
		inline void pause(){paused = true;}
		inline void repause(){paused = false;}

};



#endif