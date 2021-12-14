#include "../incs/computorv1.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return ;
}

void	ft_putstrf(char *str, float nb)
{
	ft_putstr(str);
	ft_putnbrf1(nb);
}
