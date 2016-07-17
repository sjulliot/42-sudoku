#include <stdlib.h>
#include "utils.h"
#include "sudoku.h"

char		**alloc_grid(char **av)
{
	char	**grid;
	int		i;

	if ((grid = (char**)malloc(9 * sizeof(char *))) == NULL)
		return (NULL);
	i = -1;
	while (++i < 9)
		if ((grid[i] = ft_strcpy(av[i])) == NULL)
			return (NULL);
	return (grid);
}

void		free_grid(char **grid)
{
	int		i;

	i = -1;
	while (++i < 9)
		free(grid[i]);
	free(grid);
}

t_position		find_first_available(char **grid, t_position search_from)
{
	while (search_from.y < 9)
	{
		while (search_from.x < 9)
		{
			if (grid[search_from.y][search_from.x] == '.')
				return (search_from);
			search_from.x++;
		}
		search_from.y++;
		search_from.x = -1;
	}
	return ((t_position){.x = -1, .y = -1});
}

char			value_at_position(char **grid, t_position position)
{
	return (grid[position.y][position.x]);
}

void			set_position(char **grid, t_position position, char value)
{
	grid[position.y][position.x] = value;
}
