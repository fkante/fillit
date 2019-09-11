/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:32:37 by fkante            #+#    #+#             */
/*   Updated: 2019/09/11 22:20:21 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	get_hash(char *str)
{
	while (*str == '.')
		str++;
	return (*str);
}

void	setup_tetri_tab(char **table_of_tetri)
{
	char	**initial_square;
	int		square_size;
	int		i;

	i = 0;
	while (table_of_tetri[i] != NULL)
		i++;
	i = i * 4;
	while (!(square_size = (int)ft_sqrt(i)))
		i++;
	initial_square = creation_square(square_size);
	remove_newline(table_of_tetri);
	remove_end_dot(table_of_tetri);
	remove_beg_dot(table_of_tetri);
	valid_tetri(table_of_tetri);
	hash_to_letter(table_of_tetri);
	solve_square(table_of_tetri, &initial_square, square_size);
	free_tab(initial_square);
}

int		solve_square(char **tetri, char ***new_square, int square_size)
{
	while (fill_with_tetri(tetri, *new_square, square_size) == FALSE)
	{
		free_tab(*new_square);
		square_size++;
		*new_square = creation_square(square_size);
	}
	print_square(*new_square, square_size);
	return (TRUE);
}
