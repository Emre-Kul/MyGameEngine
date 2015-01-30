#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <time.h>

#include "../General/Screen.h"
#include "../Renderer/ShaderProgram.h"
#include "../General/TextureManager.h"
#include "../General/SpriteManager.h"
#include "../General/GeneralFunc.h"

#include "BackGround.h"
#include "Player2D.h"
#include "../General/Camera.h"

class Game{
		Screen screen;
		TextureManager textureManager;
		SpriteManager spriteManager;
		ShaderProgram textureShaderProgram;
		Camera camera;

		void prepareShaders();
	public:
		bool running,paused;
		KeyController keyController;
		Game(){}
		void setScreen(Screen &scr){screen = scr;}

		void gameInit();
		void refresh();

		void render();
		void update();
		
		void run(){running = true;}
		void stop(){running = false;}
		void pause(){paused = true;}
		void repause(){paused = false;}

		

};



#endif