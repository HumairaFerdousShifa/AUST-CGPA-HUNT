/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
# include <iostream>
#include<cstdlib>
using namespace std;
#define screenWidth 1280 // towards x axis
#define screenHeight 720 // towards y axis


int playerPosX , playerPosY; // player coordinates
int pointX[10], pointY[10]; // point coordinates

bool playerCanJump = false; // if true player can jump;

int jump = 30;
int button = 0;
int page = 1;


void startGame()
{
	// ishowbmp - newgame, instruction , about , background
	//iShowBMP(0,0,"Background.bmp");
	
	iShowBMP(100,100 , "newGame.bmp");
	iShowBMP(100,150 , "option.bmp");
	iShowBMP(100,200 , "instruction.bmp");

	if(button == 1)
	{
		iShowBMP(100,100, "newGame1.bmp");
	}

}

void Game()
{
	
}
	char pointImage [10][25]; 
	char bg[32][25]={"bg.bmp"}; 
	char kyo[10][25] = {"char\\1_100-0.bmp","char\\1_100-1.bmp","char\\1_100-2.bmp","char\\1_100-3.bmp","char\\1_100-4.bmp","char\\1_100-5.bmp","char\\1_100-6.bmp","char\\1_100-7.bmp","char\\1_100-8.bmp","char\\1_100-9.bmp"};
	int kyocoX = 0;
	int kyocoY = 50;
	int kyoinD = 0;
	
	int imageSliceLength = 40 ; // total screenwidth / number of slice(32) = 40 px

	struct pointProperties
	{
		int x;
		int y;
		//int status;
		//bool enemy;
	} point[10];

	struct backGroundImage 
	{
		int x ;
		int y;
	} background[32];
	

void pointInitialize()
{

	point[0].x = 0;
	point[0].y = rand() % 400;

	for(int i = 1 ; i < 10 ; i++)
	{
		point[i].x = point[i-1].x + 40;
		point[i].y = rand() % 400;
	}
}

void initializeBackGround()
{
	background[0].x = 0;

	for(int i = 1 ; i < 32 ; i++)
	{
		background[i].x += (background[i-1].x + imageSliceLength);
		background[i].y = 0;
	}
}

void iDraw()
{
	//place your drawing codes here	

	iClear();
	//iShowBMP(0,0,"bg.bmp");
	
	for(int i = 0 ; i < 32 ; i++)
	{
			//iShowBMP(background[i].x, background[i].y , bg[i] ); slice width - 40 , slice height - 720 , slices
			//iShowBMP(point[i].x, point[i].y , pointImage[i] );
	}
	
	iShowBMP2(kyocoX, kyocoY , kyo[kyoinD] , 255);
	
	

	if(page == 0)
		startGame();
	if(page==1)
		Game();

}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
	
	}
	if(key == 'r')
	{
		
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{




	// character control

	if(key == GLUT_KEY_RIGHT && kyocoX < screenWidth - 250)
		kyocoX += 10;
	else if (key == GLUT_KEY_LEFT && kyocoX >  0)
		kyocoX -= 10;

	/*

	if(page == 0)// start page
	{
		if(key == GLUT_KEY_DOWN)
			button ++;
		if (key == GLUT_KEY_UP)
			button--;

		if(button == -1)
			button = 2;
	}

	if(page == 1) // game page
	{
		if(key == GLUT_KEY_UP)
		{
			if(playerCanJump)
			{

			}
		}
	}
	if(key== GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
	*/
}

void update()
{
	kyoinD++;
	if(kyoinD>=10)
	{
		kyoinD = 0;
	}

	// backGround render

	for(int i = 0 ; i < 32 ; i++)
	{
		background[i].x -= 20;

		if(background[i].x < 0)
			background[i].x = screenWidth;

	}
	// point render;
	for(int i = 0 ; i < 10 ; i++)
	{
		point[i].x -= 10;

		if(point[i].x < 0)
			point[i].x = screenWidth + 100;
	}

}



int main()
{

	int charChange = iSetTimer(150 , update );
	iResumeTimer(charChange);

	iInitialize(screenWidth , screenHeight , "AUST CGPA Hunt");

	return 0;
}	