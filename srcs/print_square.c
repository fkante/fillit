/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:35:48 by fkante            #+#    #+#             */
/*   Updated: 2019/07/02 10:37:22 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

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
