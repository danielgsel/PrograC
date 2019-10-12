#include "Game.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>
#include "Texture.h"
#include "DOG.h"


using namespace std;

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Untitled Dog Game", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;

	for (uint i = 0; i < numTextures; i++) {
		textures[i] = new Texture(renderer);

	}
	bow = new Bow(160,160,0,315,textures[1]);

	

	textures[0]->load("..\\images\\bg1.png");

	

}

Game::~Game() {
	for (uint i = 0; i < numTextures; i++) {
		delete textures[i];
	}
	delete dog;
	

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}



void Game::run() {
	int tiempoActual, tiempoEmpezar, ultimoTiempo;
	tiempoEmpezar = SDL_GetTicks();
	dog ->load();
	
	


	while (!exit) {
		tiempoActual = SDL_GetTicks() - tiempoEmpezar;

		handleEvents();
		update();
		render();



		ultimoTiempo = tiempoActual;
		tiempoActual = SDL_GetTicks() - tiempoEmpezar;
		if (SDL_GetTicks() - (ultimoTiempo + tiempoEmpezar) < 100) {

			SDL_Delay(100 - (SDL_GetTicks() - (ultimoTiempo + tiempoEmpezar)));

		}
	}
}

void Game::update() {
	dog->update();
	
}

void Game::render() const {
	SDL_RenderClear(renderer);


	SDL_Rect dest;
	dest.x = 0;	dest.y = 0;
	dest.w = winWidth; dest.h = winHeight;
	
	textures[0]->render(dest);


	dog->render();
	

	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		dog->handleEvents(event);
		
	}
	
}
