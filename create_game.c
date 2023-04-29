/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhochsto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:19:56 by mhochsto          #+#    #+#             */
/*   Updated: 2022/08/16 14:05:06 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_game(char game[6][6], char *clean_string)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 4)
			game[0][(i + 1)] = clean_string[i];
		else if (i < 8)
			game[5][(i - 3)] = clean_string[i];
		else if (i < 12)
			game[(i - 7)][0] = clean_string[i];
		else
			game[(i - 11)][5] = clean_string[i];
		i++;
	}
}

void	clean_input(char argv[1], char game[6][6])
{
	int		i;
	int		j;
	char	clean_string[16];

	i = 0;
	j = 0;
	while (argv[i] != 0)
	{
		if (argv[i] == 32)
		{
			i++;
		}
		else
		{
			clean_string[j] = argv[i];
			i++;
			j++;
		}
	}
	fill_game(game, clean_string);
}

void	init_matrix(char game[6][6])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 6)
	{
		while (y < 6)
		{
			game[x][y] = '0';
			y++;
		}
		y = 0;
		x++;
	}
}

void	create_game(char *argv[1], char game[6][6])
{
	init_matrix(game);
	clean_input(argv[1], game);
}
