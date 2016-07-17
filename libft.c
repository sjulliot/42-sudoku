#include <unistd.h>
#include <stdlib.h>

int				ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void			ft_putstr(const char *s)
{
	const int	len = ft_strlen(s);

	write(1, s, len);
}

int				ft_isdigit(const char c)
{
	return (c >= '1' && c <= '9');
}

void			ft_bzero(void *s, int size)
{
	int			i;

	i = -1;
	while (++i < size)
		((char *)s)[i] = 0;
}

char			*ft_strcpy(char *s)
{
	char		*res;
	int			len = ft_strlen(s);

	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	while (--len >= 0)
		res[len] = s[len];
	res[len] = 0;
	return (res);
}
