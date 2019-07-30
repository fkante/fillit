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

int	is_free(char **square, char *tetri, int col, int row)
{
	size_t	i;
	int	init_col;

	init_col = col;
	i = 0;
	while (*tetri == '.')
	{
		i++;
		tetri++;
		init_col--;
	}
	if (init_col < 0)
		return (0);
	while (*tetri != '\0')
	{
		printf("i:%ld\n", i);
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
		if (square[row][col] != '.' && *tetri != '.' && square[row][col])
			return (0);
		if (square[row][col] == 0 && *tetri != '.')
			return (0);
		if (square[row][col] == '.' && *tetri != '.')
		{
			i++;
			col++;
		}
//		printf("init_col: %d\tcol: %d\t, tetri: %c\t, col: %c\n", init_col, col, *tetri, square[row][col - 1]);
		tetri++;
	}
	printf("ok\n");
	return (1);
}

void	remove_tetri(char **square, char *tetri, int col, int row)
{
	char		ch;
	int		i;
		i = 0;
		while (square[i])
			printf("%s\n", square[i++]);
	ch = get_hash(tetri);
	i = 0;
	while (square[row])
	{
		col = 0;
		while (square[row][col])
		{

			if (i == 4)
				return ;
			//printf("emplacement: %c\n", square[row][col]);
			if (square[row][col] == ch)
			{
				i++;
				square[row][col] = '.';
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
	{
		i++;
		tetri++;
		init_col--;
	}
	printf("init_col: %d\tcol: %d\n", init_col, col);
	while (*tetri != '\0')
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
			int i = 0;
			while (sol_square[i])
				printf("%s\n", sol_square[i++]);
			if (is_free(sol_square, *tetri, x, y) == 1)
			{
			//	while(tetri[y][x] == '.')
			//	{
			//		x++;
			//	}
				printf("ok\n");
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

