/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:57:31 by fkante            #+#    #+#             */
/*   Updated: 2019/09/12 16:27:51 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE	1024
# define FALSE		0
# define TRUE		1
# define FAILURE	-1
# define SUCCESS	0

# define FD_LIMIT	4864
# define MAX_FD		1025

char	**read_file_tetri(char *av, int fd);
char	**read_buffer(const int fd, char **table_of_tetri);
char	**check_n_fill_table(char *buff, char **tab, int nb_tetri);

int		find_number_tetriminos(char *tetri_file);
int		isfour_hash(char **tetri);
int		istetri_valid(char *tetri);

char	**creation_square(int start);
void	setup_tetri_tab(char **table_of_tetri);
void	valid_tetri(char **tetri);
void	remove_newline(char **tetri);
void	remove_beg_dot(char **tetri);
void	remove_end_dot(char **tetri);
void	hash_to_letter(char **tetri);
void	reset_square(char **square);
int		fill_with_tetri(char **tetri, char **sol_square, int end);
uint8_t	dot_check(char position, char tetri);
uint8_t	valid_file(const int fd);

char	get_hash(char *str);
int		solve_square(char **tetri, char ***square, int size);
void	place_tetri(char **square, char *tetri, int col, int row);
void	remove_tetri(char **map, char *tetri, int col, int row);

void	free_tab(char **tab);
void	print_square(char **square, int size);
#endif
