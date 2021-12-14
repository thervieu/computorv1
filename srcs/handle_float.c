#include "../incs/computorv1.h"

float		ft_sqrtf(float nb) // babylonian method
{
	if (nb == 0.0 || nb == 1.0)
		return (nb);

	float	calc = nb;
	float	diff = 1;
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
