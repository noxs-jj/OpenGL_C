/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_triforce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:28:58 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/06/13 11:29:09 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glide.h"

// ##################################
// #								#
// #			-x <- -> +x			#
// #	+y							#
// #	|			 				#
// #				 0				#
// #	|							#
// #	-y							#
// #								#
// ##################################

void	_2d_triforce()
{
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
}
