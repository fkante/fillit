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

int		isfour_hash(char **tetri)
{
	int i;
	int j;
	int count_hash;

	i = 0;
	while (tetri[i])
	{
		j = 0;
		count_hash = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
				count_hash++;	
			if (count_hash > 4)
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (1);
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
	}
	if (tetri_hash == 6 || tetri_hash == 8)
		return (1);
	else
		return (FAILURE);
}

