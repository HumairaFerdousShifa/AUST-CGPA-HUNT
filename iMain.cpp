/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

/* 
	function iDraw() is called again and again by the system.
*/

int width=1362;
int height=1026;
int dsx=600;
int dsy=258;
int z1x=93;
int z1y=258;
int z2x=1178;
int z2y=258;
int z3x=93;
int z3y=258;
int z4x=1178;
int z4y=258;
int z5x=93;
int z5y=258;
int z6x=1178;
int z6y=258;
int leftBallX;
int	leftBallY;
int rightBallX;
int	rightBallY;
int life1x=1200;
int life1y=950;
int life2x=1177;
int life2y=950;
int life3x=1233;
int life3y=950;

bool z1=true;
bool z2=true;
bool z3=false;
bool z4=false;
bool z5=false;
bool z6=false;
bool ballL=false;
bool ballR=false;
bool life1=true;
bool life2=true;
bool life3=true;
bool level1=true;
bool level2=false;

void moveZ1(){
	
	iShowBMP2(z1x,z1y,"Zombie1.bmp",0);
	z1x=z1x+1;
	if(rightBallX>z1x && rightBallX<(z1x+128))
	{
		rightBallX=width+100000;
		z1x=width+100000;
		z1=false;
		ballR=false;
	}
}


void moveZ2(){
	
	iShowBMP2(z2x,z2y,"Zombie2.bmp",255);
	z2x=z2x-1;
	if(leftBallX>z2x && leftBallX<(z2x+128))
	{
		leftBallX=width+100000;
		z2x=width+100000;
		z2=false;
		ballL=false;
	}
}

void moveZ3(){
	
	iShowBMP2(z3x,z3y,"Zombie3.bmp",255);
	z3x=z3x+1;
	if(rightBallX>z3x && rightBallX<(z3x+128))
	{
		rightBallX=width+100000;
		z3x=width+100000;
		z3=false;
		ballR=false;
	}
}

void moveZ4(){
	
	iShowBMP2(z4x,z4y,"Zombie4.bmp",255);
	z4x=z4x-1;
	if(leftBallX>z4x && leftBallX<(z4x+128))
	{
		leftBallX=width+100000;
		z4x=width+100000;
		z4=false;
		ballL=false;
	}
}

void moveZ5(){
	
	iShowBMP2(z5x,z5y,"Zombie5.bmp",255);
	z5x=z5x+1;
	if(rightBallX>z5x && rightBallX<(z5x+128))
	{
		rightBallX=width+100000;
		z5x=width+100000;
		//z5=false;
		ballR=false;
	}
}


void moveZ6(){
	
	iShowBMP2(z6x,z6y,"Zombie6.bmp",255);
	z6x=z6x-1;
	if(leftBallX>z6x && leftBallX<(z6x+128))
	{
		leftBallX=width+100000;
		z6x=width+100000;
		z6=false;
		ballL=false;
	}
}




void moveBallL(){
	
	iFilledCircle(leftBallX,leftBallY,3);
	leftBallX=leftBallX+10;
	
}

void moveBallR(){
	
	iFilledCircle(rightBallX,rightBallY,3);
	rightBallX=rightBallX-10;
}


void firstLevel(){

	if(z5x>10000)
		z1=true;
		if(z1)
	moveZ1();
		if(z6x>10000)
		z2=true;
	if(z2)
	moveZ2();
	
	if(z1x==190 || z1x>10000)
		z3=true;
	if(z3)
	moveZ3();
	
	if(z2x==1080 || z2x>10000)
		z4=true;	
	if(z4)
	moveZ4();
	
	if(z3x==190 || z3x>10000)
		z5=true;
	if(z5)
	moveZ5();
	
	if(z4x==1080 || z4x>10000)
		z6=true;	
	if(z6)
	moveZ6();

	iSetColor(255,0,0);
	if(ballL)
		moveBallL();
	if(ballR)
		moveBallR();
	
}


void life(){

	if(life1)
	iShowBMP2(1200,950,"Life.bmp",255);
	if(life2)
	iShowBMP2(1167,950,"Life.bmp",255);
	if(life3)
	iShowBMP2(1233,950,"Life.bmp",255);


}


void iDraw()
{
	//place your drawing codes here	
	iClear();
	iShowBMP(0,0,"background.bmp");
	iShowBMP2(0,258,"tunnel1.bmp",255);
	iShowBMP2(1270,258,"tunnel2.bmp",255);
	iShowBMP2(0,422,"road1.bmp",255);
	iShowBMP2(1080,422,"road2.bmp",255);
	iShowBMP2(0,510,"tunnel1.bmp",255);
	iShowBMP2(1270,510,"tunnel2.bmp",255);

	life();

	iShowBMP2(dsx,dsy,"deadshot.bmp",255);

	if(level1)
	firstLevel();
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
	if(key=='d' || key=='D')
	{

		ballL=true;
		leftBallX=dsx+92;
		leftBallY=dsy+122;
	}

	if(key=='a' || key=='A')
	{
		ballR=true;
		rightBallX=dsx;
		rightBallY=dsy+122;
	}




	if(key == 'q')
	{
		//do something with 'q'
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

	if(key==GLUT_KEY_LEFT){
		dsx=dsx-3;

	}

	if(key==GLUT_KEY_RIGHT){
		dsx=dsx+3;

	}




	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}


void dsMove(){

	dsx=dsx+7;
}

void lifeChecking(){
	if(dsx==z1x || dsx==z2x || dsx==z3x || dsx==z4x || dsx==z5x || dsx==z6x)
	{
		if(life1==false)
		{
			life2x=10000;
			life2=false;
		}
		else if(life2==false)
		{
			life3=false;
			life3x=10000;
		}
		else
		{
			life1=false;
			life1x=10000;
		}
	}

}


int main()
{
	//place your own initialization codes here. 
	
	//iSetTimer(1,firstLevel);

	iInitialize(width, height, "demooo");
	iSetTimer(1,lifeChecking);
	return 0;
}	