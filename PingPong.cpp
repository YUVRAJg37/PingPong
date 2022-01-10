
#include <iostream>


enum Direction
{
	STOP = 0,
	LEFT = 1,
	UPLEFT = 2,
	DOWNLEFT = 3,
	RIGHT = 4,
	UPRIGHT = 5,
	DOWNRIGHT = 6
};

class Ball
{
private:

	int x, y;
	int originalx, originaly;
	Direction Dir;

public:

	Ball(int posx, int posy)
	{
		x = posx;
		y = posy;
		originalx = posx;
		originaly = posy;

		Dir = STOP;
	}

	inline int GetX() { return x; }
	inline int GetY() { return y; }
	inline Direction GetDirection() { return Dir; }
};

int main()
{
	return 0;
}