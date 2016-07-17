#include <stdlib.h>
#include "utils.h"
#include "sudoku.h"

#include <stdio.h>

int			keeps_row_and_column_valid(char **grid,
										t_position position,
										char new_char)
{
	t_position	tested_position;

	tested_position = (t_position){.x = 0, .y = position.y};
	while (tested_position.x < 9)
	{
		if (tested_position.x != position.x
				&& value_at_position(grid, tested_position) == new_char)
			return (0);
		tested_position.x++;
	}
	tested_position = (t_position){.x = position.x, .y = 0};
	while (tested_position.y < 9)
	{
		if (tested_position.y != position.y
				&& value_at_position(grid, tested_position) == new_char)
			return (0);
		tested_position.y++;
	}
	return (1);
}

int			keeps_subgrid_valid(char **grid,
										t_position position,
										char new_char)
{
	t_position	tested_position;
	int			tested_index;

	//printf("[debug] | | keeps_subgrid CALL [%d][%d]\n", position.y, position.x);
	tested_position.x = 3 * (position.x / 3);
	tested_position.y = 3 * (position.y / 3);
	tested_index = -1;
	while (++tested_index < 9)
	{
		//printf("[debug] | | keeps_subgrid test %d -> [%d][%d]\n", tested_index, tested_position.y, tested_position.x);
		if ((tested_position.x != position.x
				|| tested_position.y != position.y)
				&& value_at_position(grid, tested_position) == new_char)
			return (0);
		tested_position.x += (tested_index % 3 != 2 ? 1 : -2);
		tested_position.y += (tested_index % 3 == 2 ? 1 : 0);
	}
	return (1);
}

int			keeps_valid(char **grid, t_position position, char new_char)
{
	if (keeps_row_and_column_valid(grid, position, new_char) == 0
			|| keeps_subgrid_valid(grid, position, new_char) == 0)
		return (0);
	return (1);
}

int			solve_grid(char **grid, char ***res, t_position search_from)
{
	t_position	current_position;
	char		current_tested_char;
	int			sub_solutions_nb;

	//for (int i = 0; i < 9; i++)
	//	printf("[debug] | grid -> %s\n", grid[i]);
	current_position = find_first_available(grid, search_from);
	//printf("[debug] | found first_available at [%d][%d]\n", current_position.y, current_position.x);
	if (current_position.y == -1 || current_position.x == -1)
	{
		*res = alloc_grid(grid);
		return (1);
	}
	sub_solutions_nb = 0;
	current_tested_char = '0';
	while (++current_tested_char <= '9' && sub_solutions_nb < 2)
	{
		set_position(grid, current_position, current_tested_char);
		if (keeps_valid(grid, current_position, current_tested_char))
			sub_solutions_nb += solve_grid(grid, res, current_position);
	}
	set_position(grid, current_position, '.');
	//printf("[debug] | found %d subsolutions\n\n", sub_solutions_nb);
	return (sub_solutions_nb);
}

int			solve(char **av, char ***res)
{
	char	**grid;
	int		solutions_nb;

	//for (int i = 0; i < 9; i++)
		//printf("av   -> [%s]\n", av[i + 1]);
	if ((grid = alloc_grid(av)) == NULL)
		return (0);
	//printf("[debug] allocated\n");
	solutions_nb = solve_grid(grid, res, (t_position){.x = 0, .y = 0});
	//printf("[debug] solved\n");
	free_grid(grid);
	//printf("[debug] freed\n");
	return (solutions_nb);
}
