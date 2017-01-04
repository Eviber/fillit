/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:01:42 by btollet           #+#    #+#             */
/*   Updated: 2016/12/13 19:21:00 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_grid(int size)
{
	char	*result;
	size_t	len;
	size_t	index;

	len = (size + 1) * size;
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	index = 0;
	result[len] = '\0';
	while (index < len)
		result[index++] = '.';
	index = size;
	while (index < len)
	{
		result[index] = '\n';
		index += size + 1;
	}
	return (result);
}

int		size_min(char **pieces)
{
	int		nb;
	int		size;

	size = 2;
	nb = 0;
	while (pieces[nb] != 0)
		nb++;
	while (size * size < nb * 4)
		size++;
	return (size);
}
