/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:01:10 by btollet           #+#    #+#             */
/*   Updated: 2017/01/04 16:54:34 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_pieces(char *file)
{
	char	**pieces;
	int		i;
	int		len;

	len = check_file(file);
	i = -1;
	if ((pieces = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
	{
		ft_memdel((void *)&file);
		err("error");
	}
	while (++i < len)
	{
		pieces[i] = get_piece(ft_strsub(file, i * 21, 21));
		if (!pieces[i])
			freeall(file, pieces, i);
		pieces[i] = replace_letter(pieces[i], 'A' + i);
	}
	pieces[i] = NULL;
	ft_memdel((void *)&file);
	return (pieces);
}

char	*get_piece(char *square)
{
	char	*pieces;
	int		i;
	int		j;
	int		dieze;

	dieze = 0;
	j = -1;
	pieces = ft_strnew(9);
	i = 0;
	while (square[++j])
		if (is_empty(square, j, 5))
		{
			if (square[j] == '#')
				dieze++;
			pieces[i++] = square[j];
		}
	pieces[i] = '\0';
	i = check_pieces(square);
	if (!(i == 6 || i == 8) || dieze != 4)
		ft_memdel((void *)&pieces);
	return (pieces);
}

int		check_pieces(char *square)
{
	int		i;
	int		len;
	int		nb_connect;

	i = 0;
	nb_connect = 0;
	len = (int)ft_strlen(square);
	while (square[i])
	{
		if (square[i] == '#')
		{
			if (i + 1 <= len && square[i + 1] == '#')
				nb_connect++;
			if (i + 5 <= len && square[i + 5] == '#')
				nb_connect++;
			if (i - 1 >= 0 && square[i - 1] == '#')
				nb_connect++;
			if (i - 5 >= 0 && square[i - 5] == '#')
				nb_connect++;
		}
		i++;
	}
	return (nb_connect);
}
