/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:45:35 by racamach          #+#    #+#             */
/*   Updated: 2025/06/21 15:17:08 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Iterate z ↦ z² + c until it “escapes” or we hit MAX_ITER
returns the number of steps taken (the “escape time”)

zₙ₊₁ = zₙ² + c
with zₙ = xₙ + i.yₙ and c = k_re + i.k_im
⇒ xₙ₊₁ = xₙ² - yₙ² + k_re
  yₙ₊₁ = 2.xₙ.yₙ + k_im

escape when |zₙ|² = xₙ² + yₙ² > 4
*/
static int	julia_iter(t_complex *z, double k_re, double k_im)
{
	int		iter;
	double	zr2;
	double	zi2;
	double	tmp_re;

	iter = 0;
	while (iter < MAX_ITER)
	{
		zr2 = z->re * z->re;
		zi2 = z->im * z->im;
		if (zr2 + zi2 > 4.0)
			break ;
		tmp_re = zr2 - zi2 + k_re;
		z->im = 2.0 * z->re * z->im + k_im;
		z->re = tmp_re;
		iter++;
	}
	return (iter);
}

static uint32_t	julia_color(int iter, t_julia *j)
{
	int	color_idx;
	int	next_idx;

	if (iter == MAX_ITER)
		return (0x000000FFu);
	color_idx = iter % GRADIENT_SIZE;
	next_idx = (color_idx + 1) % GRADIENT_SIZE;
	return (interpolate(j->gradient[color_idx], j->gradient[next_idx], 0.0));
}

static void	julia_pixel(t_vars *vars, int x, int y)
{
	t_julia		*j;
	t_complex	z;
	int			iter;
	uint32_t	color;

	j = (t_julia *)vars->ctx;
	z.re = (x - WIDTH * 0.5) * j->zoom + j->offset_x;
	z.im = (y - HEIGHT * 0.5) * j->zoom + j->offset_y;
	iter = julia_iter(&z, j->re, j->im);
	color = julia_color(iter, j);
	set_pixel(vars->img, x, y, color);
}

void	render_julia(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			julia_pixel(vars, x, y);
			x++;
		}
		y++;
	}
}
