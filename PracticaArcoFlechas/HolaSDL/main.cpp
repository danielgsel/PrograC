
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"


using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[]){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//Game* game=nullptr;
	
	try {
		Game game;
		//game = new Game();
		game.run();
		
	}
	catch(string error){

		cout << error;
	}
	//delete game;
	return 0;
}