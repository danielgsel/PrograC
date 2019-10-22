#pragma once
#include "Texture.h"
#include "Vector2D.h"
class Marcador
{
private:

	Texture* texture;
	int points = 0;
	int w = 40;
	int h = 40;
	int row = 0;
	int x = 0;
	int y = 0;
	Vector2D position = Vector2D(x, y);
	
public:
	Marcador(){}

	Marcador(Texture* textura) :texture(textura) {}
	void render();
	void SetPoints(int newpoints);
	int digits(int number);
};

