/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 11:29:34 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/06/13 11:29:39 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glide.h"

void	keyboard(unsigned char touche, int x, int y)
{
	(void)x;
	(void)y;
	while (42)
	{
		if (touche == 'q')
			exit(0);
	}
}
