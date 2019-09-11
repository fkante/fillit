/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:35:48 by fkante            #+#    #+#             */
/*   Updated: 2019/07/31 10:55:28 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_square(char **square, int square_size)
{
	int i;

	i = 0;
	while (i < square_size)
	{
		ft_putstr(square[i++]);
		ft_putchar('\n');
	}
}

void		free_tab(char **tab)
{
	while (*tab != NULL)
	{
		ft_strdel(&(*tab));
		tab++;
	}
	ft_strdel(tab);
}
