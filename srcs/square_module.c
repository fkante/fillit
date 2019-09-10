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
		ft_memdel((void**)&square[i]);
		i++;
	}
}

char	**creation_square(int square_size)
{
	int		height;
	int		length;
	char		**new_square;

	if((new_square = ft_memalloc(sizeof(char*) * (square_size + 1))) == NULL)
		return (NULL);
	height = 0;
	while (height < square_size)
	{
		length = 0;
		if(!(new_square[height] = ft_strnew(square_size + 10)))
			return (NULL);
		while (length < square_size)
		{
			new_square[height][length] = '.';
			length++;
		}
		height++;
	}
	new_square[height] = '\0';
	return (new_square);
}
