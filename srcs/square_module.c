/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_module.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:56:50 by fkante            #+#    #+#             */
/*   Updated: 2019/09/11 16:03:57 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**creation_square(int square_size)
{
	int		height;
	int		length;
	char	**new_square;

	new_square = NULL;
	if ((new_square = ft_memalloc(sizeof(char*) * (square_size + 1))) != NULL)
	{
		height = 0;
		while (height < square_size)
		{
			length = 0;
			if ((new_square[height] = ft_strnew(square_size + 10)) == NULL)
				return (NULL);
			while (length < square_size)
			{
				new_square[height][length] = '.';
				length++;
			}
			height++;
		}
		new_square[height] = NULL;
	}
	return (new_square);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
