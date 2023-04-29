/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_easy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhochsto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:23:02 by mhochsto          #+#    #+#             */
/*   Updated: 2022/08/14 22:05:15 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	fill_top(char game[6][6], int *y, int *x, int *i)
{
	*y = 0;
	*x = 1;
	*i = 1;
	while (*x <= 4)
	{
		if ((game[*y][*(x)]) == '1')
			game[*y + 1][*x] = '4';
		if (game[*y][*x] == '4')
		{
			while (*i <= 4)
			{
				game[*y + *i][*x] = (*i + 48);
				*i = *i + 1;
			}
			*i = 1;
		}
		if (game[*y][*x] == '3' && game[*y + 1][*x] == '0')
			game[*y + 1][*x] = ':';
		if (game[*y][*x] == '2' && game[*y + 5][(*x)] == '1')
			game[(*y + 1)][*x] = '3';
		*x = *x + 1;
	}
}

void	fill_bot(char game[6][6], int *y, int *x, int *i)
{
	*y = 5;
	*x = 1;
	*i = 1;
	while (*x <= 4)
	{
		if ((game[*y][*x]) == '1')
			game[*y - 1][*x] = '4';
		if (game[*y][*x] == '4')
		{
			while (*i <= 4)
			{
				game[*y - *i][*x] = (*i + 48);
				*i = *i + 1;
			}
			*i = 1;
		}
		if (game[*y][*x] == '3' && game[*y - 1][*x] == '0')
			game[*y - 1][*x] = ':';
		if (game[*y][*x] == '2' && game[*y - 5][(*x)] == '1')
			game[(*y - 1)][*x] = '3';
		*x = *x + 1;
	}
}

void	fill_left(char game[6][6], int *y, int *x, int *i)
{
	*y = 1;
	*x = 0;
	*i = 1;
	while (*y <= 4)
	{
		if ((game[*y][*x]) == '1')
			game[*y][*x + 1] = '4';
		if (game[*y][*x] == '4')
		{
			while (*i <= 4)
			{
				game[*y][*x + *i] = (*i + 48);
				*i = *i + 1;
			}
			*i = 1;
		}
		if (game[*y][*x] == '3' && game[*y][(*x + 1)] == '0')
			game[*y][*x + 1] = ':';
		if (game[*y][*x] == '2' && game[*y][*x + 5] == '1')
			game[*y][*x + 1] = '3';
		*y = *y + 1;
	}
}

void	fill_right(char game[6][6], int *y, int *x, int *i)
{
	*y = 1;
	*x = 5;
	*i = 1;
	while (*y <= 4)
	{
		if ((game[*y][*x]) == '1')
			game[*y][*x - 1] = '4';
		if (game[*y][*x] == '4')
		{
			while (*i <= 4)
			{
				game[*y][*x - *i] = (*i + 48);
				*i = *i + 1;
			}
			*i = 1;
		}
		if (game[*y][*x] == '3' && game[*y][*x - 1] == '0')
			game[*y][*x - 1] = ':';
		if (game[*y][*x] == '2' && game[*y][(*x - 5)] == '1')
			game[*y][*x - 1] = '3';
		*y = *y + 1;
	}
}

void	fill_easy(char game[6][6])
{
	int	*y;
	int	*x;
	int	*i;

	y = (int *)malloc(sizeof(int));
	x = (int *)malloc(sizeof(int));
	i = (int *)malloc(sizeof(int));
	fill_top(game, y, x, i);
	fill_bot(game, y, x, i);
	fill_left(game, y, x, i);
	fill_right(game, y, x, i);
	free(y);
	free(x);
	free(i);
}
