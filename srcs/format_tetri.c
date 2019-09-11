/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:55:48 by fkante            #+#    #+#             */
/*   Updated: 2019/09/11 22:16:33 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	valid_tetri(char **tetri)
{
	while (tetri && *tetri != NULL)
	{
		if (ft_strcmp(*tetri, "##.##") == 0)
			ft_strcpy(*tetri, ".##.##");
		else if (ft_strcmp(*tetri, "#...#..##") == 0)
			ft_strcpy(*tetri, ".#...#..##");
		else if (ft_strcmp(*tetri, "#..##..#") == 0)
			ft_strcpy(*tetri, ".#..##..#");
		else if (ft_strcmp(*tetri, "#.###") == 0)
			ft_strcpy(*tetri, "..#.###");
		else if (ft_strcmp(*tetri, "#..###") == 0)
			ft_strcpy(*tetri, ".#..###");
		else if (ft_strcmp(*tetri, "#..##...#") == 0)
			ft_strcpy(*tetri, ".#..##...#");
		tetri++;
	}
}

void	remove_beg_dot(char **tetri)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	tetri_wo_dot[20];

	i = 0;
	ft_bzero(tetri_wo_dot, 20);
	while (tetri && tetri[i])
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

void	remove_end_dot(char **tetri)
{
	int		i;
	int		j;
	int		count;
	char	tetri_wo_dot[20];

	i = 0;
	ft_bzero(tetri_wo_dot, 20);
	while (tetri && tetri[i])
	{
		j = 0;
		while (tetri[i][j] != '\0' && tetri[i][j + 1] != '\0')
			j++;
		while (j != 0 && tetri[i][j] == '.')
			j--;
		count = j;
		j = 0;
		while (tetri[i][j] && j <= count)
		{
			tetri_wo_dot[j] = tetri[i][j];
			j++;
		}
		tetri_wo_dot[j] = '\0';
		ft_strcpy(tetri[i], tetri_wo_dot);
		i++;
	}
}

void	remove_newline(char **tetri)
{
	int		i;
	int		j;
	int		k;
	char	tetri_wo_newline[20];

	i = 0;
	ft_bzero(tetri_wo_newline, 20);
	while (tetri && tetri[i])
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
	char	c;
	char	*tmp;

	i = 0;
	c = 'A';
	while (tetri && tetri[i])
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
