// PingPong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum Dir
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
    int originalX, originalY;
    Dir Direction;

public:

    Ball(int posX, int posY)
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
        Direction = STOP;
    }

    void Reset()
    {
        x = originalX;
        y = originalY;
        Direction = STOP;
    }

    void ChangeDirection(Dir NewDirection)
    {
        Direction = NewDirection;
    }

    void RandomDirection()
    {
        Direction = (Dir)((rand() % 6) + 1);
    }

    void ChangeDirection()
    {
	    switch (Direction)
	    {
	    case STOP :
		    {
				break;
		    }
	    case LEFT :
		    {
				x--;
                break;
		    }
	    case UPLEFT :
		    {
	            x--;
	            y--;
	            break;
		    }
	    case DOWNLEFT :
		    {
	            y++;
	            x--;
	            break;
		    }
	    case RIGHT :
		    {
				x++;
                break;
		    }
	    case UPRIGHT :
		    {
				x++;
				y--;
                break;
		    }
	    case DOWNRIGHT :
		    {
				x++;
				y++;
                break;
		    }
	    default :
		    {
			    break;
		    }
	    }
    }

    inline int GetX() { return x; }
    inline int GetY() { return y; }
    inline Dir GetDirection() { return Direction; }
};


int main()
{
    std::cout << "Hello World!\n";
}

