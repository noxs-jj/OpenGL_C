/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_triforce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 13:50:16 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/06/13 13:50:20 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glide.h"

#define STARTX -0.5f
#define STARTY -0.5f
#define STARTZ 0

void	_3d_triforce()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_POLYGON);	// White polygon

		glColor3ub(255, 0 , 0);
		glVertex3d(STARTX, STARTY, STARTZ);

		glColor3ub(0, 255 , 0);
		glVertex3d(STARTX + 1, STARTY, STARTZ);

		glColor3ub(0, 0, 255);
		glVertex3d(STARTX + 1, STARTY + sqrt(3/2), STARTZ);

		glColor3ub(255, 144, 255);
		glVertex3d(STARTX + 0.5, STARTY + (sqrt(3/2) / 2), STARTZ + sqrt(3/2));

	glEnd();


	glFlush();
	glLoadIdentity();
	glutSwapBuffers();
}



// pyramide3d bas  triangle 4 cote

// 1p startx . starty . startz
// 2p startx + 1 . starty . startz
// 3p startx + 0.5 . (starty + sqrt(3/2)) . startz

// 4p startx + 0.5 . starty + (sqrt(3/2) / 2) . startz + sqrt(3/2)
