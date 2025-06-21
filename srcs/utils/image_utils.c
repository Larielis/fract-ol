/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:19:37 by racamach          #+#    #+#             */
/*   Updated: 2025/06/19 15:53:21 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define DARK_BLUE   0x000764FFu	     /* #000764FF */
#define BRIGHT_BLUE 0x206BCBFFu      /* #206BCBFF */
#define PALE_CYAN   0xEDFFFFFFu      /* #EDFFFFFF */
#define ORANGE      0xFFAA00FFu      /* #FFAA00FF */
#define BLACK       0x000000FFu      /* #000000FF */

#define MIDNIGHT    0x001F3FFFu      /* #001F3FFF */
#define INDIGO      0x4B0082FFu      /* #4B0082FF */
#define CRIMSON     0xDC143CFFu      /* #DC143CFF */
#define GOLD        0xFFD700FFu      /* #FFD700FF */

void	init_gradient_mandelbrot(uint32_t *gradient)
{
	const uint32_t	colors[] = {DARK_BLUE, BRIGHT_BLUE, PALE_CYAN, ORANGE,
		BLACK};
	const int		size = (sizeof(colors) / sizeof(*colors)) - 1;
	int				p;
	int				j;
	int				i;

	i = 0;
	p = 0;
	while (p < size)
	{
		j = 0;
		while (j < GRADIENT_SIZE / size)
		{
			gradient[i] = interpolate(colors[p], colors[p + 1], (double)j
					/ (GRADIENT_SIZE / size));
			i++;
			j++;
		}
		p++;
	}
}

void	init_gradient_julia(uint32_t *gradient)
{
	const uint32_t	colors[] = {MIDNIGHT, INDIGO, CRIMSON, ORANGE,
		GOLD};
	const int		size = (sizeof(colors) / sizeof(*colors)) - 1;
	int				p;
	int				j;
	int				i;

	i = 0;
	p = 0;
	while (p < size)
	{
		j = 0;
		while (j < GRADIENT_SIZE / size)
		{
			gradient[i] = interpolate(colors[p], colors[p + 1], (double)j
					/ (GRADIENT_SIZE / size));
			i++;
			j++;
		}
		p++;
	}
}

void	set_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	size_t	idx;

	if (x < 0 || y < 0 || x >= (int)img->width || y >= (int)img->height)
		return ;
	idx = (y * img->width + x) * 4;
	img->pixels[idx + 0] = (color >> 24) & 0xFF;
	img->pixels[idx + 1] = (color >> 16) & 0xFF;
	img->pixels[idx + 2] = (color >> 8) & 0xFF;
	img->pixels[idx + 3] = color & 0xFF;
}
