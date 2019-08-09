/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_module.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:56:50 by fkante            #+#    #+#             */
/*   Updated: 2019/07/31 10:57:00 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_square(char **square)
{
	size_t	i;

	i = 0;
	while (square[i])
	{
		free(square[i]);
		i++;
	}
	free(square);
}

char	**creation_square(int square_size)
{
	int		height;
	int		length;
	char		**new_square;

	if(!(new_square = (char**)malloc(sizeof(char*) * square_size)))
		return (NULL);
	height = 0;
	while (height < square_size)
	{
		length = 0;
		new_square[height] = (char*)malloc(sizeof(char) * square_size + 1);
		while (length < square_size)
		{
			new_square[height][length] = '.';
			length++;
		}
		new_square[height][length] = '\0';
		height++;
	}
	return (new_square);
}
