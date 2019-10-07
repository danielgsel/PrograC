#include "DOG.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>


using namespace std;


DOG::DOG() {
	velX = 0;
	velY = 0;
	texture = nullptr;
}
void DOG::print(SDL_Renderer* render) {
	texture->Print(render);
}

void DOG::actPos(SDL_Renderer* render ) {

	texture->Move(velX,velY);
}

void DOG::newTexture(SDL_Renderer* render ,string file) {
	texture = new Textura();
	texture->Load(render ,file);
}