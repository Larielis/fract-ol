/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:44:23 by racamach          #+#    #+#             */
/*   Updated: 2025/06/16 21:20:23 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ALPHA_VALUE 0xFFu

static uint8_t	get_component(uint32_t c, uint8_t shift)
{
	return ((c >> shift) & 0xFF);
}

uint32_t	rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 24 | g << 16 | b << 8 | ALPHA_VALUE);
}

uint32_t	interpolate(uint32_t c1, uint32_t c2, double t)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = get_component(c1, 24) + (get_component(c2, 24) - get_component(c1, 24))
		* t;
	g = get_component(c1, 16) + (get_component(c2, 16) - get_component(c1, 16))
		* t;
	b = get_component(c1, 8) + (get_component(c2, 8) - get_component(c1, 8))
		* t;
	return (rgb(r, g, b));
}
