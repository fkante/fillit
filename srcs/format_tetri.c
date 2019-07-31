/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:55:48 by fkante            #+#    #+#             */
/*   Updated: 2019/07/31 10:55:54 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
** I have a issue on linux with the newline character, i had to remove it
** to so i can increment on place tetris
*/

void	remove_newline(char **tetri)
{
	int		i;
	int		j;
	int		k;
	char	tetri_wo_newline[20];

	i = 0;
	while (tetri[i])
	{
		j = 0;
		k = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '\n')
				++j;
			tetri_wo_newline[k] = tetri[i][j];
			++k;
			++j;
		}
		ft_strcpy(tetri[i], tetri_wo_newline);
		i++;
	}
}

void	hash_to_letter(char **tetri)
{
	int		i;
	char		c;
	char		*tmp;

	i = 0;
	c = 'A';
	while (tetri[i])
	{
		tmp = tetri[i];
		while (*tmp)
		{
			if (*tmp == '#')
				*tmp = c;
			tmp++;
		}
		c++;
		i++;
	}
}
