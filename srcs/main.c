#include "../incs/computorv1.h"

int ft_strlen(char *str) {
	int i = 0;
	while (str[i]) i++;
	return (i);
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

int		main(int ac, char **av)
{
	if (ac != 2) {
		printf("Usage: ./computorv1 [equation]\n");
		return (1);
	}

	t_equation	eq;
	bzero(&eq, sizeof(t_equation));

	int			i = 0;
	int			eq_sign = 0;
	float		tmp;

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
		int power = ft_atoi(str, &i);
		if (power >= 200000) {
			printf("power >= 200k. You are mad. Please input a power lower than 200k :)\n");
			exit(1);
		}
		eq.coefs[power] += eq_sign == 0 ? tmp : -1 * tmp;
	}
	solve(eq);
	free(str);
	return (0);
}
