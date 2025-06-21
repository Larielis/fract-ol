/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 08:38:57 by racamach          #+#    #+#             */
/*   Updated: 2025/06/16 10:59:12 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	int32_t	mx;
	int32_t	my;
	t_vars	*v;

	(void)xdelta;
	v = (t_vars *)param;
	mlx_get_mouse_pos(v->mlx, &mx, &my);
	if (v->fractal == MANDELBROT)
		mandelbrot_scroll((t_mandelbrot *)v->ctx, mx, my, ydelta);
	else
		julia_scroll((t_julia *)v->ctx, mx, my, ydelta);
	v->need_redraw = true;
}

/*
** Key press → escape / pan
*/
void	key_hook(mlx_key_data_t key, void *param)
{
	t_vars	*v;

	v = (t_vars *)param;
	if (key.action != MLX_PRESS)
		return ;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(v->mlx);
	if (v->fractal == MANDELBROT)
		mandelbrot_pan((t_mandelbrot *)v->ctx, key);
	else
		julia_pan((t_julia *)v->ctx, key);
	v->need_redraw = true;
}

/*
** Main render loop → redraw when needed
*/
void	loop_hook(void *param)
{
	t_vars	*v;

	v = (t_vars *)param;
	if (v->need_redraw == false)
		return ;
	if (v->fractal == MANDELBROT)
		render_mandelbrot(v);
	else
		render_julia(v);
	v->need_redraw = false;
}

/*
** Hook registration
*/
void	setup_hooks(t_vars *vars)
{
	mlx_scroll_hook(vars->mlx, scroll_hook, vars);
	mlx_key_hook(vars->mlx, key_hook, vars);
	mlx_loop_hook(vars->mlx, loop_hook, vars);
}
