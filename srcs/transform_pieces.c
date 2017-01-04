/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_pieces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:01:58 by btollet           #+#    #+#             */
/*   Updated: 2016/12/11 15:50:22 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*replace_letter(char *piece, int letter)
{
	int		i;

	i = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
			piece[i] = letter;
		else if (piece[i] == '.')
			piece[i] = ' ';
		i++;
	}
	return (piece);
}

int		is_empty(char *square, int index, int actual)
{
	int save;

	save = index;
	if (square[index] == '\n' && actual == 5)
		return (is_empty(square, save, 1));
	while (index - actual >= 0 && ((actual == 1 && square[index - 1] != '\n')
		|| actual == 5))
		index -= actual;
	while ((actual == 1 && square[index] != '\n' && square[index] != '\0')
		|| (actual == 5 && index < 20))
	{
		if (square[index] == '#')
		{
			if (actual == 5)
				return (is_empty(square, save, 1));
			return (1);
		}
		index += actual;
	}
	return (0);
}
