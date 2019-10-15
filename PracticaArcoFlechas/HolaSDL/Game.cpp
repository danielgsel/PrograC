#include "Game.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>
#include "Texture.h"



using namespace std;

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Untitled Dog Game", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;


	/*Orden de las texturas para cargar
	0=background
	1=arco sin cargar
	2=arco cargado
	3=flecha horizontal
	4=flecha vertical
	5=globos
	6=letras
	*/

	textures[0] = new Texture(renderer, "..\\images\\bg1.png");
	textures[1]= new Texture(renderer, "..\\images\\Bow2.png"); 
	textures[2] = new Texture(renderer, "..\\images\\Bow1.png");
	textures[3] = new Texture(renderer, "..\\images\\Arrow1.png"); 
	textures[4] = new Texture(renderer, "..\\images\\Arrow2.png"); 
	textures[5] = new Texture(renderer, "..\\images\\balloons.png",7,6);
	textures[6] = new Texture(renderer, "..\\images\\digits1.png",1,10);

	 bow = new Bow(100,100,textures[1]);
	 for (int i = 0; i < numBalloons; i++) {
		 ballons.push_back(new Ballon(100,100,textures[5]));
	 }

	

}

Game::~Game() {
	//Destruyo todos los objetos  teniendo en cuenta que pueden estar en vectores
	bow->~Bow();
	bow = nullptr;
	for (int i = 0; i < ballons.size(); i++) {
		ballons.at(i)->~Ballon();
		ballons.at(i) = nullptr;
	}
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
		if (ballons.at(i)->update()) {    // Si alguno me dice que se ha salido de antalla genero uno nuevo
			generateBalloons(&ballons, i);
		}
	}
}

void Game::generateBalloons(vector<Ballon*>* ball, int i) {
	//Borro de memoria el globo que se acaba de salir de pantalla y creo uno nuevo en su lugar en el vector de globos
			ball->at(i)->~Ballon();
			ball->at(i) = new Ballon(100, 100, textures[5]);
}

void Game::render() const {
	SDL_RenderClear(renderer);
	//Prepao el rect donde se va a dibujar
	SDL_Rect dest;
	dest.x = 0;	dest.y = 0;
	dest.w = winWidth; dest.h = winHeight;	
	textures[0]->render(dest);
	//LLamo a cada objeto para que se dibuje
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
