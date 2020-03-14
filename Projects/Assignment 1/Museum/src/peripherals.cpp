// ============================================================================
// 	Author:       Jonathan Edwards
//
// 	Description:  ....
// ============================================================================


// Standard libaries
#include <stdio.h>

// OpenGL libaries
#include <GL/glut.h>

// Personal libaries
#include "peripherals.h"
#include "display.h"


// ASCII Keys
#define QUIT    'q'
#define ESC     0x1B



/** ------------------------------------------------------------------------------
// 						Perform background processing tasks
//  @param delay - Delay in milli seconds
//  --------------------------------------------------------------------------- */
static void idle(int delay)
{
	glutTimerFunc(delay, idle, delay);
}


// ----------------------------------------------------------------------------
//							Special key event callback 
// ----------------------------------------------------------------------------
// void special(int key, int x, int y)
// {
//     if (key == GLUT_KEY_END) exit(EXIT_SUCCESS);

//     glutTimerFunc(TIMER_DELAY, idle, TIMER_DELAY);
// }

float angle=0;

void special(int key, int x, int y)
{
	if(key == GLUT_KEY_LEFT) angle -= 0.1;  //Change direction
	else if(key == GLUT_KEY_RIGHT) angle += 0.1;
	else if(key == GLUT_KEY_DOWN)
	{  //Move backward
        moveBack(angle);
	}
	else if(key == GLUT_KEY_UP)
	{ //Move forward
		// position the person it from the centre
        moveForward(angle);
	}
	// printf("eye z:   %f\n", eye_z);

    lookRotation(angle);
	
    glutTimerFunc(TIMER_DELAY, idle, TIMER_DELAY);
}


// ----------------------------------------------------------------------------
//							ASCII key event callback 
// ----------------------------------------------------------------------------
void keyEvents(unsigned char key, int x, int y)
{
    if (key == QUIT) exit(EXIT_SUCCESS);
	else if (key == ESC) exit(EXIT_SUCCESS);

    glutTimerFunc(TIMER_DELAY, idle, TIMER_DELAY);  
}
