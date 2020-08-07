/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thervieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:11:39 by thervieu          #+#    #+#             */
/*   Updated: 2020/08/07 12:11:41 by thervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computorv1.h"

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}

void	ft_putnbrf2(int nb, int dot)
{
	int		power_10;
	int		whole;
	int		frac;

	frac = 0;
	whole = 0;
	power_10 = 1;
	if (dot == 0)
		ft_putnbr(nb);
	else
	{
		while (dot--)
			power_10 *= 10;
		whole = nb / power_10;
		frac = nb % power_10;
		ft_putnbr(whole);
		write(1, ".", 1);
		ft_putnbr(frac);
	}

}

void	ft_putnbrf1(float nb_f)
{
	int	dot;

	dot = 0;
	if (nb_f < 0.0)
	{
		write(1, "- ", 2);
		nb_f *= -1;
	}
	else
		write(1, "+ ", 2);
	//printf("nb = |%f|\n", nb_f);
	while((float)(nb_f - (int)nb_f) != 0.0)
	{
		dot++;
		nb_f *= 10;
	//	printf("nb = |%f|\n", nb_f);
	}
	//printf("nb = |%f|\n", nb_f);
	ft_putnbrf2((int)nb_f, dot);
	return ;
}
