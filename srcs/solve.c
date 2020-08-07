/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thervieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:24:07 by thervieu          #+#    #+#             */
/*   Updated: 2020/08/07 20:24:08 by thervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computorv1.h"

void	solve_013(t_equation eq)
{
	if (eq.degree == 0)
	{
		ft_putstr("All numbers (real or complex) are \
			solution to this equation.");
		return ;
	}
	if (eq.degree == 3)
	{
		ft_putstr("The polynomial degree is stricly gre\
			ater than 2, computorv1 can't solve this equation.\n");
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

void	solve_complex(t_equation eq)
{
	ft_putstr("\nDiscriminant is strictly negative,");
	ft_putstr(" the two complex solutions are:\n");
	ft_putnbrf1((-1.0 * eq.coefb) / (2.0 * eq.coefa));
	ft_putstrf(" ", (-1.0 * ft_sqrtf(-1.0 * eq.disc)) / (2.0 * eq.coefa));
	ft_putstr("i\n");
	ft_putnbrf1((-1.0 * eq.coefb) / (2.0 * eq.coefa));
	ft_putstrf(" ", (+1.0 * ft_sqrtf(-1.0 * eq.disc)) / (2.0 * eq.coefa));
	ft_putstr("i\n");
}

void	solve_2(t_equation eq)
{
	eq.disc = (eq.coefb * eq.coefb) - (4 * eq.coefa * eq.coefc);
	if (eq.disc > 0)
	{
		ft_putstr("\nDiscriminant is strictly positive, ");
		ft_putstr("the two solutions are:\n");
		ft_putnbrf1((((-1.0 * eq.coefb) - ft_sqrtf(eq.disc))
					/ (2.0 * eq.coefa)));
		ft_putchar('\n');
		ft_putnbrf1((((-1.0 * eq.coefb) + ft_sqrtf(eq.disc))
					/ (2.0 * eq.coefa)));
		ft_putchar('\n');
	}
	else if (eq.disc == 0)
	{
		ft_putstr("\nDiscriminant is equal to 0, the unique solution is:\n");
		ft_putnbrf1((-1.0 * eq.coefb) / (2.0 * eq.coefa));
	}
	else if (eq.disc < 0)
		solve_complex(eq);
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
	(eq.degree != 2) ? solve_013(eq) : solve_2(eq);
}
