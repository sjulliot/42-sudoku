#ifndef SUDOKU_H
#define SUDOKU_H

/*
** libft.c
*/
int		ft_strlen(const char *s);
void	ft_putstr(const char *c);
int		ft_isdigit(const char c);
void	ft_bzero(void *s, int size);
char	*ft_strcpy(char *s);

/*
** algo.c
*/
int		solve(char **av, char ***res);

#endif
