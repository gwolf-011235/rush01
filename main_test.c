/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:03:59 by gwolf             #+#    #+#             */
/*   Updated: 2022/08/17 14:31:34 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	create_game(char *argv[], char game[6][6]);
void	init_matrix(char game[6][6]);
void	fill_easy(char game[6][6]);
void	fill_advanced(char game[6][6]);
void	sudoku_check(char game[6][6]);
void	you_complete_me(char game[6][6]);
void	print_game(char game[6][6], int min, int max);
void	clean_input(char argv[1], char game[6][6]);
int		can_do(char game[6][6]);

int	output_error_check(char game[6][6])
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			if (game[i][j] == '0' || game[i][j] == ':')
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_check(char *argv[])
{
	int	a;
	int	strlen;

	strlen = 0;
	a = 0;
	while (argv[1][strlen] != '\0')
		strlen++;
	if (strlen == 31)
	{
		while (a <= strlen)
		{
			if ((argv[1][a] < '5' && argv[1][a] > '0') && (argv[1][a + 1] == ' '
					|| argv[1][a + 1] == '\0'))
				a = a + 2;
			else
				return (1);
		}
		return (0);
	}
	return (1);
}

int	write_error(int error)
{
	if (error == 0)
		return (0);
	if (error == 1)
		write(2, "Error: wrong Input", 18);
	if (error == 2)
		write(2, "Error: unsolveable", 18);
	if (error == 3)
		write(2, "Error: wrong Argument number", 28);
	return (1);
}

void	secret_algorithm(char game[6][6])
{
	write(1, "\nSTART\n", 7);
	print_game(game, 0, 6);

	write(1, "\nEASY\n", 6);
	fill_easy(game);
	print_game(game, 0, 6);

	write(1, "\nSUDO\n", 6);
	sudoku_check(game);
	print_game(game, 0, 6);

	write(1, "\nADV\n", 5);
	fill_advanced(game);
	print_game(game, 0, 6);

	write(1, "\nSUDO2\n", 7);
	sudoku_check(game);
	print_game(game, 0, 6);

	write(1, "\nCOMP\n", 6);
	you_complete_me(game);
}

int	main(int argc, char *argv[])
{
	char	game[6][6];

	if (argc != 2)
	{
		write_error(3);
		return (1);
	}
	if (write_error(input_check(argv)) == 1)
		return (1);
	create_game(argv, game);
	secret_algorithm(game);
	if (write_error(output_error_check(game)) == 1)
		return (1);
if (write_error(can_do(game)) == 1)
		return (1);
	print_game(game, 0, 6);
	return (0);
}
