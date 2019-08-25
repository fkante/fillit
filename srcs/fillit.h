/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:57:31 by fkante            #+#    #+#             */
/*   Updated: 2019/07/31 11:29:49 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 1024
# define FALSE		0
# define TRUE		1
# define FAILURE	-1
# define SUCCESS	0

# define FD_LIMIT	4864
# define MAX_FD 1024 + 1
# define RET_VALUE(ret)	ret > 0 ? 1 : ret

int		find_number_tetriminos(char *tetri_file);
char	**check_n_fill_table(char *buff, char **tab, int nb_tetri);
char	**read_file_tetri(char *av, int fd);
int		get_next_line(const int fd, char **line);
char	**read_buffer(const int fd, char **table_of_tetri);
int		check_height(char *tetri);
int		check_length(char *tetri);
int		istetri_valid(char *tetri);
char	**creation_square(int start);
int		solve_square(char **tetri, char **square, int size);
void	print_square(char **square, int size);
void	place_tetri(char **square, char *tetri, int col, int row);
void	remove_tetri(char **map, char *tetri, int col, int row);
void	hash_to_letter(char **tetri);
void	remove_beg_dot(char **tetri);
void	reset_square(char **square);
void	remove_newline(char **tetri);
int		fill_with_tetri(char **tetri, char **sol_square, int x, int y, int end);

#endif
