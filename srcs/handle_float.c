/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thervieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:20:11 by thervieu          #+#    #+#             */
/*   Updated: 2020/08/07 18:20:12 by thervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computorv1.h"

float		ft_sqrtf(float nb)
{
	float	calc;
	float	diff;

	if (nb == 0.0 || nb == 1.0)
		return (nb);
	calc = nb;
	diff = calc;
	calc = 0.5 * (calc + nb / calc);
	while (calc != diff)
	{
		diff = calc;
		calc = 0.5 * (calc + nb / calc);
	}
	return (calc);
}

float		ft_atof(const char *str, int ret, int fact, int d)
{
	int	point_seen;

	point_seen = 0;
	if (*str == '-' || *str == '+' || *str == '=')
	{
		*str == '-' ? fact *= -1 : 0;
		str += 2;
	}
	while (*str == ' ')
		str++;
	while (*str != ' ')
	{
		(*str == '.') ? point_seen = 1 : 0;
		(*str == '.') ? str++ : 0;
		d = *str - '0';
		if (d >= 0 && d <= 9)
		{
			(point_seen == 1) ? fact /= 10.0f : 0;
			ret = ret * 10.0f + (float)d;
		}
		str++;
	}
	return (ret * fact);
}
