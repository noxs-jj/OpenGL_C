/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 10:29:57 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/14 10:34:37 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	if (size > 0)
	{
		tmp = (char *)ft_memalloc(size + 1);
		if (tmp == NULL)
			return (NULL);
		i = 0;
		while (i <= size + 1)
		{
			tmp[i] = '\0';
			i++;
		}
		return (tmp);
	}
	else
		return (NULL);
}
