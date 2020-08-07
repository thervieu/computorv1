/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thervieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:54:04 by thervieu          #+#    #+#             */
/*   Updated: 2020/08/07 12:54:05 by thervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <unistd.h>
# include <stdio.h>

typedef struct	s_equation
{
	int			degree;
	float		coefc;
	float		coefb;
	float		coefa;
	float		coef3;
	float		disc;
	float		sol1;
	float		sol2;
}				t_equation;

int			ft_strlen(char *str);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);
void		ft_putnbrf1(float nb_f);
void		ft_putstrf(char *str, float nb);
float		ft_atof(const char *str, int ret, int fact, int d);
float		ft_sqrtf(float nb);
void		solve(t_equation eq);

#endif
