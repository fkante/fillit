/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:54:45 by fkante            #+#    #+#             */
/*   Updated: 2019/09/13 15:16:31 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		launch(char ***table_of_tetri, int fd)
{
	int		i;

	if ((*table_of_tetri = read_buffer(fd, *table_of_tetri)) == NULL)
		return (FAILURE);
	i = 0;
	while ((*table_of_tetri)[i] != NULL)
	{
		if (istetri_valid((*table_of_tetri)[i]) == FAILURE
				|| isfour_hash(*table_of_tetri) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int		main(int ac, char **av)
{
	char	**table_of_tetri;
	int		fd;
	int		ret;

	ret = FAILURE;
	if (ac != 2 && !(ret = SUCCESS))
		ft_putendl("usage: ./fillit path/file");
	if (ac == 2 && (fd = open(av[1], O_RDONLY)) != FAILURE)
	{
		table_of_tetri = NULL;
		if ((ret = launch(&table_of_tetri, fd)) == SUCCESS)
			setup_tetri_tab(table_of_tetri);
		free_tab(table_of_tetri);
		close(fd);
	}
	if (ret == FAILURE)
		ft_putendl("error");
	return (ret);
}
