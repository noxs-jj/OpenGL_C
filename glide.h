/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glide.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:30:16 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/06/13 11:30:20 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLIDE_H
# define GLIDE_H

# include "libft/includes/libft.h"

# ifdef __LINUX__
#	include <GL/gl.h>		// Header File For The OpenGL32 Library
#	include <GL/glu.h>		// Header File For The GLu32 Library
#	include <GL/glut.h>		// Header File For The GLut Library
# endif

# ifdef __APPLE__
#	include <openGL/gl.h>
#	include <openGL/glu.h>
#	include <glut/glut.h>
# endif

# ifdef __WIN32__
#	include <GL/gl.h>
#	include <GL/glu.h>
#	include <windows.h>		// Header File for Windows
# endif

# define WINX	1024
# define WINY	768
# define STARTX	50
# define STARTY	50
# define TITLE	"OpenGL by NoXsNoNo"


void			keyboard(unsigned char touche, int x, int y);

void			_2d_triangle();
void			_2d_triforce();

void			_3d_triforce();

#endif

