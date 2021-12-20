#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>

typedef struct	s_equation
{
	int			degree;
	float		coefs[200000];
	float		disc;
	float		sol1;
	float		sol2;
}				t_equation;

float		ft_atof(const char *str, int *i);
int			ft_atoi(const char *str, int *i);
float		ft_sqrtf(float nb);
void		solve(t_equation eq);

#endif
