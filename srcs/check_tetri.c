/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:24:50 by fkante            #+#    #+#             */
/*   Updated: 2019/06/27 11:50:31 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		istetri(char **shape, int x, int y)
{
	if (x >= 0 && x < 5 && y >= 0 && y < 5 && shape[y][x] == '#')
		return (1);
	else
		return (0);
}
// trying to identify the tetriminos by moving from the first # going right or
// down, the problem is that this doesnt work with tetri going up right or
// down left;
int		check_each_tetriminos(char **tab, char **tetri, int x, int y, int end)
{
	if (end == 4)
		return (1);
	if (istetri(tab, x, y) == 1)
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

// identify tetriminos by scanning the square;
int		parsing_tetri(char **tab, int **tetri,int x, int y, int length)
{

	if (istetri(tab, x, y) == 1)
	{
		tetri[y][x] = 1;
		if (parsing_tetri(tab, tetri, x + 1, y, length) == 1)
			return (1);
		if (parsing_tetri(tab, tetri, x, y + 1, length) == 1)
			return (1);
	}
	return (0);
}

int		store_one_tetri(char **tab)
{
	int		**one_tetri;
	int		length;
	int		line;
	int		col;

	line = 0;
	col = 0;
	length = 0;
	while (tab[line] != '\0')
	{
		while (tab[line][col] != '\n')
		{
			//	printf("col:%d\tline:%d\n", col, ligne);
			//	printf("%c", tab[line][col]);
			if (tab[line][col] == '#')
				length++;
			col++;
		}
		col = 0;
		line++;
	}
	printf("length: %d\tcol:%d\tline:%d\n", length, col, line);
	if (!(one_tetri = (int **)malloc(sizeof(int)*1)))
		return (0);
	//	parsing_tetri(tab, one_tetri, 0, 0, length);
	return (1);
}

int		check_height(char *tetri)
{
	int		height;
	int		i;

	height = 0;
	i = 0;
	while (i < 21)
	{
		if (tetri[i] == '#')
		{
			height++;
			while (tetri[i] != '\n')
				i++;
		}
		i++;
	}
	return (height);
}

int		check_length(char	*tetri)
{
	int length;
	int i;
}
