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

char	**creation_square(int start)
{
	int		height;
	int		length;
	char		**new_square;

	if(!(new_square = (char**)malloc(sizeof(char*) * start)))
		return (NULL);
	height = 0;
	while (height < start)
	{
		length = 0;
		new_square[height] = (char*)malloc(sizeof(char) * start);
		while (length < start)
		{
			new_square[height][length] = 0;
			length++;
		}
		height++;
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

