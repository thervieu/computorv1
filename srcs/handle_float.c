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

float		ft_atof(const char *str, int *i)
{
	int	point_seen = 0;
	float fact = 1;
	float ret = 0;
	int d = 0;

	if (str[*i] == '-' || str[*i] == '+')
	{
		str[*i] == '-' ? fact *= -1 : 0;
		(*i)++;
	}
	while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '.')
	{
		if (str[*i] == '.') {
			point_seen = 1;
			(*i)++;
			continue;
		}
		d = str[*i] - '0';
		if (d >= 0 && d <= 9)
		{
			(point_seen == 1) ? fact /= 10.0f : 0;
			ret = ret * 10.0f + (float)d;
		}
		(*i)++;
	}
	while (str[*i] && str[*i] != '^' && str[*i] != '=')
		(*i)++;
	return (ret * fact);
}

int		ft_atoi(const char *str, int *i) {
	int ret = 0;
	while (str[*i] >= '0' && str[*i] <= '9') {
		ret = (ret * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (ret);
}
