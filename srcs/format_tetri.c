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

void	remove_beg_dot(char **tetri)
{
	int 		i;
	int 		j;
	int 		k;
	int		count;
	char		tetri_wo_dot[20];

	i = 0;
	while (tetri[i])
	{
		j = 0;
		k = 0;
		count = 0;
		while (tetri[i][j] == '.')
		{
			j++;
			count++;
		}
		while (tetri[i][j])
			tetri_wo_dot[k++] = tetri[i][j++];
		ft_strcpy(tetri[i], tetri_wo_dot);
		tetri[i][j - count] = '\0';
		i++;
	}
}

void	remove_newline(char **tetri)
{
	int		i;
	int		j;
	int		k;
	char		tetri_wo_newline[20];

	i = 0;
	while (tetri[i])
	{
		k = 0;
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] != '\n')
				tetri_wo_newline[k++] = tetri[i][j++];
			else 
				j++;
		}
		ft_strcpy(tetri[i], tetri_wo_newline);
		tetri[i][j - 4] = '\0';
		i++;
	}
}

void	hash_to_letter(char **tetri)
{
	int		i;
	char		c;
	char		*tmp;

	i = 0;
	while (tetri[i])
		printf("hashto:\n%s", tetri[i++]);
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
