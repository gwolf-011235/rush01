/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_complete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:59:52 by gwolf             #+#    #+#             */
/*   Updated: 2022/08/16 13:17:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	four_complete_x(char game[6][6], int sum, int count);
void	four_complete_y(char game[6][6], int sum, int count);

void	you_complete_me(char game[6][6])
{
	int	i;

	i = 10;
	while (i--)
	{
		game[5][0] = 0;
		game[5][5] = 0;
		four_complete_x(game, game[5][0], game[5][5]);
		game[5][0] = 0;
		game[5][5] = 0;
		four_complete_y(game, game[5][0], game[5][5]);
	}
	game[5][0] = 48;
	game[5][5] = 48;
}

void	four_complete_x(char game[6][6], int sum, int count)
{
	char	*empty;
	int		x;
	int		y;

	y = 1;
	while (y < 5)
	{
		x = 1;
		while (x < 5)
		{
			sum += ((game[y][x] - '0') % 10);
			if (((game[y][x] - '0') % 10) != 0)
				count++;
			else
				empty = &game[y][x];
			x++;
		}
		if (count == 3 && *empty != '0')
		{
			*empty = (10 - sum + '0');
		}
		count = 0;
		sum = 0;
		y++;
	}
}

void	four_complete_y(char game[6][6], int sum, int count)
{
	char	*empty;
	int		x;
	int		y;

	x = 1;
	while (x < 5)
	{
		y = 1;
		while (y < 5)
		{
			sum += ((game[y][x] - 48) % 10);
			if (((game[y][x] - 48) % 10) != 0)
				count++;
			else
				empty = &game[y][x];
			y++;
		}
		if (count == 3 && *empty != '0')
		{
			*empty = (10 - sum + 48);
		}
		count = 0;
		sum = 0;
		x++;
	}
}
