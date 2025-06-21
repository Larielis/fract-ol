/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 08:38:24 by racamach          #+#    #+#             */
/*   Updated: 2025/06/19 21:19:22 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool	setup_context(t_vars *vars, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		return (handle_mandelbrot(vars));
	if (ft_strcmp(argv[1], "julia") == 0)
		return (handle_julia(vars, argc, argv));
	print_usage(argv[0]);
	return (false);
}

bool	setup_window(t_vars *vars)
{
	vars->mlx = mlx_init(WIDTH, HEIGHT, "fract'ol", false);
	if (vars->mlx == NULL)
		return (false);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (vars->img == NULL)
		return (false);
	if (mlx_image_to_window(vars->mlx, vars->img, 0, 0) < 0)
		return (false);
	return (true);
}

void	cleanup(t_vars *vars)
{
	if (vars->mlx)
		mlx_terminate(vars->mlx);
	if (vars->ctx)
		free(vars->ctx);
}
