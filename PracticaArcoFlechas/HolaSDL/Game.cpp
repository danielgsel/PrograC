#include "Game.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <math.h>
#include <string>
#include "Texture.h"
#include <fstream>



using namespace std;

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arco/Flechas", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		throw  (string)"Error cargando SDL";

	/*Orden de las texturas para cargar
	0=background
	1=arco sin cargar
	2=arco cargado
	3=flecha horizontal
	4=flecha vertical
	5=globos
	6=letras
	*/

		for (int i = 0; i < numTextures; i++) {
			textures[i] = new Texture(renderer, mytextures[i].file, mytextures[i].row, mytextures[i].col);
		}
		bow = new Bow( textures[1], textures[2], this,winHeight);
		for (int i = 0; i < numBalloons; i++) {
			ballons.push_back(new Ballon( textures[5], this, i,winWidth,winHeight));
		}
		marcador = new Marcador(textures[6], textures[4], numArrows);

}

Game::~Game() {
	//Destruyo todos los objetos  teniendo en cuenta que pueden estar en vectores

	delete bow;
	bow = nullptr;
	delete marcador;
	marcador = nullptr;

	for (int q = 0; q < arrows.size(); q++)
	{
		delete arrows.at(q);
		arrows.at(q) = nullptr;
	}
	for (int i = 0; i < ballons.size(); i++) {
		delete ballons.at(i);
		ballons.at(i) = nullptr;
	}
	for (int i = 0; i < numTextures; i++) {
		delete textures[i];
		textures[i] = nullptr;
	}	

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


void Game::run() {
	//Mientras no quiera salir o me quede municion o mi ultima flecha siga en el aire. Sigo jugando
	while (!exit && !(numArrows<1 && arrows.size()<1)) {
		
		handleEvents();
		update();
		render();
		//DELAY PARA CONTROLAR LOS FPS
		SDL_Delay(FRAMERATE);
	}
}

void Game::update() {
	bow->update();
	//Los globos y flechas se tienen que recorrer con bucles
	for (int i = 0; i < numBalloons; i++) {
		if (ballons.at(i)->update()) {    // Si alguno me dice que se ha salido de antalla genero uno nuevo
			generateBalloons(&ballons, i);
		}
	}
	//Muevo las flechas y en caso de que se hayan salido de pantalla las borro
	for (int i = 0; i < arrows.size(); i++) {
		if (arrows.at(i)->update()) {
			delete arrows.at((i));
			arrows.erase(arrows.begin() + i);
		}
	}	
	
}

	//Borro de memoria el globo que se acaba de salir de pantalla y creo uno nuevo en su lugar en el vector de globos
void Game::generateBalloons(vector<Ballon*>* ball, int i) {
			delete ball->at(i);
			ball->at(i) = new Ballon( textures[5], this, i,winWidth,winHeight);
}

void Game::render() const {
	SDL_RenderClear(renderer);
	//Primero renderizo el fondo
	SDL_Rect dest;
	dest.x = 0;	dest.y = 0;
	dest.w = winWidth; dest.h = winHeight;	
	textures[0]->render(dest);
	//LLamo a cada objeto para que se dibuje
	marcador->render();                       //Dibuo antes el marcador para que no tape al arco
	bow->render();
	for (int i = 0; i < numBalloons; i++) {
		ballons.at(i)->render();
	}
	for (int i = 0; i < arrows.size(); i++) {
		arrows.at(i)->render();
	}
	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT)
			exit = true;
		bow->handleEvents(event);		
	}
}

//Creo un nueva flecha, si la rotacion que me llega no es nula, calculo sus componentes x e y
void Game::newArrow(double x, double y,int speed,int rotatio) {
	Arrow* arrow = new Arrow(x,y, textures[3],rotatio, winWidth,winHeight);
	arrows.push_back(arrow);
	numArrows--;
	cout << "Arrows left="<<numArrows<<endl;
	marcador->arrowShot(numArrows);
	if (rotatio == 0)
	arrow->setVel(speed, 0);
	else {
		int VelX = cos(-((rotatio* M_PI) / 180)) * speed;
		int VelY = -sin(-((rotatio * M_PI) / 180)) * speed;   //Si la speed es demasiado pequeño esto va a dar 0, aunque haya algo de rotacion
		arrow->setVel(VelX, VelY);
	}
}


//Por cada globo que me llega compruebo si alguna de las flechas le ha dado
bool Game::arrowHitsBaloon(SDL_Rect baloon) {
	int i = 0;
	bool hit = false;
	while ((i < arrows.size()) && (hit == false)) {
		SDL_Rect res = SDL_Rect();
		hit = SDL_IntersectRect(&baloon, &arrows.at(i)->GetRect(), &res);
		i++;
	}

	return hit;
}


//Borro el globo de la posicion pos del vector de globos y en su lugar creo uno nuevo
void Game::destroyBaloon(int pos) {
	delete ballons.at(pos);
	ballons.at(pos) = new Ballon( textures[5],  this, pos,winWidth,winHeight);
	puntuacion++;
	cout << "Points="<<puntuacion<<endl;
	marcador->SetPoints(puntuacion);
}


//Devuele la municion restante
int Game::arrowsLeft() {
	return numArrows;
}