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
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;

	for (uint i = 0; i < numTextures; i++) {
		textures[i] = new Texture(renderer);

	}
	dog = new DOG(82,82,0,0,textures[1]);
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
	while (!exit) {
		handleEvents();
		update();
		render();

	}
}

void Game::update() {
	dog->update();

}

void Game::render() const {
	SDL_RenderClear(renderer);

	dog->render();
	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
	}
	dog->handleEvents(event);
}
