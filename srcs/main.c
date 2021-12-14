#include "../incs/computorv1.h"

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
		(c >= '3') ? eq->coef3 += tmp : 0;
	}
	else
	{
		(c == '0') ? eq->coefc -= tmp : 0;
		(c == '1') ? eq->coefb -= tmp : 0;
		(c == '2') ? eq->coefa -= tmp : 0;
		(c >= '3') ? eq->coef3 -= tmp : 0;
	}
}

char *get_eq_no_space(const char *str) {
	int count = 0;
	int i = 0;
	while (str[i]) {
		if (str[i] != ' ')
			count++;
		i++;
	}
	char *rtn;
	if (!(rtn = malloc((count + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	int j = 0;
	while (str[i]) {
		if (str[i] != ' ') {
			rtn[j] = str[i];
			j++;
		}
		i++;
	}
	rtn[j] = '\0';
	return (rtn);
}

void print_eq(t_equation eq) {
	printf("\neq.degree = |%d|\n", eq.degree);
	printf("eq.coef3 = |%f|\n", eq.coef3);
	printf("eq.coefa = |%f|\n", eq.coefa);
	printf("eq.coefb = |%f|\n", eq.coefb);
	printf("eq.coefc = |%f|\n", eq.coefc);
}

int ft_strlen(char *str) {
	int i = 0;
	while (str[i]) i++;
	return (i);
}

int		main(int ac, char **av)
{
	if (ac != 2) {
		printf("Usage: ./computorv1 [equation]\n");
		return (1);
	}

	int			i = 0;
	int			eq_sign = 0;
	float		tmp;
	t_equation	eq;

	init_eq(&eq);
	char *str = get_eq_no_space(av[1]);
	while (str[i])
	{
		tmp = ft_atof(str, &i);
		if (i == ft_strlen(str))
			break ;
		if (str[i] == '=') {
			eq_sign++;
			i++;
			continue ;
		}
		i++;
		if_forest(&eq, str[i], tmp, eq_sign);
		i++;
	}
	// print_eq(eq);
	solve(eq);
	free(str);
	return (0);
}
