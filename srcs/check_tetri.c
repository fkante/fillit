/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:24:50 by fkante            #+#    #+#             */
/*   Updated: 2019/07/01 15:44:14 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		check_length(char *tetri)
{
	int length;
	int i;
	int newline;

	length = 0;
	i = 0;
	newline = 0;
	while (i < 4)
	{
		if (tetri[i] == '#' || tetri[i + 5] == '#' || tetri[i + 10] == '#'
				|| tetri[i + 15] == '#')
		{
			length++;
			if (newline > 0)
				return (0);
		}
		else if (length > 0)
			newline++;
		i++;
	}
	return (length);
}

int		istetri_valid(char *tetri)
{
	int i;
	int same_edge;

	i = 0;
	same_edge = 0;
	while (i < 21)
	{
		if (tetri[i] == '#')
				if (tetri[i + 1] == '#' || tetri[i - 1] == '#'
						|| tetri[i + 5] == '#' || tetri[i - 5] == '#')
			same_edge++;
		if (same_edge == 4)
			return (1);
		i++;
	}
	return (0);
}
