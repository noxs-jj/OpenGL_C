/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:21:36 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/02 15:47:42 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[j] != '\0')
		j++;
	if (size <= (ft_strlen(dst)))
		return (size + ft_strlen(src));
	while (src[i] != '\0')
	{
		if (i + j < size - 1)
			dst[j + i] = src[i];
		else
			dst[j + i] = '\0';
		i++;
	}
	dst[j + i] = '\0';
	return (j + i);
}
