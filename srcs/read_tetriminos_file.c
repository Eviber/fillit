/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetriminos_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:42:45 by ygaude            #+#    #+#             */
/*   Updated: 2016/12/13 19:22:29 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strappend(char *s1, char *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

char	*read_file(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];
	char	*file_content;

	file_content = ft_strnew(1);
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		if (file_content)
			free(file_content);
		err("error");
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		file_content = ft_strappend(file_content, buf);
	}
	close(fd);
	return (file_content);
}
