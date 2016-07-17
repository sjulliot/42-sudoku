#ifndef ALGO_H
#define ALGO_H

typedef struct	s_position
{
	int			x;
	int			y;
}				t_position;

/*
** utils.c
*/
char			**alloc_grid(char **av);
void			free_grid(char **grid);
t_position		find_first_available(char **grid, t_position search_from);
char			value_at_position(char **grid, t_position position);
void			set_position(char **grid, t_position position, char value);

#endif
