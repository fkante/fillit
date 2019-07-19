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
# define DOT(a) (a == '.')
# define DO2(a, b) if(1){a; b;}
# define DO3(a, b, c) if(1){a; b; c;}

int	find_number_tetriminos(char *tetri_file);
char	**check_n_fill_table(char *buff, char **tab, int nb_tetri);
char	**read_file_tetri(char *av, int fd);
int	get_next_line(const int fd, char **line);
char	**read_buffer(const int fd);
int	check_height(char *tetri);
int	check_length(char *tetri);
int	istetri_valid(char *tetri);
char	**creation_square(int start);
int	solve_square(char **tetri, char **square, int size);
void	print_square(char **square, int size);
void	place_tetri(char **square, char *tetri, int col, int row);
void	remove_tetri(char **map, char *tetri, int col, int row);
void	hash_to_letter(char **tetri);
void	reset_square(char **square);
void	remove_newline(char **tetri);
int	fill_with_tetri(char **tetri, char **sol_square, int x, int y, int end);

#endif
