/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:41:32 by ygaude            #+#    #+#             */
/*   Updated: 2017/01/04 16:54:03 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_line(char *line)
{
	int		nb_of_char;
	int		i;

	i = 0;
	nb_of_char = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '#' && line[i] != '.')
			return (0);
		nb_of_char++;
		i++;
	}
	return (nb_of_char);
}

int		check_square(char *square)
{
	int		nb_of_line;
	int		i;

	i = 0;
	nb_of_line = 0;
	while (*square != '\n' && *square)
	{
		if (check_line(square) != 4)
			return (-1);
		nb_of_line++;
		square += 5;
	}
	return (nb_of_line);
}

int		check_file(char *file)
{
	int		nb_of_square;
	char	*tmp;

	tmp = file;
	nb_of_square = 0;
	if ((file[ft_strlen(file) - 1] == '\n' && file[ft_strlen(file) - 2] == '\n')
		|| file[0] == '\0' || file[ft_strlen(file) - 1] != '\n')
	{
		ft_memdel((void *)&tmp);
		err("error");
	}
	while (*file != '\0')
	{
		if (ft_strlen(file) == 20 && check_square(file) == 4)
			return (nb_of_square + 1);
		if (check_square(file) != 4)
		{
			ft_memdel((void *)&tmp);
			err("error");
		}
		nb_of_square++;
		file += 21;
	}
	return (nb_of_square);
}
