/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:54:45 by fkante            #+#    #+#             */
/*   Updated: 2019/07/31 11:34:04 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char		**table_of_tetri;
	int		square_size;
	char		**initial_square;

	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	table_of_tetri = NULL;
	if (fd == -1)
		return (-1);
	if((table_of_tetri = read_buffer(fd, table_of_tetri)) == NULL)
	{
		close(fd);
		ft_putstr_fd("error malloc", 1);
		return(0);
	}
	i = 0;
	while (table_of_tetri[i])
	{
		if (istetri_valid(table_of_tetri[i]) == FAILURE || isfour_hash(table_of_tetri) == FAILURE)
		{
			close(fd);
			ft_putstr_fd("error tetri not valid", 1);
			return(0);
		}
		i++;
	}
	i = i * 4;
	while (!(square_size = (int)ft_sqrt(i)))
		i++;
	initial_square = creation_square(square_size);
	remove_newline(table_of_tetri);
	remove_end_dot(table_of_tetri);
	remove_beg_dot(table_of_tetri);
	valid_tetri(table_of_tetri);
	hash_to_letter(table_of_tetri);
	solve_square(table_of_tetri, initial_square, square_size);
	free_tab(table_of_tetri);
	free_tab(initial_square);
	close(fd);
	return (0);
}
