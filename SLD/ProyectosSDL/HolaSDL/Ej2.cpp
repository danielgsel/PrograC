#include "SDL.h"			
	#include "SDL_image.h"
	#include "checkML.h"
	#include <iostream>

using namespace std;

using uint = unsigned int;

int A(SDL_Renderer* render);
int B(SDL_Renderer* render);
int C(SDL_Renderer* render, int x, int* posPerro,int velDog);
int F(SDL_Renderer* render, int x, int* posHeli,int velHeli);
void firstTest() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const uint winWidth = 800;
	const uint winHeight = 600;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	int tiempoActual, tiempoEmpezar, ultimoTiempo;
	int posicionPerro = 0;
	int posicionHeli = 800;
	int velHeli = 10;
	int velDog = 10;
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;
	else {
		tiempoEmpezar = SDL_GetTicks();
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		A(renderer);
		B(renderer);
		tiempoActual = SDL_GetTicks() - tiempoEmpezar;
			SDL_Event event;
		while (tiempoActual < 5000) {
			SDL_RenderClear(renderer);
									//Teclado
			while (SDL_PollEvent(&event) ) {
				if (event.type == SDL_QUIT)
				{ }
			 if (event.type == SDL_KEYDOWN) {
					switch (event.key.keysym.sym) {
					case SDLK_h:
						if (velHeli > 0)
							velHeli = 0;
						else
							velHeli = 10;
						break;
					case SDLK_d:
						if (velDog > 0)
							velDog = 0;
						else
							velDog = 10;
						break;
					case SDLK_j:
						velHeli += 10;
						break;
					case SDLK_g:
						velHeli -= 10;
						break;
					case SDLK_f:
						velDog += 10;
						break;
					case SDLK_s:
						velDog -= 10;
						break;

					}
					
				}
				
			}
									//Teclado
			A(renderer);

			ultimoTiempo = tiempoActual;
			tiempoActual = SDL_GetTicks() - tiempoEmpezar;
			if (SDL_GetTicks() - (ultimoTiempo + tiempoEmpezar) < 100) {

				SDL_Delay(100 - (SDL_GetTicks() - (ultimoTiempo + tiempoEmpezar)));

			}
			C(renderer, tiempoActual - ultimoTiempo, &posicionPerro,velDog);
			F(renderer, tiempoActual - ultimoTiempo, &posicionHeli,velHeli);
			SDL_RenderPresent(renderer);
		}

		//SDL_RenderPresent(renderer);
		//SDL_Delay(5000);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}




int A(SDL_Renderer* render) {

	SDL_Texture* fondo; // Variable para la textura
	string filename = "..\\images\\background1.png"; // Nombre del fichero con la imagen .bmp
	SDL_Surface* surface = IMG_Load(filename.c_str()); // Solo para bmps
	fondo = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
	SDL_RenderCopy(render, fondo, NULL, NULL);
	return 0;
}

int B(SDL_Renderer* render) {
	SDL_Texture* perro; // Variable para la textura
	string filename = "..\\images\\dog.png"; // Nombre del fichero con la imagen .bmp
	SDL_Surface* surface = IMG_Load(filename.c_str()); // Solo para bmps
	perro = SDL_CreateTextureFromSurface(render, surface);
	SDL_Rect source;
	SDL_Rect dest;   
	source.x = source.y = 0;
	source.w = 128;
	source.h = 82;
	dest.x = 0;
	dest.y = 500;
	dest.w = 128;
	dest.h = 82;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(render, perro, &source, &dest);

	return 1;
}

int C(SDL_Renderer* render, int tiempoFrame, int* posPerro,int velDog) {


	//srcRect.x = textFrameW * int(((SDL_GetTicks() / TIME_PER_FRAME) % 6));

	SDL_Texture* perro; // Variable para la textura
	string filename = "..\\images\\dog.png"; // Nombre del fichero con la imagen .bmp
	SDL_Surface* surface = IMG_Load(filename.c_str()); // Solo para bmps
	perro = SDL_CreateTextureFromSurface(render, surface);
	SDL_Rect source;
	SDL_Rect dest;
	source.x = 128 * int(((SDL_GetTicks() / tiempoFrame) % 6));
	source.y = 0;
	source.w = 128;
	source.h = 82;
	if (*posPerro > 800) {
		*posPerro = 0;
	}
	*posPerro +=velDog;
	dest.x = *posPerro;
	dest.y = 500;
	dest.w = 128;
	dest.h = 82;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(render, perro, &source, &dest);

	return 1;
}

int F(SDL_Renderer* render, int tiempoFrame, int* posHeli, int velHeli) {
	//srcRect.x = textFrameW * int(((SDL_GetTicks() / TIME_PER_FRAME) % 6));
	SDL_Texture* heli; // Variable para la textura
	string filename = "..\\images\\helicopter.png"; // Nombre del fichero con la imagen .bmp
	SDL_Surface* surface = IMG_Load(filename.c_str()); // Solo para bmps
	heli = SDL_CreateTextureFromSurface(render, surface);
	SDL_Rect source;
	SDL_Rect dest;
	source.x = 128 * int(((SDL_GetTicks() / tiempoFrame) % 5));
	source.y = 0;
	source.w = 128;
	source.h = 82;
	if (*posHeli < 0) {
		*posHeli = 800;
	}
	*posHeli -= velHeli;
	dest.x = *posHeli;
	dest.y = 0;
	dest.w = 128;
	dest.h = 82;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(render, heli, &source, &dest);

	return 1;
}


int main(int argc, char* argv[]) {
	firstTest();
	return 0;
}