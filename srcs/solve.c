#include "../incs/computorv1.h"

float absf(float nb) {
	if (nb == 0) return 0;
	return (nb > 0 ? nb : nb * (float)-1);
}

void	solve_013(t_equation eq)
{
	if (eq.degree == 0)
	{
		if (eq.coefs[0] == 0)
			printf("\nAll numbers (real or complex) are solution to this equation.\n");
		else
			printf("\nThis equation is false, it doesn't make sense to talk about its solutions.\n");
		return ;
	}
	else if (eq.degree == 1)
	{
		printf("\nThe unique solution is -c / b\n\n");
		printf("Replacing with the values,\n");
		printf("(-1 * %.3f) / %.3f\n", eq.coefs[0], eq.coefs[1]);
		eq.sol1 = -1.0 * eq.coefs[0] / eq.coefs[1];
		printf("\nAfter calulation the solution is\n");
		printf("%c %.3f\n", eq.sol1 >= 0 ? '+' : '-', absf(eq.sol1));
		return ;
	}
	else if (eq.degree >= 3)
	{
		printf("\nThe polynomial degree is stricly greater than 2, computorv1 can't solve this equation.\n");
		return ;
	}
}

void	solve_2(t_equation eq)
{
	printf("\nDiscriminant = b^2 - (4 * a * c)\n");
	printf("Discriminant = (%.3f)^2 - (4 * %.3f * %.3f)\n", eq.coefs[1], eq.coefs[0], eq.coefs[2]);
	eq.disc = (eq.coefs[1] * eq.coefs[1]) - (4 * eq.coefs[2] * eq.coefs[0]);
	printf("Discriminant = %.3f\n\n", eq.disc);
	if (eq.disc > 0)
	{
		printf("Discriminant is strictly positive.\nThe two real solutions are,\n- b - sqrt(delta) / (2 * a)\nand:\n- b + sqrt(delta) / (2 * a)\n\n");
		printf("Replacing with the values,\n");
		printf("(-1 * %.3f) - (-1 * sqrt(%.3f)) / (2 * %.3f)\nand\n", eq.coefs[1], eq.disc, eq.coefs[2]);
		printf("(-1 * %.3f) + (-1 * sqrt(%.3f)) / (2 * %.3f)\n", eq.coefs[1], eq.disc, eq.coefs[2]);
		printf("\nAfter calulation the solutions are\n");
		eq.sol1 = (((-1.0 * eq.coefs[1]) - ft_sqrtf(eq.disc))
					/ (2.0 * eq.coefs[2]));
		eq.sol2 = (((-1.0 * eq.coefs[1]) + ft_sqrtf(eq.disc))
					/ (2.0 * eq.coefs[2]));
		printf("%c %.3f\n", eq.sol1 >= 0 ? '+' : '-', absf(eq.sol1));
		printf("%c %.3f\n", eq.sol2 >= 0 ? '+' : '-', absf(eq.sol2));
	}
	else if (eq.disc == 0)
	{
		printf("Discriminant is equal to 0.\nthe unique solution is,\n-b/(2*a)\n\n");
		printf("Replacing with the values,\n");
		printf("-1 * %.3f / (2 * %.3f)\n", eq.coefs[1], eq.coefs[2]);
		eq.sol1 = (-1.0 * eq.coefs[1]) / (2.0 * eq.coefs[2]);
		printf("\nAfter calulation the solution is\n");
		printf("%c %.3f\n", eq.sol1 >= 0 ? '+' : '-', absf(eq.sol1));
	}
	else if (eq.disc < 0){
		printf("Discriminant is strictly negative.\n");
		printf("The two complex solutions are, \n- b - (sqrt(-delta) * i) / (2 * a)\nand:\n- b + (sqrt(-delta) * i) / (2 * a)\n\n");
		printf("Replacing with the values,\n");
		printf("(-1 * %.3f) - (-1 * sqrt(%.3f)) * i / (2 * %.3f)\nand\n", eq.coefs[1], -1 * eq.disc, eq.coefs[2]);
		printf("(-1 * %.3f) + (-1 * sqrt(%.3f)) * i / (2 * %.3f)\n", eq.coefs[1], -1 * eq.disc, eq.coefs[2]);
		printf("\nAfter calulation the solutions are\n");
		eq.sol1 = (-1.0 * eq.coefs[1]) / (2.0 * eq.coefs[2]);
		printf("%c %.3f ", eq.sol1 >= 0 ? '+' : '-', absf(eq.sol1));

		eq.sol1 = (-1.0 * ft_sqrtf(-1.0 * eq.disc)) / (2.0 * eq.coefs[2]);
		printf("%c %.3f i\n", eq.sol1 >= 0 ? '+' : '-', absf(eq.sol1));

		eq.sol2 = (-1.0 * eq.coefs[1]) / (2.0 * eq.coefs[2]);
		printf("%c %.3f ", eq.sol2 >= 0 ? '+' : '-', absf(eq.sol2));

		eq.sol2 = (+1.0 * ft_sqrtf(-1.0 * eq.disc)) / (2.0 * eq.coefs[2]);
		printf("%c %.3f i\n", eq.sol2 >= 0 ? '+' : '-', absf(eq.sol2));
	}
}

void	solve(t_equation eq)
{
	printf("\nReduced form:");
	for (int power = 199999 ; power >= 0; power--) {
		if (eq.coefs[power] != 0) {
			printf(" %c %.3f * X^%d", eq.coefs[power] >= 0 ? '+' : '-', absf(eq.coefs[power]), power);
			if (eq.degree == 0) eq.degree = power;
		}
	}
	printf(" = 0\n");
	printf("\nPolynomial degree: %d\n", eq.degree);
	(eq.degree != 2) ? solve_013(eq) : solve_2(eq);
}
