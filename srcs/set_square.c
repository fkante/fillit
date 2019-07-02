/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:25:03 by fkante            #+#    #+#             */
/*   Updated: 2019/07/02 15:44:05 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	get_char_tetri(int y)
{
	char		c;

	c = 'A' + y;
	return (c);
}

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
	if(!(new_square = (char**)malloc(sizeof(char*) * h_total + 1)))
		return (NULL);
	i = 0;
	while (i < h_total)
	{
		new_square[i] = (char*)malloc(sizeof(char) * l_total + 1);
		i++;
	}
	return (new_square);
}

int		is_free(char **shape, int x, int y)
{
	if (x >= 0 && x < 5 && y >= 0 && y < 5 && shape[y][x] == '#')
		return (1);
	else
		return (0);
}

int		fill_with_tetri(char **tetri, char **sol_square, int x, int y, int end)
{
	if (end == 4)
		return (1);
	if (is_free(tetri, x, y) == 1)
	{
		printf("y:%d\n", y);
		sol_square[y][x] = get_char_tetri(y);
		end++;
		if (fill_with_tetri(tetri, sol_square, x + 1, y, end) == 1)
			return (1);
		if (fill_with_tetri(tetri, sol_square, x + 5, y, end) == 1)
			return (1);
	}
	return (0);
}

int		solve_square(char **tetri, char **new_square, int x, int y)
{
	fill_with_tetri(tetri, new_square, x, y, 0);
	print_square(new_square);
	return (1);
}

