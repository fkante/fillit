/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:56:12 by fkante            #+#    #+#             */
/*   Updated: 2019/09/11 22:20:16 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint8_t	input_buf(char buf)
{
	if (buf == '.' || buf == '#'
			|| buf == '\n' || buf == '\0')
		return (SUCCESS);
	else
		return (FAILURE);
}

int		find_number_tetriminos(char *buf)
{
	int	i;
	int	count_tetri;
	int	count_dot;

	i = 0;
	count_tetri = 0;
	count_dot = 0;
	if (buf == NULL)
		return (0);
	while (buf[i] != '\0')
	{
		if (buf[i] == '.')
			count_dot++;
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
		{
			if (count_dot != 12)
				return (0);
			count_tetri++;
			count_dot = 0;
		}
		if (count_dot > 12)
			return (0);
		i++;
	}
	return (count_tetri);
}

char	**check_n_fill_table(char *buff, char **tab, int nb_of_tetri)
{
	int	i;
	int	buff_index;
	int	tetri_index;

	buff_index = 0;
	tetri_index = 0;
	while (tetri_index < nb_of_tetri)
	{
		if ((tab[tetri_index] = (char*)malloc(21 * sizeof(char))) != NULL)
		{
			i = 0;
			while (i < 20)
			{
				if (input_buf(buff[buff_index]) == SUCCESS)
					tab[tetri_index][i++] = buff[buff_index++];
				else
					return (NULL);
			}
		}
		tab[tetri_index++][i] = '\0';
		buff_index++;
	}
	tab[tetri_index] = NULL;
	return (tab);
}

char	**read_buffer(const int fd, char **tab)
{
	ssize_t	read_return;
	char	buff[BUFF_SIZE + 1];
	int		nb_tetri;

	tab = NULL;
	if ((read_return = read(fd, buff, BUFF_SIZE)) > 0 && read_return < 566)
	{
		buff[read_return] = '\0';
		if ((nb_tetri = find_number_tetriminos(buff)) != 0)
		{
			if ((tab = (char **)malloc(sizeof(char*) * (nb_tetri + 1))) == NULL)
				return (NULL);
			if ((tab = check_n_fill_table(buff, tab, nb_tetri)) == NULL)
				return (NULL);
			tab[nb_tetri] = NULL;
		}
	}
	return (tab);
}
