/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:50:53 by ygaude            #+#    #+#             */
/*   Updated: 2017/01/04 17:41:06 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	err(char *msg)
{
	ft_putendl(msg);
	exit(1);
}

void	freeall(char *file, char **pieces, int i)
{
	if (i == -1)
		while (pieces && pieces[++i])
			;
	while (i)
		ft_memdel((void *)&pieces[i--]);
	ft_memdel((void *)&file);
	ft_memdel((void **)pieces);
	err("error");
}
