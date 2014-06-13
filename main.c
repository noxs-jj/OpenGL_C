#include "glide.h"

void	print_2d();
void	keyboard(unsigned char touche, int x, int y);

int	main(int ac, char **av)
{
	glutInit(&ac, av);					// init glut
	glutInitDisplayMode(GLUT_RGB		// set color to RGB
						| GLUT_DOUBLE	// set double buffered windows
						| GLUT_DEPTH);	// Bit mask to select a window with a depth buffer.
	glutInitWindowSize(WINX, WINY);		// Size of windows
	glutInitWindowPosition(STARTX, STARTY);	// where the windos in create on Xserver/Desktop
	glutCreateWindow(TITLE);			// Create windows with title in param char *
	glClearColor(0, 0, 0, 0);			//set background/void color
	glPointSize(1.0);					//set point size
	glEnable(GL_DEPTH_TEST);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	//glutDisplayFunc(2d_triangle);		// function print screen
	glutDisplayFunc(2d_triforce);		// function print screen


	glFlush();
	glLoadIdentity();
	glutSwapBuffers();
	glutKeyboardFunc(keyboard);			// function for keyboard event
	//glutReshapeFunc(reshape); // A TRAVAILLER
	glutMainLoop();						// program never return
	return (0);
}

void	keyboard(unsigned char touche, int x, int y)
{
	while (42)
	{
		if (touche == 'q')
			exit(0);
	}
}