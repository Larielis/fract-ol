/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:40:55 by racamach          #+#    #+#             */
/*   Updated: 2025/06/21 15:28:36 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1024
# define HEIGHT 768
# define MAX_ITER 5000
# define GRADIENT_SIZE 256
# define PAN_STEP 40

typedef enum e_fractal
{
	MANDELBROT,
	JULIA
}				t_fractal;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_mandelbrot
{
	double		zoom;
	double		offset_x;
	double		offset_y;
	uint32_t	gradient[GRADIENT_SIZE];
}				t_mandelbrot;

typedef struct s_julia
{
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		re;
	double		im;
	uint32_t	gradient[GRADIENT_SIZE];
}				t_julia;

typedef struct s_vars
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	bool		need_redraw;
	t_fractal	fractal;
	void		*ctx;
}				t_vars;

uint32_t		rgb(uint8_t r, uint8_t g, uint8_t b);
uint32_t		interpolate(uint32_t c1, uint32_t c2, double t);
void			init_gradient_mandelbrot(uint32_t *gradient);
void			init_gradient_julia(uint32_t *gradient);
void			set_pixel(mlx_image_t *img, int x, int y, uint32_t color);
void			render_mandelbrot(t_vars *vars);
void			render_julia(t_vars *vars);

bool			setup_context(t_vars *vars, int argc, char **argv);
bool			setup_window(t_vars *vars);
void			setup_hooks(t_vars *vars);
void			cleanup(t_vars *vars);
void			print_usage(char *prog);

void			*init_mandelbrot(void);
void			*init_julia(double re, double im);

void			mandelbrot_scroll(t_mandelbrot *m, int32_t mx, int32_t my,
					double ydelta);
void			julia_scroll(t_julia *j, int32_t mx, int32_t my, double ydelta);

void			mandelbrot_pan(t_mandelbrot *m, mlx_key_data_t key);
void			julia_pan(t_julia *j, mlx_key_data_t key);

bool			handle_mandelbrot(t_vars *vars);
bool			handle_julia(t_vars *vars, int argc, char **argv);

int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memset(void *s, int c, size_t n);
size_t			ft_strlen(const char *s);
double			ft_atof(const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);
#endif