#include "fillit.h"

int		find_number_tetriminos(char *tetri_file);
char	**check_n_fill_table(char *buff, char **tab, int nb_tetri);
char	**read_file_tetri(char *av, int fd);
int		store_one_tetri(char **tab);

int		main(int ac, char **av)
{
	int		fd;
	char	**table_of_tetri;
	int		i;

	i = 0;
	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	table_of_tetri = read_buffer(fd);
	if(table_of_tetri == NULL)
	{
		close(fd);
		ft_putstr_fd("error", 1);
		return(0);
	}
	i = istetri_valid(table_of_tetri[ft_atoi(av[2])]);
	printf("edges %d\n", i);
	printf("%s", table_of_tetri[ft_atoi(av[2])]);
	creation_square(table_of_tetri);
	close(fd);
	return (0);
}
