/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 08:59:00 by racamach          #+#    #+#             */
/*   Updated: 2025/06/19 09:51:54 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	*init_mandelbrot(void)
{
	t_mandelbrot	*m;

	m = malloc(sizeof(t_mandelbrot));
	if (m == NULL)
		return (NULL);
	m->zoom = 4.0 / WIDTH;
	m->offset_x = 0.0;
	m->offset_y = 0.0;
	init_gradient_mandelbrot(m->gradient);
	return (m);
}

void	*init_julia(double re, double im)
{
	t_julia	*j;

	j = malloc(sizeof(t_julia));
	if (j == NULL)
		return (NULL);
	j->zoom = 4.0 / WIDTH;
	j->offset_x = 0.0;
	j->offset_y = 0.0;
	j->re = re;
	j->im = im;
	init_gradient_julia(j->gradient);
	return (j);
}
