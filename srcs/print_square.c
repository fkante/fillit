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
	int j;

	i = -1;
	printf("\e[1;1H\e[2J");
	while (++i < square_size)
	{
		j = -1;
		while (++j < square_size)
		{
			if (square[i][j] == 0)
				printf(YELLOW(" . "));
			else
			{
				if ((square[i][j] - 65) % 4 == 0)
					printf(GREEN(" %c "), square[i][j]);
				else if ((square[i][j] - 65) % 4 == 1)
					printf(RED(" %c "), square[i][j]);
				else if ((square[i][j] - 65) % 4 == 2)
					printf(BLUE(" %c "), square[i][j]);
				else if ((square[i][j] - 65) % 4 == 3)
					printf(MAGENTA(" %c "), square[i][j]);
				else if ((square[i][j] - 65) % 4 == 4)
					printf(CYAN(" %c "), square[i][j]);
				else
					printf(YELLOW(" %c "), square[i][j]);

			}
		}
		printf("\n");
	}
}
/*	int i;

	i = 0;
	while (i < square_size)
	{
	ft_putstr(square[i++]);
	ft_putchar('\n');
	}
	}*/
