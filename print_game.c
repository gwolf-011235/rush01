/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpammer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:25:13 by kpammer           #+#    #+#             */
/*   Updated: 2022/08/16 14:55:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_game(char game[6][6], int min, int max)
{
	int	i;
	int	j;

	i = min;
	while (i < max)
	{
		j = min;
		while (j < max)
		{
			write(1, &game[i][j], 1);
			if (j < (max - 1))
			{
				write(1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
