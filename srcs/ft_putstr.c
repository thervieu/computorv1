/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thervieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:48:42 by thervieu          #+#    #+#             */
/*   Updated: 2020/08/07 12:48:43 by thervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computorv1.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return ;
}

void	ft_putstrf(char *str, float nb)
{
	ft_putstr(str);
	ft_putnbrf1(nb);
}
