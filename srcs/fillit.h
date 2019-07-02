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

int		find_number_tetriminos(char *tetri_file);
char	**check_n_fill_table(char *buff, char **tab, int nb_tetri);
char	**read_file_tetri(char *av, int fd);
int		get_next_line(const int fd, char **line);
char	**read_buffer(const int fd);
int		check_height(char *tetri);
int		check_length(char *tetri);
int		istetri_valid(char *tetri);
char	**creation_square(char **tetri);
int		solve_square(char **tetri, char **square, int x, int y);
void	print_square(char **square);

#endif
