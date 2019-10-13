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

	/*Orden de las texturas para cargar
	0=background
	1=arco sin cargar
	2=arco cargado
	3=flecha horizontal
	4=flecha vertical
	5=globos
	6=letras
	*/

	textures[0]->load("..\\images\\bg1.png");
	textures[1]->load("..\\images\\Bow2.png");
	textures[2]->load("..\\images\\Bow1.png");
	textures[3]->load("..\\images\\Arrow1.png");
	textures[4]->load("..\\images\\Arrow2.png");
	textures[5]->load("..\\images\\balloons.png",7,6);
	textures[6]->load("..\\images\\digits1.png");

	 bow = new Bow(160,160,textures[1]);
	 for (int i = 0; i < numBalloons; i++) {
		 ballons.push_back(new Ballon(160,160,textures[5]));
	 }

	

}

Game::~Game() {
	for (uint i = 0; i < numTextures; i++) {
		delete textures[i];
	}	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}



void Game::run() {
	int tiempoActual, tiempoEmpezar, ultimoTiempo;
	tiempoEmpezar = SDL_GetTicks();

	//Carga de todos los objetos
	bow->load();
	for (int i = 0; i < numBalloons; i++) {
		ballons.at(i)->load();
	}
	
	//BUCLE PRINCIPAL DEL JUEGO
	while (!exit) {
		tiempoActual = SDL_GetTicks() - tiempoEmpezar;
		handleEvents();
		update();
		render();
		ultimoTiempo = tiempoActual;
		tiempoActual = SDL_GetTicks() - tiempoEmpezar;
		//DELAY PARA CONTROLAR LOS FPS
		if (SDL_GetTicks() - (ultimoTiempo + tiempoEmpezar) < 1000) {
			SDL_Delay(100 - (SDL_GetTicks() - (ultimoTiempo + tiempoEmpezar)));
		}
	}
}

void Game::update() {

	bow->update();
	//Los globos al estar en un array todos guardados lo hago con el bucle, las flechas tienen una estructura similar por lo que será lo mismo
	for (int i = 0; i < numBalloons; i++) {
		ballons.at(i)->update();
	}


	//Hacer un metodo privado que se encargue de generar globos
}

void Game::render() const {
	SDL_RenderClear(renderer);
	SDL_Rect dest;
	dest.x = 0;	dest.y = 0;
	dest.w = winWidth; dest.h = winHeight;	
	textures[0]->render(dest);
	bow->render();
	for (int i = 0; i < numBalloons; i++) {
		ballons.at(i)->render();
	}
	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		bow->handleEvents(event);		
	}
	
}
