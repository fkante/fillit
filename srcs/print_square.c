/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:35:48 by fkante            #+#    #+#             */
/*   Updated: 2019/09/16 16:10:02 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
** void	print_square(char **square, int square_size)
** {
**	int i;
**
**	i = 0;
**	while (i < square_size)
**	{
**		ft_putstr(square[i++]);
**		ft_putchar('\n');
**	}
** }
*/

#include <stdio.h>
#include <sys/ioctl.h>

void    print_square(char **square, int square_size)
{
	int col = 2;
	int i;
	struct winsize  w;
	ioctl(0, TIOCGWINSZ, &w);
	//ft_putstr("\033[2J");
	i = 0;
	while (i < square_size)
	{
		printf("\033[%d;%luH", col + i, w.ws_col - ft_strlen(square[0]));
		printf("%s",square[i++]);
	}
}
