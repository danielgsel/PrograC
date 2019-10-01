
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>

using namespace std;

using uint = unsigned int;
int A(SDL_Renderer* render, SDL_Texture* texture);
int B(SDL_Renderer* render);
int C(SDL_Renderer* render, float x, SDL_Texture* texture);
//int D(SDL_Renderer* render);

void firstTest() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const uint winWidth = 800;
	const uint winHeight = 600;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("My first test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;
	else {
		uint32_t startTime, frameTime, oldFrameTime;
		startTime = SDL_GetTicks();
		float xPerro = 0;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		frameTime = SDL_GetTicks() - startTime;

		SDL_Texture* fondo; // Variable para la textura
		string filename = "..\\images\\background1.png"; // Nombre del fichero con la imagen .bmp
		SDL_Surface* surface = IMG_Load(filename.c_str()); // Solo para bmps
		fondo = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		SDL_Texture* dog; // Variable para la textura
		filename = "..\\images\\dog.png"; // Nombre del fichero con la imagen .bmp
		surface = IMG_Load(filename.c_str()); // Solo para bmps
		dog = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		while (frameTime < 5000) {
			SDL_RenderClear(renderer);
			A(renderer,fondo);
			C(renderer, xPerro, dog);
			SDL_RenderPresent(renderer);

			oldFrameTime = frameTime;

			frameTime = SDL_GetTicks() - startTime;
			xPerro = (10 * ((float)frameTime - (float)oldFrameTime) / 50);
			
			

			

		}
		//SDL_Delay(5000);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int A(SDL_Renderer* render, SDL_Texture* texture) {

	
	SDL_RenderCopy(render, texture, NULL, NULL);





	
	return 1;
}

int B(SDL_Renderer* render) {

	SDL_Rect destRect;
	destRect.w = destRect.h = 200; // Frame de 50x50
	destRect.x = 0; destRect.y = 400; // Se pinta en la esquina superior izqda
	SDL_Rect sourceRect;
	sourceRect.w = 128; sourceRect.h = 82; // Frame de 50x50
	sourceRect.x = sourceRect.y = 0; // Se pinta en la esquina superior izqda
	
	SDL_Texture* texture; // Variable para la textura
	string filename = "..\\images\\dog.png"; // Nombre del fichero con la imagen .bmp
	SDL_Surface* surface = IMG_Load(filename.c_str()); // Solo para bmps
	texture = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
	SDL_RenderCopy(render, texture, &sourceRect, &destRect);

	return 2;
}

int C(SDL_Renderer* render, float posX, SDL_Texture* texture) {
	
	SDL_Rect destRect;
	destRect.w = destRect.h = 200; // Frame de 50x50
	destRect.x = posX; destRect.y = 400; // Se pinta en la esquina superior izqda
	SDL_Rect sourceRect;
	sourceRect.w = 128; sourceRect.h = 82; // Frame de 50x50
	sourceRect.x = sourceRect.y = 0; // Se pinta en la esquina superior izqda

	
	SDL_RenderCopy(render, texture, &sourceRect, &destRect);

	
	return 1;
}



int main(int argc, char* argv[]){
	firstTest();
	return 0;
}