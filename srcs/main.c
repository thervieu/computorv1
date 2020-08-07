/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thervieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:13:59 by thervieu          #+#    #+#             */
/*   Updated: 2020/08/05 16:14:02 by thervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	eq->degree = -1;
	eq->coefc = 0;
	eq->coefb = 0;
	eq->coefa = 0;
	eq->coef3 = 0;
	eq->sol1 = 0;
	eq->sol2 = 0;
}

void	solve_013(t_equation eq)
{
	if (eq.degree == 0)
	{
		ft_putstr("All numbers (real or complex) are solution to this equation.");
		return ;
	}
	if (eq.degree == 3)
	{
		ft_putstr("The polynomial degree is stricly greater than 2, computorv1 can't solve this equation.\n");
		return ;
	}
	if (eq.degree == 1)
	{
		ft_putstr("The solution is\n");
		eq.sol1 = (eq.coefc != 0) ? -1.0 * eq.coefb / eq.coefc : 0;
		ft_putnbrf1(eq.sol1);
		ft_putchar('\n');
		return ;
	}
}

void	solve_2(t_equation eq)
{
	eq.disc = (eq.coefb * eq.coefb) - (4 * eq.coefa * eq.coefc);
	if (eq.disc > 0)
	{
		ft_putstr("\nDiscriminant is strictly positive, the two solutions are:\n");
		ft_putnbrf1((((-1.0 * eq.coefb) - ft_sqrtf(eq.disc)) / (2.0 * eq.coefa)));
		ft_putchar('\n');
		ft_putnbrf1((((-1.0 * eq.coefb) + ft_sqrtf(eq.disc)) / (2.0 * eq.coefa)));
		ft_putchar('\n');
	}
	else if (eq.disc == 0)
	{
		ft_putstr("\nDiscriminant is equal to 0, the unique solution is:\n");
		ft_putnbrf1((-1.0 * eq.coefb) / (2.0 * eq.coefa));
	}
	else if (eq.disc < 0)
	{
		ft_putstr("\nDiscriminant is strictly negative, the two complex solutions are:\n");
		ft_putnbrf1((-1.0 * eq.coefb) / (2.0 * eq.coefa));
		ft_putstrf(" ", (-1.0 * ft_sqrtf(-1.0 * eq.disc)) / (2.0 * eq.coefa));
		ft_putstr("i\n");
		ft_putnbrf1((-1.0 * eq.coefb) / (2.0 * eq.coefa));
		ft_putstrf(" ", (+1.0 * ft_sqrtf(-1.0 * eq.disc)) / (2.0 * eq.coefa));
		ft_putstr("i\n");
	}
}

void	solve(t_equation eq)
{
	(eq.coefc != 0) ? eq.degree = 0 : 0;
	(eq.coefb != 0) ? eq.degree = 1 : 0;
	(eq.coefa != 0) ? eq.degree = 2 : 0;
	(eq.coef3 != 0) ? eq.degree = 3 : 0;
	ft_putstrf("Reduced form: ", eq.coefc);
	ft_putstrf(" * X^0 ", eq.coefb);
	ft_putstrf(" * X^1 ", eq.coefa);
	ft_putstr(" * X^2 = 0\n");
	ft_putstrf("Polynomial degree: ", eq.degree);
	ft_putchar('\n');
	(eq.degree != 2) ? solve_013(eq) : solve_2(eq);
}

int		main(int ac, char **av)
{
	int			i;
	int			eq_sign;
	float		tmp;
	t_equation	eq;

	init_eq(&eq);
	eq_sign = 0;
	i = 0;
	tmp = 0;
	if (ac != 2)
		return (1);
	tmp = ft_atof(av[1], 0, 1, 0);
	while (av[1][i] != 'X')
		i++;
	(av[1][i + 2] == '0') ? eq.coefc = tmp : 0;
	(av[1][i + 2] == '1') ? eq.coefb = tmp : 0;
	(av[1][i + 2] == '2') ? eq.coefa = tmp : 0;
	(av[1][i + 2] == '3') ? eq.coef3 = tmp : 0;
	i++;
	while (av[1][i])
	{
		(av[1][i] == '=') ? eq_sign++ : 0;
		if (av[1][i] == 'X')
		{

			tmp = ft_atof(av[1] + i + search(av[1], i), 0, 1, 0);
			if (eq_sign == 0)
			{
				(av[1][i + 2] == '0') ? eq.coefc += tmp : 0;
				(av[1][i + 2] == '1') ? eq.coefb += tmp : 0;
				(av[1][i + 2] == '2') ? eq.coefa += tmp : 0;
				(av[1][i + 2] == '3') ? eq.coef3 += tmp : 0;
			}
			else
			{
				(av[1][i + 2] == '0') ? eq.coefc -= tmp : 0;
				(av[1][i + 2] == '1') ? eq.coefb -= tmp : 0;
				(av[1][i + 2] == '2') ? eq.coefa -= tmp : 0;
				(av[1][i + 2] == '3') ? eq.coef3 -= tmp : 0;
			}	
		}
		i++;
	}
	solve(eq);
	return (0);
}
