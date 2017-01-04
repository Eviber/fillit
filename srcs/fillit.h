/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:00:30 by btollet           #+#    #+#             */
/*   Updated: 2016/12/13 19:17:41 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define BUFF_SIZE 42

void	err(char *msg);
void	freeall(char *file, char **pieces, int i);
size_t	file_len(char *file);
char	*read_file(char *file);
int		check_line(char *line);
int		check_square(char *square);
int		check_file(char *file);
char	**get_pieces(char *file);
char	*get_piece(char *square);
int		check_pieces(char *square);
int		check_nb_of_dieze(char *square);
char	*best_position(char *result, char **pieces, int i, int size);
char	*place_pieces(char *result, char *piece, int index_result, int size);
char	*create_grid(int size);
char	*replace_letter(char *piece, int letter);
int		is_empty(char *square, int index, int actual);
char	*solve(char **pieces);
char	*remove_piece(char *result, char c);
int		can_be_placed(char *result, int index_result, char *piece, int size);
int		size_min(char **pieces);

#endif
