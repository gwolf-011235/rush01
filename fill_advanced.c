/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_advanced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhochsto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:23:02 by mhochsto          #+#    #+#             */
/*   Updated: 2022/08/17 14:24:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	adv_fill_top(char game[6][6], int *y, int *x, int *i)
{
	*y = 0;
	*x = 1;
	*i = 1;
	while (*x <= 4)
	{
		if ((game[*y][*x]) == '3' && game[*y + 5][*x] == '1' && game[*y
			+ 3][*x] == '3' && game[*y + 4][*x] == '4')
			game[*y + 1][*x] = '2';
		if ((game[*y][*x]) == '3' && game[*y + 5][*x] == '2' && game[*y
			+ 3][*x] == '4' && game[*y + 4][*x] == '3')
			game[*y + 1][*x] = '1';
		if (game[*y][*x] == '2' && game[*y + 5][*x] == '3')
			game[*y + 2][*x] = '4';
		if (game[*y][*x] == '2' && game[*y + 5][*x] == '2' && game[*y
			+ 4][*x] == '3' && game[*y + 3][*x] == '4')
			game[*y + 1][*x] = '2';
		*x += 1;
	}
}

void	adv_fill_bot(char game[6][6], int *y, int *x, int *i)
{
	*y = 5;
	*x = 1;
	*i = 1;
	while (*x <= 4)
	{
		if ((game[*y][*x]) == '3' && game[*y - 5][*x] == '1' && game[*y
			- 3][*x] == '3' && game[*y - 4][*x] == '4')
			game[*y - 1][*x] = '2';
		if ((game[*y][*x]) == '3' && game[*y - 5][*x] == '2' && game[*y
			- 3][*x] == '4' && game[*y - 4][*x] == '3')
			game[*y - 1][*x] = '1';
		if (game[*y][*x] == '2' && game[*y - 5][*x] == '3')
			game[*y - 2][*x] = '4';
		if (game[*y][*x] == '2' && game[*y - 5][*x] == '2' && game[*y
			- 4][*x] == '3' && game[*y - 3][*x] == '4')
			game[*y - 1][*x] = '2';
		*x += 1;
	}
}

void	adv_fill_left(char game[6][6], int *y, int *x, int *i)
{
	*y = 1;
	*x = 0;
	*i = 1;
	while (*y <= 4)
	{
		if ((game[*y][*x]) == '3' && game[*y][*x + 5] == '1' && game[*y][*x
			+ 3] == '3' && game[*y][*x + 4] == '4')
			game[*y][*x + 1] = '2';
		if ((game[*y][*x]) == '3' && game[*y][*x + 5] == '2' && game[*y][*x
			+ 3] == '4' && game[*y][*x + 4] == '3')
			game[*y][*x + 1] = '1';
		if (game[*y][*x] == '2' && game[*y][*x + 5] == '3')
			game[*y][*x + 2] = '4';
		if (game[*y][*x] == '2' && game[*y][*x + 5] == '2' && game[*y][*x
			+ 4] == '3' && game[*y][*x + 3] == '4')
			game[*y][*x + 1] = '2';
		*y += 1;
	}
}

void	adv_fill_right(char game[6][6], int *y, int *x, int *i)
{
	*y = 1;
	*x = 5;
	*i = 1;
	while (*y <= 4)
	{
		if ((game[*y][*x]) == '3' && game[*y][*x - 5] == '1' && game[*y][*x
			- 3] == '3' && game[*y][*x - 4] == '4')
			game[*y][*x - 1] = '2';
		if ((game[*y][*x]) == '3' && game[*y][*x - 5] == '2' && game[*y][*x
			- 3] == '4' && game[*y][*x - 4] == '3')
			game[*y][*x - 1] = '1';
		if (game[*y][*x] == '2' && game[*y][*x - 5] == '3')
			game[*y][*x - 2] = '4';
		if (game[*y][*x] == '2' && game[*y][*x - 5] == '2' && game[*y][*x
			- 4] == '3' && game[*y][*x - 3] == '4')
			game[*y][*x - 1] = '2';
		*y += 1;
	}
}

void	fill_advanced(char game[6][6])
{
	int	*y;
	int	*x;
	int	*i;

	y = (int *)malloc(sizeof(int));
	x = (int *)malloc(sizeof(int));
	i = (int *)malloc(sizeof(int));
	adv_fill_top(game, y, x, i);
	adv_fill_bot(game, y, x, i);
	adv_fill_left(game, y, x, i);
	adv_fill_right(game, y, x, i);
	free(y);
	free(x);
	free(i);
}
