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
# include <openGL/gl.h>		// Header File For The OpenGL32 Library
# include <openGL/glu.h>	// Header File For The GLu32 Library
# include <glut/glut.h>		// Header File For The GLut Library

# define WINX	1024
# define WINY	768
# define STARTX	200
# define STARTY	50
# define TITLE	"OpenGL by NoXsNoNo"

void			keyboard(unsigned char touche, int x, int y);

void			_2d_triangle();
void			_2d_triforce();


#endif
