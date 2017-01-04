/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:00:46 by btollet           #+#    #+#             */
/*   Updated: 2016/12/11 17:17:55 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*file_content;
	char	*res;

	if (argc == 2)
	{
		file_content = read_file(argv[1]);
		res = solve(get_pieces(file_content));
		if (res)
			ft_putstr(res);
		ft_memdel((void *)&res);
	}
	else
		err("usage: ./fillit tetriminos_file");
	return (0);
}
