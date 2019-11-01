//Alumno1: David Czepiel
//Alumno2 : Daniel Gonz�lez Sell�n
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"


using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[]){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	try {
		Game game;
		game.run();	
	}
	catch(string error){
		cout << error;
	}
	return 0;
}