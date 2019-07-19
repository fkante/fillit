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

char	get_hash(char *str)
{
	while (*str == '.')
		str++;
	return (*str);
}

int		is_free_2(char **square, int max, int y, int x)
{
	int		count;

	count = 0;
	if (square[y][x] == 0)
	{
		square[y][x] = 1;
		count++;
	}
	if (y < max - 1 && square[y + 1][x] == 0)
		count += is_free_2(square, max, y + 1, x);
	if (x >= 1 && square[y][x - 1] == 0)
		count += is_free_2(square, max, y, x - 1);
	if (x < max - 1 && square[y][x + 1] == 0)
		count += is_free_2(square, max, y, x + 1);
	if (y >= 1 && square[y - 1][x] == 0)
		count += is_free_2(square, max, y - 1, x);
	return (count);
}

int		is_free(char **square, int max)
{
	int 	count;
	int	tmp;
	int	x;
	int 	y;

	count = 0;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (y >= 1 && !square[y - 1][x] && (tmp = is_free_2(square, max, y - 1, x)) >= 4)
				count += tmp;
			if (x >= 1 && !square[y][x - 1] && (tmp = is_free_2(square, max, y, x - 1)) >= 4)
				count += tmp;
			if (x < max - 1 && !square[y][x + 1] && (tmp = is_free_2(square, max, y, x + 1)) >= 4)
				count += tmp;
			if (y < max - 1 && !square[y + 1][x] && (tmp = is_free_2(square, max, y + 1, x)) >= 4)
				count += tmp;
			x++;
		}
		y++;
	}
	return (count);
}

void	remove_tetri(char **map, char *tetri, int col, int row)
{
	char		ch;
	int		i;

	ch = get_hash(tetri);
	printf("remove_tetri: %c\n", ch);
	printf("emplacement: %c\n", map[row][col]);
	i = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{

			if (i == 4)
				return ;
			if (map[row][col] == ch)
			{
				i++;
				map[row][col] = '.';
				printf("i: %d\t",i);
			}
			col++;
		}
		row++;
	}
}

void	place_tetri(char **square, char *tetri, int col, int row)
{
	size_t		i;
	int		init_col;

	init_col = col;
	i = 0;
	while (*tetri == '.')
		DO3(i++, tetri++, init_col--);
	while (*tetri != '\n')
	{
		if (i > 3)
		{
			i = 0;
			col = init_col;
			row++;
		}
		if (*tetri == '.')
		{
			i++;
			col++;
		}
		if (square[row][col] == 1 && *tetri != '.')
		{
			square[row][col] = *tetri;
			printf("square: %c\t, tetri: %c\n", square[row][col], *tetri);
			col++;
			i++;
		}
		tetri++;
	}
}

int	fill_with_tetri(char **tetri, char **sol_square, int x, int y, int end)
{
	if (!*tetri)
		return (1);
	while (y < end)
	{
		while (x < end)
		{
			if (is_free(sol_square, end) != 0)
			{
				while(sol_square[y][x] != 1)
				{
					x++;
				}
				place_tetri(sol_square, *tetri, x, y);
				if (fill_with_tetri(tetri + 1, sol_square, 0, 0, end) == 1)
					return (1);
				else
					remove_tetri(sol_square, *tetri, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
/*
int		fill_with_tetri(char **tetri, char **sol_square, int end)
{
	int 	x;
	int 	y;
	int	empty;

	x = 0;
	empty = is_free(sol_square, end);
	while (y < end)
	{
		x = 0;
		while (x < end)
		{
			printf("empty: %d\n", empty);
			if (empty != 0)
				place_tetri(sol_square, *tetri, x, y);
			if (fill_with_tetri(tetri + 1, sol_square, end) == 1)
				return (1);
			else
				remove_tetri(sol_square, *tetri, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
*/
int		solve_square(char **tetri, char **new_square, int square_size)
{
	while (fill_with_tetri(tetri, new_square, 0, 0, square_size) == 0)
	{
		square_size++;
		reset_square(new_square);
		new_square = creation_square(square_size);
	}
	print_square(new_square, square_size);
		reset_square(new_square);
	return (1);
}

