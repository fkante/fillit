/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_module.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:39:06 by fkante            #+#    #+#             */
/*   Updated: 2019/09/11 21:58:25 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint8_t	dot_check(char position, char tetri)
{
	if (position != '.' && tetri != '.')
		return (FALSE);
	if (position == 0 && tetri != '.')
		return (FALSE);
	return (TRUE);
}

int		is_free(char **square, char *tetri, int col, int row)
{
	size_t	i;
	int		init_col;
	int		count;

	init_col = col;
	i = 0;
	count = 0;
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
		if (square[row] == NULL)
			return (0);
		if (dot_check(square[row][col], *tetri) == FALSE)
			return (0);
		if (square[row][col] == '.' && *tetri != '.')
		{
			i++;
			col++;
			count++;
		}
		tetri++;
		if (count == 4)
			break ;
	}
	return (1);
}

void	remove_tetri(char **square, char *tetri, int col, int row)
{
	int		i;
	char	ch;

	i = 0;
	ch = get_hash(tetri);
	i = 0;
	while (square[row])
	{
		col = 0;
		while (square[row][col])
		{
			if (i == 4)
				return ;
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
	size_t	i;
	int		init_col;
	int		count;

	init_col = col;
	i = 0;
	count = 0;
	while (*tetri == '.')
	{
		i++;
		tetri++;
		init_col--;
	}
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
		if (square[row][col] == '.' && *tetri != '.')
		{
			square[row][col] = *tetri;
			col++;
			i++;
			count++;
		}
		if (count == 4)
			break ;
		tetri++;
	}
}

int		fill_with_tetri(char **tetri, char **sol_square, int end)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!tetri || !*tetri)
		return (TRUE);
	while (y < end)
	{
		while (x < end)
		{
			if (is_free(sol_square, *tetri, x, y) == TRUE)
			{
				place_tetri(sol_square, *tetri, x, y);
				if (fill_with_tetri(tetri + 1, sol_square, end) == TRUE)
					return (TRUE);
				else
					remove_tetri(sol_square, *tetri, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (FALSE);
}
