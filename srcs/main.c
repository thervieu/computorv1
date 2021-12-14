#include "../incs/computorv1.h"

int		search(char *str, int pos)
{
	int		i;

	i = 0;
	while (str[pos + i] && str[pos + i] != '+' && str[pos + i] != '-'
		&& str[pos + i] != '=')
		i--;
	return (i);
}

void	init_eq(t_equation *eq)
{
	eq->degree = 0;
	eq->coefc = 0;
	eq->coefb = 0;
	eq->coefa = 0;
	eq->coef3 = 0;
	eq->sol1 = 0;
	eq->sol2 = 0;
}

void		if_forest(t_equation *eq, char c, float tmp, int eq_sign)
{
	if (eq_sign == 0)
	{
		(c == '0') ? eq->coefc += tmp : 0;
		(c == '1') ? eq->coefb += tmp : 0;
		(c == '2') ? eq->coefa += tmp : 0;
		(c == '3') ? eq->coef3 += tmp : 0;
	}
	else
	{
		(c == '0') ? eq->coefc -= tmp : 0;
		(c == '1') ? eq->coefb -= tmp : 0;
		(c == '2') ? eq->coefa -= tmp : 0;
		(c == '3') ? eq->coef3 -= tmp : 0;
	}
}

void	first_coef(char *str, int *i, t_equation *eq, float tmp)
{
	while (str[*i] != 'X')
		(*i)++;
	(str[*i + 2] == '0') ? eq->coefc = tmp : 0;
	(str[*i + 2] == '1') ? eq->coefb = tmp : 0;
	(str[*i + 2] == '2') ? eq->coefa = tmp : 0;
	(str[*i + 2] == '3') ? eq->coef3 = tmp : 0;
	(*i)++;
}

int		main(int ac, char **av)
{
	if (ac != 2) {
		printf("Wrong number of arguments\nUsage: ./computorv1 [equation]");
		return (1);
	}

	int			i = 0;
	int			eq_sign = 0;
	float		tmp;
	t_equation	eq;

	init_eq(&eq);
	eq_sign = 0;
	if (ac != 2)
		return (1);
	tmp = ft_atof(av[1], 0, 1, 0);
	first_coef(av[1], &i, &eq, tmp);
	while (av[1][i++])
	{
		(av[1][i] == '=') ? eq_sign++ : 0;
		if (av[1][i] == 'X')
		{
			tmp = ft_atof(av[1] + i + search(av[1], i), 0, 1, 0);
			if_forest(&eq, av[1][i + 2], tmp, eq_sign);
		}
	}
	solve(eq);
	return (0);
}
