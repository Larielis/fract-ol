/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:45:17 by racamach          #+#    #+#             */
/*   Updated: 2025/06/21 15:16:17 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Iterate z ↦ z² + c starting from z₀ = 0 until it “escapes” or we hit MAX_ITER
returns the number of steps taken (the “escape time”)

z₀     = 0 + 0i
zₙ₊₁ = zₙ² + c
with zₙ = xₙ + i.yₙ  and  c = c_re + i.c_im
⇒ xₙ₊₁ = xₙ² − yₙ² + c_re
  yₙ₊₁ = 2.xₙ.yₙ + c_im
escape when |zₙ|² = xₙ² + yₙ² > 4
*/
static int	mandelbrot_iter(t_complex c)
{
	int			iter;
	t_complex	z;
	double		zr2;
	double		zi2;
	double		tmp;

	iter = 0;
	z.re = 0.0;
	z.im = 0.0;
	zr2 = 0.0;
	zi2 = 0.0;
	while (zr2 + zi2 <= 4.0 && iter < MAX_ITER)
	{
		tmp = zr2 - zi2 + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		zr2 = z.re * z.re;
		zi2 = z.im * z.im;
		iter++;
	}
	return (iter);
}

static uint32_t	mandelbrot_color(int iter, t_mandelbrot *m)
{
	int	color_idx;
	int	next_idx;

	if (iter == MAX_ITER)
		return (0x000000FFu);
	color_idx = iter % GRADIENT_SIZE;
	next_idx = (color_idx + 1) % GRADIENT_SIZE;
	return (interpolate(m->gradient[color_idx], m->gradient[next_idx], 0.0));
}

static void	mandelbrot_pixel(t_vars *vars, int x, int y)
{
	t_mandelbrot	*m;
	t_complex		c;
	int				iter;
	uint32_t		col;

	m = vars->ctx;
	c.re = (x - WIDTH * 0.5) * m->zoom + m->offset_x;
	c.im = (y - HEIGHT * 0.5) * m->zoom + m->offset_y;
	iter = mandelbrot_iter(c);
	col = mandelbrot_color(iter, m);
	set_pixel(vars->img, x, y, col);
}

void	render_mandelbrot(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot_pixel(vars, x, y);
			x++;
		}
		y++;
	}
}
