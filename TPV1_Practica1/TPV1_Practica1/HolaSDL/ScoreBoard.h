//Alumno1: David Czepiel
//Alumno2 : Daniel González Sellán
#include "Texture.h"
#include "Vector2D.h"
class ScoreBoard
{
private:

	Texture* texture;
	Texture* arrowTexture;
	int points = 0;
	int arrows = 5;
	int w = 40;
	int h = 40;
	int row = 0;
	Vector2D position = Vector2D(0, 0);
	
public:
	ScoreBoard(){}

	ScoreBoard(Texture* textura, Texture* arrow,int numArrows) :texture(textura), arrowTexture(arrow),arrows(numArrows) {}
	void render();
	int getPoints();
	void SetPoints(int newpoints);
	void arrowShot(int arr);
	int digits(int number);
};

