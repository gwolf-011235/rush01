/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:59:52 by gwolf             #+#    #+#             */
/*   Updated: 2022/08/16 14:44:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_line(char game[6][6], int number, int row);
int	check_legal(char game[6][6], int number, int row);
int	check_row(char game[6][6], int number, int line);

/* IDEA check row&line could be combined in one function?
 * for example if rows = 0 then check rows else check lines or something
 */

/* check line looks for the number it gets in the row it gets 
 * we need to +48 to convert the given number into char 
 * we return 0 when number found
 * return 1 if no number which triggers if clause in main
 * */

int	check_line(char game[6][6], int number, int y)
{
	int	x;

	x = 1;
	while (x < 5)
	{
		if (game[y][x] == number + 48)
		{
			return (0);
		}
		x++;
	}
	return (1);
}
/* check_legal is called when we know we dont have a number after check_row
 * it calls itself the check_row function with the given row
 * if check_row finds something we save the current position (= i)
 * we save in game[0][0] to save space
 * it also looks for flags set by easy_rules
 * a flag is the number 58 (= '10') for modulo purposes (problematic?)
 * The empty if clauses check for flag if number == 3 and
 * Check if the suqare is empty (0 or 10 % 10 which is 0).
 */

int	check_legal(char game[6][6], int number, int y)
{
	int	legal_pos;
	int	x;
	int	save_x;

	legal_pos = 0;
	x = 1;
	while (x < 5)
	{
		if ((((game[y][x] - 48) - number) == 7) ||
				(((game[y][x] - 48) % 10) != 0))
		{
		}
		else if (check_row(game, number, x))
		{
			save_x = x;
			legal_pos++;
		}
		x++;
	}
	if (legal_pos == 1)
	{
		game[y][save_x] = (number + 48);
		return (1);
	}
	return (0);
}
/* check_row is like its brother (copy paste)
 */

int	check_row(char game[6][6], int number, int x)
{
	int	y;

	y = 1;
	while (y < 5)
	{
		if (game[y][x] == number + 48)
		{
			return (0);
		}	
		y++;
	}
	return (1);
}
/*sudoku checks for solveable numbers with sudoku-like logic
 * it loops through numbers 4 to 1
 * it first calls check_line with a number (starting with 4)
 * if check line doesnt find anything, sudoku calls check_legal
 * if check_legal is successful sudoku saves a one in game[0][5]
 * if game[0][5] is not zero the same number (e.g. 4) will be checked again
 * maybe we need to add another loop trough everything?
 */

void	sudoku_check(char game[6][6])
{
	int	count;
	int	numbers;
	int	found;

	count = 1;
	numbers = 4;
	found = 0;
	while (numbers)
	{
		while (count < 5)
		{
			if (check_line(game, numbers, count))
				found = check_legal(game, numbers, count);
			count++;
		}
		if (found == 0)
			numbers--;
		else
			numbers = 4;
		found = 0;
		count = 1;
	}
}
