/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:57:10 by racamach          #+#    #+#             */
/*   Updated: 2025/06/16 11:06:58 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_scroll(t_mandelbrot *m, int32_t mx, int32_t my,
		double ydelta)
{
	double	re;
	double	im;

	re = (mx - WIDTH / 2) * m->zoom + m->offset_x;
	im = (my - HEIGHT / 2) * m->zoom + m->offset_y;
	if (ydelta > 0)
		m->zoom = m->zoom * 0.9;
	else
		m->zoom = m->zoom * 1.1;
	m->offset_x = re - (mx - WIDTH / 2) * m->zoom;
	m->offset_y = im - (my - HEIGHT / 2) * m->zoom;
}

void	julia_scroll(t_julia *j, int32_t mx, int32_t my, double ydelta)
{
	double	re;
	double	im;

	re = (mx - WIDTH / 2) * j->zoom + j->offset_x;
	im = (my - HEIGHT / 2) * j->zoom + j->offset_y;
	if (ydelta > 0)
		j->zoom = j->zoom * 0.9;
	else
		j->zoom = j->zoom * 1.1;
	j->offset_x = re - (mx - WIDTH / 2) * j->zoom;
	j->offset_y = im - (my - HEIGHT / 2) * j->zoom;
}
