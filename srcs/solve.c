#include "../incs/computorv1.h"

void	solve_013(t_equation eq)
{
	if (eq.degree == 0)
	{
		if (eq.coefc == 0)
			ft_putstr("All numbers (real or complex) are solution to this equation.\n");
		else
			ft_putstr("This equation is false, it doesn't make sense to talk about its solutions.\n");
		return ;
	}
	else if (eq.degree == 1)
	{
		ft_putstr("The unique solution is ");
		eq.sol1 = (eq.coefc != 0) ? -1.0 * eq.coefb / eq.coefc : 0;
		ft_putnbrf1(eq.sol1);
		ft_putchar('\n');
		return ;
	}
	else if (eq.degree == 3)
	{
		ft_putstr("The polynomial degree is stricly greater than 2, computorv1 can't solve this equation.\n");
		return ;
	}
}

void	solve_complex(t_equation eq)
{
	ft_putstr("Discriminant is strictly negative, the two complex solutions are:\n");
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
		ft_putstr("Discriminant is strictly positive, the two real solutions are:\n");
		ft_putnbrf1((((-1.0 * eq.coefb) - ft_sqrtf(eq.disc))
					/ (2.0 * eq.coefa)));
		ft_putchar('\n');
		ft_putnbrf1((((-1.0 * eq.coefb) + ft_sqrtf(eq.disc))
					/ (2.0 * eq.coefa)));
		ft_putchar('\n');
	}
	else if (eq.disc == 0)
	{
		ft_putstr("Discriminant is equal to 0, the unique solution is ");
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
	ft_putstrf("\nReduced form: ", eq.coefa);
	ft_putstrf(" * X^2 ", eq.coefb);
	ft_putstrf(" * X^1 ", eq.coefc);
	ft_putstr(" * X^0 = 0\n");
	ft_putstr("\nPolynomial degree: ");
	ft_putchar('0' + eq.degree);
	write(1, "\n\n", 2);
	(eq.degree != 2) ? solve_013(eq) : solve_2(eq);
}
