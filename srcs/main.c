/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:22:35 by racamach          #+#    #+#             */
/*   Updated: 2025/06/17 17:25:52 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(char *prog)
{
	write(1, "Usage: ", 7);
	write(1, prog, ft_strlen(prog));
	write(1, " mandelbrot | julia [re im]\n", 28);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2)
	{
		print_usage(argv[0]);
		return (EXIT_FAILURE);
	}
	ft_memset(&vars, 0, sizeof(vars));
	if (!setup_context(&vars, argc, argv))
		return (EXIT_FAILURE);
	if (!setup_window(&vars))
		return (EXIT_FAILURE);
	setup_hooks(&vars);
	mlx_loop(vars.mlx);
	cleanup(&vars);
	return (EXIT_SUCCESS);
}
