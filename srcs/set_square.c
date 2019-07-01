/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:25:03 by fkante            #+#    #+#             */
/*   Updated: 2019/07/01 15:44:04 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**creation_square(char **tetri)
{
	int		l_total;
	int		h_total;
	int		i;
	char	**new_square;

	l_total = 0;
	h_total = 0;
	i = 0;
	while (tetri[i])
		l_total += check_length(tetri[i++]);
	i = 0;
	while (tetri[i])
		h_total += check_height(tetri[i++]);
	printf("l: %d\th: %d\n", l_total, h_total);
	if(!(new_square = (char**)malloc(sizeof(char*) * (h_total)+1)))
		return (NULL);
	return (new_square);
}

int		is_free(char **shape, int x, int y)
{
	if (x >= 0 && x < 5 && y >= 0 && y < 5 && shape[y][x] == '#')
		return (1);
	else
		return (0);
}

char	*solve_square(char **tetri, char *square, int x, int y)
{
	char	c;

	c = 'A';
	if (is_free(square, x, y) == 1)
	{
	}
}


int		check_each_tetriminos(char **tab, char **tetri, int x, int y, int end)
{
	if (end == 4)
		return (1);
	if (is_free(tab, x, y) == 1)
	{
		tetri[y][x] = '#';
		end++;
		if (check_each_tetriminos(tab, tetri, x + 1, y, end) == 1)
			return (1);
		if (check_each_tetriminos(tab, tetri, x, y + 1, end) == 1)
			return (1);
	}
	return (0);
}
