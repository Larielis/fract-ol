/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:15:54 by racamach          #+#    #+#             */
/*   Updated: 2025/06/21 15:27:20 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	parse_fraction(const char *str, size_t *i, double res)
{
	double	frac;
	double	divisor;

	frac = 0.0;
	divisor = 1.0;
	(*i)++;
	while (ft_isdigit(str[*i]))
	{
		frac = frac * 10.0 + (str[*i] - '0');
		divisor = divisor * 10.0;
		(*i)++;
	}
	return (res + frac / divisor);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	size_t	i;

	result = 0.0;
	sign = 1.0;
	i = 0;
	if (!str)
		return (0.0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		result = parse_fraction(str, &i, result);
	return (sign * result);
}
