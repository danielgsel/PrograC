
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"

using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[]){
	
	try {
		Game game;
		game.run();
	    game.~Game();//Para que nada más terminar de correr se destruyan y borren todos los objetos

	}
	catch(string error){
		cout << error;
	}
	return 1;
}