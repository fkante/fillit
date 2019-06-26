#include "fillit.h"

int	find_number_tetriminos(char *tetri_file)
{
	int	count_tetri;
	int	i;

	count_tetri = 0;
	i = 0;
	if (tetri_file == NULL)
		return (-1);
	while (tetri_file[i])
	{
		if (tetri_file[i] == '\n' 
				&& (tetri_file[i + 1] == '\n' || tetri_file[i + 1] == '\0'))
			count_tetri++;
		i++;
	}
	return (count_tetri);
}

char	**check_n_fill_table(char *buff, char **tab, int nb_of_tetri)
{
	int	i;
	int	buff_index;
	int	tetri_index;

	i = 0;
	buff_index = 0;
	tetri_index = 0;
	while (tetri_index < nb_of_tetri)
	{
		if(!(tab[tetri_index] = (char*)malloc(21*sizeof(char))))
			return (NULL);
		i = 0;
		while (i < 21)

		{
			if (buff[buff_index] == '.' || buff[buff_index] == '#'
					|| buff[buff_index] == '\n' || buff[buff_index] == '\0')
			tab[tetri_index][i++] = buff[buff_index++];
			else
			{
				ft_strdel(tab);
				return (NULL);
			}
		}
		tab[tetri_index][i] = '\0';
		tetri_index++;
	}
	tab[tetri_index] = NULL;
	return (tab);
}
char	**read_buffer(const int fd)
{
	ssize_t	read_return;
	char	buff[BUFF_SIZE + 1];
	char	**table_of_tetri;
	int	nb_of_tetri;

	table_of_tetri = NULL;
	while ((read_return = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_return] ='\0';
	}
	nb_of_tetri = find_number_tetriminos(buff);
	printf("nb of tetri = %d\n", nb_of_tetri);
	if (!(table_of_tetri = (char **)malloc(sizeof(char*) * nb_of_tetri + 1)))
		return (NULL);
	if(!(table_of_tetri = check_n_fill_table(buff, table_of_tetri, nb_of_tetri)))
		return (NULL);
	return (table_of_tetri);
}
