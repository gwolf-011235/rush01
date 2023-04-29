/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_unsolveable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:14:38 by gwolf             #+#    #+#             */
/*   Updated: 2022/08/14 20:50:28 by mhochsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	unsolveable_y(char game[6][6], int sum)
{
	int	x;
	int	y;

	y = 1;
	while (y <= 4)
	{
		x = 1;
		while (x <= 4)
		{
			sum += ((game[y][x] - 48));
			x++;
		}
		if (sum != 10)
			return (1);
		sum = 0;
		y++;
	}
	return (0);
}

int	unsolveable_x(char game[6][6], int sum)
{
	int	x;
	int	y;

	x = 1;
	while (x <= 4)
	{
		y = 1;
		while (y <= 4)
		{
			sum += ((game[y][x] - 48));
			y++;
		}
		if (sum != 10)
			return (1);
		sum = 0;
		x++;
	}
	return (0);
}

int	can_do(char game[6][6])
{
	if (unsolveable_y(game, 0) || unsolveable_x(game, 0))
		return (2);
	else
		return (0);
}
