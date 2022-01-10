// PingPong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
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

    void Move()
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

    friend  ostream& operator<<(ostream& Out, Ball b)
    {
        Out << "Ball [" << b.x << "," << b.y << "]" << " " << b.Direction <<"\n";
        return Out;
    }

    inline int GetX() { return x; }
    inline int GetY() { return y; }
    inline Dir GetDirection() { return Direction; }
};

class Paddle
{
private:

    int x, y;
    int originalX, originalY;

public:

    Paddle(int posX, int posY)
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }

    void Reset()
    {
        x = originalX;
        y = originalY;
    }

    void MoveUp()
    {
        y--;
    }

    void MoveDown()
    {
        y++;
    }

    inline int GetX() { return x; }
    inline int GetY() { return y; }

    friend ostream& operator<<(ostream& out, Paddle p)
    {
        out << "Paddle [" << p.x << "," << p.y << "]" << "\n";
        return out;
    }
};

class GameManager
{
private:
    int height, width;
    char up1, down1, up2, down2;
    int score1, score2;
    bool quit;

    Ball* b;
    Paddle* p1;
    Paddle* p2;

public:

    GameManager(int w, int h)
    {
        height = h; width = w;
        up1 = 'w'; down1 = 's'; up2 = 'r'; down2 = 'f';
        score1 = score2 = 0;
        quit = false;

        b = new Ball(w / 2, h / 2);
        p1 = new Paddle(1, h / 2 - 3);
        p2 = new Paddle(w - 2, h / 2 - 3);

    }

    ~GameManager()
    {
        delete b, p1, p2;
    }

    void ScoreUp(Paddle *player)
    {
        if (player == p1)
            score1++;
        if (player == p2)
            score2++;

        b->Reset();
        p1->Reset();
        p2->Reset();
    }

    void Draw()
    {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            cout << "\xB2";
    	cout<<endl;

        for (int i=0; i< height; i++)
        {
           for(int j=0; j<width; j++)
           {
               int ballX = b->GetX();
               int ballY = b->GetY();
               int p1X = p1->GetX();
               int p2X = p2->GetX();
               int p1Y = p1->GetY();
               int p2Y = p2->GetY();

               if (j == 0)
                   cout <<  "\xB2";

               if (ballX == j && ballY == i)
                   cout << "O";
               else if (p1X == j && p1Y == i)
                   cout << "\xDB";
               else if (p1X == j && p1Y + 1 == i)
                   cout << "\xDB";
               else if (p1X == j && p1Y + 2== i)
                   cout << "\xDB";
               else if (p1X == j && p1Y + 3 == i)
                   cout << "\xDB";
               else if (p1X == j && p1Y + 4== i)
                   cout << "\xDB";

               else if (p2X == j && p2Y == i)
                   cout << "\xDB";
               else if (p2X == j && p2Y + 1 == i)
                   cout << "\xDB";
               else if (p2X == j && p2Y + 2 == i)
                   cout << "\xDB";
               else if (p2X == j && p2Y + 3 == i)
                   cout << "\xDB";
               else if (p2X == j && p2Y + 4 == i)
                   cout << "\xDB";
               else
                   cout << " ";

               if (j == width - 1)
                   cout << "\xB2";
           }
           cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "\xB2";

        cout << endl;
        cout << "Score 1 : " << score1 << endl << "Score 2 : " << score2;
    }

    void Input()
    {
        b->Move();

        int ballX = b->GetX();
        int ballY = b->GetY();
        int p1X = p1->GetX();
        int p2X = p2->GetX();
        int p1Y = p1->GetY();
        int p2Y = p2->GetY();

	    if(_kbhit())
	    {
            char currentKey = _getch();
            if (currentKey == up1 && p1Y > 0)
                p1->MoveUp();
            if (currentKey == up2 && p2Y > 0)
                p2->MoveUp();
            if (currentKey == down1 && p1Y + 4 < height)
                p1->MoveDown();
            if (currentKey == down2 && p2Y + 4 < height)
                p2->MoveDown();

            if (b->GetDirection() == STOP)
                b->RandomDirection();

            if (currentKey == 'q')
                quit = true;
	    }
    }

    void Logic()
    {
        int ballX = b->GetX();
        int ballY = b->GetY();
        int p1X = p1->GetX();
        int p2X = p2->GetX();
        int p1Y = p1->GetY();
        int p2Y = p2->GetY();

        for (int i = 0; i < 4; i++)
            if (ballX == p1X + 1 && ballY == p1Y + i)
                b->ChangeDirection((Dir)((rand() % 3) + 4));

        for (int i = 0; i < 4; i++)
            if (ballX == p2X - 1 && ballY == p2Y + i)
                b->ChangeDirection((Dir)((rand() % 3) + 1));

        if (ballY == height - 1)
            b->ChangeDirection((b->GetDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT));

        if (ballY == 0)
            b->ChangeDirection((b->GetDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT));

        if (ballX == width - 1)
            ScoreUp(p1);

        if (ballX == 0)
            ScoreUp(p2);

    }

    void RUN()
    {
	    while(!quit)
	    {
            Draw();
            Input();
            Logic();
	    }
    }
};

int main()
{
    GameManager GM(40, 20);

    GM.RUN();

    return 0;
}

