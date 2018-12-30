

class Tile
{
public:
	Tile * up;
	Tile * down;
	Tile * left;
	Tile * right;
	
	int gridPosX;
	int gridPosY;
	int absPosX;
	int absPosY;

	Tile(int _posX, int _posY);
	
	void draw();
};