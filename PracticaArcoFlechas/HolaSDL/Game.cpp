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

	//Hay que pensar en una forma mejor de inicializar las cosas
	textures[0] = new Texture(renderer, "..\\images\\bg1.png");
	textures[1]= new Texture(renderer, "..\\images\\Bow2.png"); 
	textures[2] = new Texture(renderer, "..\\images\\Bow1.png");
	textures[3] = new Texture(renderer, "..\\images\\Arrow1.png"); 
	textures[4] = new Texture(renderer, "..\\images\\Arrow2.png"); 
	textures[5] = new Texture(renderer, "..\\images\\balloons.png",7,6);
	textures[6] = new Texture(renderer, "..\\images\\digits1.png",1,10);


	 bow = new Bow(100,100,textures[1],velBow, this);
	 for (int i = 0; i < numBalloons; i++) {
		 ballons.push_back(new Ballon(100,100,textures[5], velBallon, this, i));
	 }
	 marcador = new Marcador(textures[6],textures[4],numArrows);

}

Game::~Game() {
	//Destruyo todos los objetos  teniendo en cuenta que pueden estar en vectores
	delete bow;
	bow = nullptr;
	for (int i = 0; i < ballons.size(); i++) {
		delete ballons.at(i);
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
	//BUCLE PRINCIPAL DEL JUEGO

	ifstream puntuaciones;
	puntuaciones.open("puntuaciones.txt");
	if (puntuaciones.is_open()) {
		vector<int> record;
		for (int j = 0; j < 10; j++) {
			int punt = 0;
			puntuaciones >> punt;
			record.push_back(punt);
		}
		puntuaciones.close();
		int k = 0;
		while (k<record.size() && record.at(k)<marcador->getPoints()) {
			k++;
		}
		if (k < record.size())
			record.at(2) = 10;
		ofstream actualizar;
		actualizar.open("puntuaciones.txt");
		for (int i = 0; i < record.size(); i++)
			actualizar << record.at(i) << endl;

	}
	else {


		ofstream myfile;
		myfile.open("puntuaciones.txt");
		myfile << marcador->getPoints() << endl;

		for (int i = 0; i < 9; i++)
			myfile << 0 << endl;
		myfile.close();
	}
	while (!exit) {
		
		handleEvents();
		update();
		render();

		//DELAY PARA CONTROLAR LOS FPS
		SDL_Delay(FRAMERATE);
	}
	
	
	


}

void Game::update() {

	bow->update();
	//Los globos al estar en un array todos guardados lo hago con el bucle, las flechas tienen una estructura similar por lo que ser� lo mismo
	for (int i = 0; i < numBalloons; i++) {
		if (ballons.at(i)->update()) {    // Si alguno me dice que se ha salido de antalla genero uno nuevo
			generateBalloons(&ballons, i);
		}
	}

	for (int i = 0; i < arrows.size(); i++) {
		if (arrows.at(i)->update()) {

			delete arrows.at((i));
			arrows.erase(arrows.begin() + i);
			

		}
	}

	
	
}

void Game::generateBalloons(vector<Ballon*>* ball, int i) {
	//Borro de memoria el globo que se acaba de salir de pantalla y creo uno nuevo en su lugar en el vector de globos
			delete ball->at(i);
			ball->at(i) = new Ballon(100, 100, textures[5],velBallon, this, i);
}

void Game::render() const {
	SDL_RenderClear(renderer);
	//Prepao el rect donde se va a dibujar
	SDL_Rect dest;
	dest.x = 0;	dest.y = 0;
	dest.w = winWidth; dest.h = winHeight;	
	textures[0]->render(dest);
	//LLamo a cada objeto para que se dibuje
	marcador->render();                       //Me interesa que se renderice primero el marcador porque asi no tapa al arco
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
		if (event.type == SDL_QUIT) exit = true;
		bow->handleEvents(event);		
	}



}

void Game::newArrow(double x, double y,int speed,int rotatio) {
	

	Arrow* arrow = new Arrow(x,y, textures[3],rotatio);
	arrows.push_back(arrow);
	marcador->arrowShot();
	if (rotatio == 0)
	arrow->setVel(speed, 0);
	else {
		int VelX = cos(-((rotatio* M_PI) / 180)) * speed;
		int VelY = -sin(-((rotatio * M_PI) / 180)) * speed;   //Si la speed es demasiado peque�o esto va a dar 0, la culpa es de speed
		arrow->setVel(VelX, VelY);


	}
}


bool Game::arrowHitsBaloon(SDL_Rect* baloon) {
	int i = 0;
	bool hit = false;
	//SDL_bool hitSDL = SDL_FALSE;
	while ((i < arrows.size()) && (hit == false)) {
		SDL_Rect* res = new SDL_Rect();
		hit = SDL_IntersectRect(baloon, arrows.at(i)->GetRect(), res);
		i++;
	}

	return hit;
}


void Game::destroyBaloon(int pos) {
	delete ballons.at(pos);
	ballons.at(pos) = new Ballon(100, 100, textures[5], velBallon, this, pos);
	puntuacion++;
	marcador->SetPoints(puntuacion);
}

int Game::arrowsLeft() {
	return marcador->arrowsLeft();
}