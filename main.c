#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "sudoku.h"

int			invalid_chars_in_line(const char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '.')
			return (1);
		s++;
	}
	return (0);
}

int			error_in_arguments(int ac, char **av)
{
	int		i;

	if (ac != 10)
		return (1);
	i = 0;
	while (++i <= 9)
		if (ft_strlen(av[i]) != 9 || invalid_chars_in_line(av[i]))
			return (1);
	return (0);
}

void		exit_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

void		print_solution(char **av)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= 9)
	{
		j = -1;
		while (++j <= 9)
		{
			write(1, av[i] + j, 1);
			ft_putstr(" ");
		}
		ft_putstr("\n");
	}
}

int			main(int ac, char **av)
{
	int		solutions_nb;
	char	**res;

	if (error_in_arguments(ac, av))
		exit_error();
	res = 0;
	solutions_nb = solve(av + 1, &res);
	if (solutions_nb != 1)
		exit_error();
	print_solution(res);
	free_grid(res);
	return (0);
}
