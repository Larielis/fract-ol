/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pan.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:58:07 by racamach          #+#    #+#             */
/*   Updated: 2025/06/16 11:07:10 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_pan(t_mandelbrot *m, mlx_key_data_t key)
{
	if (key.key == MLX_KEY_LEFT)
		m->offset_x -= PAN_STEP * m->zoom;
	if (key.key == MLX_KEY_RIGHT)
		m->offset_x += PAN_STEP * m->zoom;
	if (key.key == MLX_KEY_UP)
		m->offset_y -= PAN_STEP * m->zoom;
	if (key.key == MLX_KEY_DOWN)
		m->offset_y += PAN_STEP * m->zoom;
}

void	julia_pan(t_julia *j, mlx_key_data_t key)
{
	if (key.key == MLX_KEY_LEFT)
		j->offset_x -= PAN_STEP * j->zoom;
	if (key.key == MLX_KEY_RIGHT)
		j->offset_x += PAN_STEP * j->zoom;
	if (key.key == MLX_KEY_UP)
		j->offset_y -= PAN_STEP * j->zoom;
	if (key.key == MLX_KEY_DOWN)
		j->offset_y += PAN_STEP * j->zoom;
}
