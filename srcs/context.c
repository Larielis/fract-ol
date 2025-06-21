/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:13:42 by racamach          #+#    #+#             */
/*   Updated: 2025/06/20 22:32:02 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	handle_mandelbrot(t_vars *vars)
{
	vars->ctx = init_mandelbrot();
	if (vars->ctx == NULL)
		return (false);
	vars->fractal = MANDELBROT;
	vars->need_redraw = true;
	return (true);
}

bool	handle_julia(t_vars *vars, int argc, char **argv)
{
	double	re;
	double	im;

	if (argc > 2)
		re = atof(argv[2]);
	else
		re = -0.8;
	if (argc > 3)
		im = atof(argv[3]);
	else
		im = 0.156;
	vars->ctx = init_julia(re, im);
	if (vars->ctx == NULL)
		return (false);
	vars->fractal = JULIA;
	vars->need_redraw = true;
	return (true);
}
