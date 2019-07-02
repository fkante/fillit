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
	if (table_of_tetri == NULL)
	{
		close(fd);
		ft_putstr_fd("error", 1);
		return(0);
	}
	while (table_of_tetri[i])
	{
		if (istetri_valid(table_of_tetri[i]) == 0)
		{
			close(fd);
			ft_putstr_fd("error", 1);
			return(0);
		}
		i++;
	}
	//printf("all try ok\n");
	//printf("%s", table_of_tetri[ft_atoi(av[2])]);
	solve_square(table_of_tetri, creation_square(table_of_tetri), 0, 0);
	close(fd);
	return (0);
}
