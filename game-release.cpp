//============================================================================
// Name        : Tetris.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Tetris...
//============================================================================
#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
//#include<sys/wait.h>
//#include<stdlib.h>
//#include<stdio.h>
#include<unistd.h>
#include<sstream>
#include <bits/stdc++.h>
#include<cmath>     // for basic math functions such as cos, sin, sqrt
using namespace std;

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
int startx=32,starty=32;
int array[65][65];
int tailx[100];
int taily[100];
int foodx,foody,foodx1,foody1,foodx2,foody2,foodx3,foody3,foodx4,foody4,bonus_foodx,bonus_foody;
int hurdlex,hurdley,hurdlex1,hurdley1,hurdlex2,hurdley2,hurdlex3,hurdley3,Score=0,highscore;
int *ptr=&startx;
int key_move=1,length=4;
bool gameover;
void Display(){

   srand(time(NULL));
   int tempx,tempy,tempx2,tempy2;
   *ptr+=key_move;
   gameover=false;
   
   DrawString( 20, 630, "Score ="+to_string(Score), colors[MISTY_ROSE]);
   DrawString( 20, 610, "High Score ="+to_string(highscore), colors[BLUE_VIOLET]);
 
   		
    glClearColor(0/*Red Component*/, 0.0/*Green Component*/,
            0.0/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   //Update the colors	
   		
    
    //DrawString( 20, 630, str, colors[MISTY_ROSE]);
   		
   		
   for(int i=0;i<65;i++)//drawing the body of snake
   {
   	for(int j=0;j<65;j++)
   	{
   		for(int k=1;k<length;k++)
   		{
   			if(tailx[k]==j && taily[k]==i)
   			{
   				DrawCircle((i*10)+3.5,(j*10)+3.5,7,colors[4]);
   			}
   			if(tailx[1]==tailx[length+1] && taily[1]==taily[length+1])
   			{
   				DrawString(50,600,"GAME OVER!",colors[ORANGE]);
   				gameover=true;
 			}  		
   		}
   	}
   }	
    
  
   				 
   		
   
    for(int i=0;i<65;i++)//code to generate food and hurdles.It is  going to generate 5 food at a time one bonus food and two hurles in the 					following part of the code.
   {
   	for(int j=0;j<65;j++)
   	{
   		if(i==foody || j==foodx)
   		{
   			DrawSquare( foodx*10,foody*10 , 7 , colors[15]);
   		}
   		if(i==foody1 || j==foodx1)
   		{
   			DrawSquare( foodx1*10,foody1*10 , 7 , colors[15]);
   		}
   		if(i==foody2 || j==foody2)
   		{
   			DrawSquare( foodx2*10,foody2*10 , 7 , colors[15]);
   		}
   		if(i==foody3 || j==foodx3)
   		{
   			DrawSquare( foodx3*10,foody3*10 , 7 , colors[15]);
   		}	
   		if(i==foody4 || j==foodx4)
   		{
   			DrawSquare( foodx4*10,foody4*10 , 7 , colors[15]);
   		}
   		if(i==bonus_foody || j==bonus_foodx)
   		{
   			DrawCircle( bonus_foodx*10,bonus_foody*10 , 12 , colors[86]);
   		}	
   		if(i==hurdley || j==hurdlex)
   		{
   			DrawLine( hurdlex*10 , hurdley*10 , hurdlex*10, (hurdley*10)+80, 40 , colors[DARK_GREEN] );
   		}
   		if(i==hurdley1 || j==hurdlex1)
   		{
   			DrawLine( hurdlex1*10 , hurdley1*10 , (hurdlex1*10)+60, hurdley1*10, 20 , colors[POWDER_BLUE] );
   		}			 
   	}
   }		
   	//Randomly calling food,bonus food,hurdles		
   	if(starty==foodx && startx==foody)
	{
   		foodx=rand()%63+1;
   		foody=rand()%63+1;
   		length++;
   		Score+=10;
   	}
   	if(starty==foodx1 && startx==foody1)	
   	{
   		foodx1=rand()%63+1;
  		foody1=rand()%63+1;
   		length++;
  		Score+=10;
  	}
   	if(starty==foodx2 && startx==foody2)	
   	{
   		foodx2=rand()%63+1;
   		foody2=rand()%63+1;
   		length++;
   		Score+=10;
 	}
 	if(starty==foodx3 && startx==foody3)	
  	{
   		foodx3=rand()%63+1;
   		foody3=rand()%63+1;
   		length++;
   		Score+=10;
   	}
   	if(starty==foodx4 && startx==foody4)
   	{
   		foodx4=rand()%63+1;
   		foody4=rand()%63+1;
   		length++;
   		Score+=10;
   	}
   	if(starty==bonus_foodx && startx==bonus_foody)
   	{
   		bonus_foodx=rand()%63+1;
   		bonus_foody=rand()%63+1;
   		length++;
   		Score+=20;
   	}
   	if(starty==hurdlex && startx==hurdley)	
   	{
   		hurdlex=rand()%60+1;
   		hurdley=rand()%60+1;
  	}
   	if(starty==hurdlex1 && startx==hurdley1)	
   	{
   		hurdlex1=rand()%60+1;
   		hurdley1=rand()%60+1;
   	}

   	//conditions to check for the game to end	
    if((hurdlex<starty && hurdlex+2.5>starty)&&(hurdley<startx && hurdley+2.5>startx))
    {
    		gameover=true;
   		DrawString(50,600,"GAME OVER!",colors[ORANGE]);
   		
   		
    }	
    if((hurdlex1<starty && hurdlex1+2.5>starty)&&(hurdley1<startx && hurdley1+2.5>startx))
    {
   		gameover=true;
   		DrawString(50,600,"GAME OVER!",colors[ORANGE]);
    }	
   	
   	
   highscore=140;
	if(Score>highscore)
	{
		highscore=Score;
	}	
	
		
   //As I am not fixing the boundaries so putting checks for the snake to reappear from the same coordinates of x and y axis
   if(startx>65)
	{
		startx=0;
	}
	if(startx<0)
	{
		startx=65;
	}
	if(starty>65)
	{
		starty=0;
	}
	if(starty<0)
	{
		starty=65;
	}			
   	  
   						
	//swaping of indexes of the snake for traversing
	tempx = tailx[0];
	tempy = taily[0];
	tailx[0] = startx;
	taily[0] = starty;

	for (int i=1;i<length;i++)
	{
		tempx2 = tailx[i];
		tempy2 = taily[i];
		tailx[i] = tempx;
		taily[i] = tempy;
		tempx = tempx2;
		tempy = tempy2;

	}
	
	
   glutSwapBuffers(); // do not modify this line..
   
   
   		
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y)
{
	while(gameover==true)
	{
    	if (key == GLUT_KEY_LEFT  /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)  	
	{
		
		starty--;	
		if (key_move==1)
		{
			key_move=-1;
		}
		
		ptr=&starty;
		
	}									// what to do when left key is pressed...
      
      
     else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) 
     { 	
		starty++;	
		if (key_move==-1)
		{
			key_move=1;
		}
		ptr=&starty;								// what to do when left key is pressed...
      } 
      
      else if (key == GLUT_KEY_UP) /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/ 
      {	
		startx++;	
		if (key_move==-1)
		{
			key_move=1;
		}
		ptr=&startx;								// what to do when left key is pressed...
      }
    else if (key == GLUT_KEY_DOWN)   /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/ 
    { 	
		startx--;	
		if (key_move==1)
		{
			key_move=-1;
		}
		ptr=&startx;								// what to do when left key is pressed...
    }
    }
    

    /* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
     * this function*/
     glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
    if (key == KEY_ESC/* Escape key ASCII*/) {
        exit(1); // exit the program when escape key is pressed.
    }
    if (key == 'R' || key=='r'/* Escape key ASCII*/) {
        //exit(1); // exit the program when escape key is pressed.
    	//aswangle+=90;
    }
    
    else if (int(key) == 13)
    {  
	}
    
    glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

// implement your functionality here
	glutPostRedisplay();
// once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc(500.0 / FPS,Timer, 0);
}
void FoodTimer(int m) {//this function is to generate random bonus food

// implement your functionality here

	bonus_foodx=rand()%63+1;
	bonus_foody=rand()%63+1;
	Score=0;
	glutPostRedisplay();
// once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc(60000.0 / FPS, FoodTimer, 15);
}
void HurdleTimer(int m) {//this function to generate ramdom hurdles

// implement your functionality here

	hurdlex=rand()%60+1;
   	hurdley=rand()%60+1;
   	hurdlex1=rand()%60+1;
   	hurdley1=rand()%60+1;
   	hurdlex2=rand()%60+1;
   	hurdley2=rand()%60+1;
   	Score=0;
	glutPostRedisplay();
// once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc(56000.0 / FPS, HurdleTimer, 15);
}
void FaairaTimer(int m) {//this function is to generate random food

// implement your functionality here
	glutPostRedisplay();
	foodx=rand()%63+1;
	foody=rand()%63+1;
	foodx1=rand()%63+1;
	foody1=rand()%63+1;
	foodx2=rand()%63+1;
	foody2=rand()%63+1;
	foodx3=rand()%63+1;
	foody3=rand()%63+1;
	foodx4=rand()%63+1;
	foody4=rand()%63+1;
   	Score=0;
// once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc(56000.0 / FPS, FaairaTimer, 15);
}

/*
 * our gateway main function
 * */
 
int main(int argc, char*argv[]) {
    int width = 650, height = 650; // i have set my window size to be 800 x 600
    InitRandomizer(); // seed the random number generator...
    glutInit(&argc, argv); // initialize the graphics library...
     
         
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(50, 50); // set the initial position of our window
    glutInitWindowSize(width, height); // set the size of our window
    glutCreateWindow("PF's Snake Game"); // set the title of our game window
    SetCanvasSize(width, height); // set the number of pixels...

// Register your functions to the library,
// you are telling the library names of function to call for different tasks.
//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
    while(gameover==true)
    {
    	glutSpecialFunc(NonPrintableKeys);
    }	
    glutKeyboardFunc(PrintableKeys);
    
	
 // tell library which function to call for non-printable ASCII characters
     // tell library which function to call for printable ASCII characters
// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
    glutTimerFunc(5.0 / FPS, Timer,0 );
    glutTimerFunc(30.0 / FPS, FoodTimer,0 );
    glutTimerFunc(15.0 / FPS, FaairaTimer,0 );
    glutTimerFunc(15.0 / FPS, HurdleTimer,0 );
    

// now handle the control to library and it will call our registered functions when
// it deems necessary...
    glutMainLoop();
    return 1;
}
#endif /* Snake Game */

