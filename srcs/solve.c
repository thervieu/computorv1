#include "../incs/computorv1.h"

float absf(float nb) {
	if (nb == 0) return 0;
	return (nb > 0 ? nb : nb * (float)-1);
}

void	solve_013(t_equation eq)
{
	if (eq.degree == 0)
	{
		if (eq.coefc == 0)
			printf("All numbers (real or complex) are solution to this equation.\n");
		else
			printf("This equation is false, it doesn't make sense to talk about its solutions.\n");
		return ;
	}
	else if (eq.degree == 1)
	{
		printf("The unique solution is ");
		eq.sol1 = (eq.coefc != 0) ? -1.0 * eq.coefb / eq.coefc : 0;
		printf("%c %.3f\n", eq.sol1 > 0 ? '+' : '-', absf(eq.sol1));
		return ;
	}
	else if (eq.degree == 3)
	{
		printf("The polynomial degree is stricly greater than 2, computorv1 can't solve this equation.\n");
		return ;
	}
}

void	solve_2(t_equation eq)
{
	eq.disc = (eq.coefb * eq.coefb) - (4 * eq.coefa * eq.coefc);
	if (eq.disc > 0)
	{
		printf("Discriminant is strictly positive, the two real solutions are:\n");
		eq.sol1 = (((-1.0 * eq.coefb) - ft_sqrtf(eq.disc))
					/ (2.0 * eq.coefa));
		eq.sol2 = (((-1.0 * eq.coefb) + ft_sqrtf(eq.disc))
					/ (2.0 * eq.coefa));
		printf("%c %.3f\n", eq.sol1 > 0 ? '+' : '-', absf(eq.sol1));
		printf("%c %.3f\n", eq.sol2 > 0 ? '+' : '-', absf(eq.sol2));
	}
	else if (eq.disc == 0)
	{
		printf("Discriminant is equal to 0,\nthe unique solution is ");
		eq.sol1 = (-1.0 * eq.coefb) / (2.0 * eq.coefa);
		printf("%c %.3f\n", eq.sol1 > 0 ? '+' : '-', absf(eq.sol1));
	}
	else if (eq.disc < 0){
		printf("Discriminant is strictly negative, the two complex solutions are:\n");
		eq.sol1 = (-1.0 * eq.coefb) / (2.0 * eq.coefa);
		printf("%c %.3f ", eq.sol1 > 0 ? '+' : '-', absf(eq.sol1));

		eq.sol1 = (-1.0 * ft_sqrtf(-1.0 * eq.disc)) / (2.0 * eq.coefa);
		printf("%c %.3f i\n", eq.sol1 > 0 ? '+' : '-', absf(eq.sol1));

		eq.sol2 = (-1.0 * eq.coefb) / (2.0 * eq.coefa);
		printf("%c %.3f ", eq.sol2 > 0 ? '+' : '-', absf(eq.sol2));

		eq.sol2 = (+1.0 * ft_sqrtf(-1.0 * eq.disc)) / (2.0 * eq.coefa);
		printf("%c %.3f i\n", eq.sol2 > 0 ? '+' : '-', absf(eq.sol2));
	}
}

void	solve(t_equation eq)
{
	(eq.coefc != 0) ? eq.degree = 0 : 0;
	(eq.coefb != 0) ? eq.degree = 1 : 0;
	(eq.coefa != 0) ? eq.degree = 2 : 0;
	(eq.coef3 != 0) ? eq.degree = 3 : 0;
	if (eq.degree != 3) {
	printf("\nReduced form: %c %.3f", eq.coefa > 0 ? '+' : '-', absf(eq.coefa));
	printf(" * X^2 %c %.3f", eq.coefb > 0 ? '+' : '-', absf(eq.coefb));
	printf(" * X^1 %c %.3f", eq.coefc > 0 ? '+' : '-', absf(eq.coefc));
	printf(" * X^0 = 0\n");
	printf("\nPolynomial degree: %d\n\n", eq.degree);
	}
	(eq.degree != 2) ? solve_013(eq) : solve_2(eq);
}
