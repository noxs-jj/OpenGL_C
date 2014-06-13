/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:36:43 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/06/13 11:36:47 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glide.h"

void reshape(int x, int y)
{
	if (x < y)
		glViewport(0, (y - x) / 2, x, x);
	if (y < x)
		glViewport((x - y) / 2, 0, y, y);
}

int	main(int ac, char **av)
{
	glutInit(&ac, av);						// init glut
	glutInitDisplayMode(GLUT_RGB			// set color to RGB
						| GLUT_DOUBLE		// set double buffered windows
						| GLUT_DEPTH);		// Bit mask to select a window with a depth buffer.
	glutInitWindowSize(WINX, WINY);			// Size of windows
	glutInitWindowPosition(STARTX, STARTY);	// where the windos in create on Xserver/Desktop
	glutCreateWindow(TITLE);				// Create windows with title in param char *
	glClearColor(0, 0, 0, 0);				//set background/void color
	glPointSize(1.0);						//set point size
	glEnable(GL_DEPTH_TEST);

	//glutDisplayFunc(_2d_triangle);		// function print screen
	glutDisplayFunc(_2d_triforce);			// function print screen
	//glutDisplayFunc(_3d_triforce);			// function print screen
	
	glutKeyboardFunc(keyboard);				// function for keyboard event
	glutReshapeFunc(reshape); 				// resize, form save proportion
	glutMainLoop();							// program never return
	return (0);
}
