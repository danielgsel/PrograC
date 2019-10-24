#pragma once
#include "Texture.h"
#include "Vector2D.h"
class Marcador
{
private:

	Texture* texture;
	Texture* arrowTexture;
	int points = 0;
	int arrows = 5;
	int w = 40;
	int h = 40;
	int row = 0;
	int x = 0;
	int y = 0;
	Vector2D position = Vector2D(x, y);
	
public:
	Marcador(){}

	Marcador(Texture* textura, Texture* arrow,int numArrows) :texture(textura), arrowTexture(arrow),arrows(numArrows) {}
	void render();
	void SetPoints(int newpoints);
	void arrowShot();
	int arrowsLeft();
	int digits(int number);
};

