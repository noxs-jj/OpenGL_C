#include "glide.h"

void	print_2d();
void	keyboard(unsigned char touche, int x, int y);

int	main(int ac, char **av)
{
	glutInit(&ac, av); // init glut
	glutInitDisplayMode(GLUT_RGB // set color to RGB
						| GLUT_DOUBLE // set double buffered windows
						| GLUT_DEPTH); // Bit mask to select a window with a depth buffer.
	glutInitWindowSize(WINX, WINY); // Size of windows
	glutInitWindowPosition(STARTX, STARTY); // where the windos in create on Xserver/Desktop
	glutCreateWindow(TITLE); // Create windows with title in param char *

	glClearColor(0, 0, 0, 0); //set background/void color
	glPointSize(1.0); //set point size
	glEnable(GL_DEPTH_TEST);

	//glutDisplayFunc(print_2d); // function print screen
	glutDisplayFunc(triforce_2d); // function print screen
	glutKeyboardFunc(keyboard); // function for keyboard event
	//glutReshapeFunc(reshape); // resize windows

	glutMainLoop(); // program never return
	return (0);
}

void	print_2d()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_POLYGON);		// start of form
		glColor3ub(255, 0 , 0);	// chose color of point on space
		glVertex2d(-0.5, -0.5);	// set point in space in 2D
		glColor3ub(0, 255, 0);
		glVertex2d(0, 0.5); 	// x, y
		glColor3ub(0, 0, 255);
		glVertex2d(0.5, -0.5);	// x, y
	glEnd(); // fin du dessin

	glFlush(); // force printing
	glLoadIdentity();

	glutSwapBuffers();
}

void	triforce_2d()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_POLYGON);	// White polygon
		glColor3ub(255, 255 , 255);
		glVertex2d((0 -0.5) / 2, (0.5 - 0.5) / 2);
		glColor3ub(255, 255, 255); 
		glVertex2d(0.5 / 2, 0 / 2);
		glColor3ub(255, 255, 255);
		glVertex2d(0, -0.5);
	glEnd();
	glBegin(GL_POLYGON);	// colored polygon
		glColor3ub(255, 0 , 0);
		glVertex2d(-0.5, -0.5);
		glColor3ub(0, 255, 0);
		glVertex2d(0, 0.5);
		glColor3ub(0, 0, 255);
		glVertex2d(0.5, -0.5);
	glEnd();
	glFlush();
	glLoadIdentity();
	glutSwapBuffers();
}

void	keyboard(unsigned char touche, int x, int y)
{
	while (42)
	{
		if (touche == 'q')
			exit(0);
	}
}