#include <SDL.h> // Esto puede cambiar dependiendo de la instalaci�n
using namespace std;
#include <iostream>
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
int main(int argc, char* argv[]) { // Tiene que ser as� exactamente!
// Variables
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	int winX, winY; // Posici�n de la ventana
	winX = winY = SDL_WINDOWPOS_CENTERED;
	// Inicializaci�n del sistema, ventana y renderer
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", winX, winY, WIN_WIDTH,
		WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		std::cout << "Error initializing SDL\n�; // En general lanzaremos una excepci�n";
	else { // Programa que usa SDL
		
	}
	// Finalizaci�n
}