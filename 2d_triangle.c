/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:29:20 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/06/13 11:29:29 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glide.h"

void	2d_triangle()
{
	glBegin(GL_POLYGON);		// start of form
		glColor3ub(255, 0 , 0);	// chose color of point on space
		glVertex2d(-0.5, -0.5);	// set point in space in 2D
		glColor3ub(0, 255, 0);
		glVertex2d(0, 0.5);		// x, y
		glColor3ub(0, 0, 255);
		glVertex2d(0.5, -0.5);	// x, y
	glEnd();
}
