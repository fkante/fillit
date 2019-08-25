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
	int tetri_hash;

	i = 0;
	tetri_hash = 0;
	while (i < 20)
	{
		if (tetri[i] == '#')
		{
			if ((i + 1) < 20 && tetri[i + 1] == '#')
				tetri_hash++;       
			if ((i - 1) >= 0 && tetri[i - 1] == '#')
				tetri_hash++;       
			if ((i + 5) < 20 && tetri[i + 5] == '#')
				tetri_hash++;       
			if ((i - 5) >= 0 && tetri[i - 5] == '#')
				tetri_hash++;
		}
		i++;
		if (tetri_hash > 8)
			return (FAILURE);
	}
	if (tetri_hash == 6 || tetri_hash == 8)
		return (1);
	else
		return (FAILURE);
}
