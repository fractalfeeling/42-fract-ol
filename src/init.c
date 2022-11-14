/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:15:14 by lwee              #+#    #+#             */
/*   Updated: 2022/11/14 22:11:18 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	which_fractal(t_fractol *fractal, char *name)
{
	int	i;

	i = 0;
	while (name[i])
		ft_tolower(name[i++]);
	if (ft_strncmp(name, "mandelbrot", 11) == 0)
		fractal->type = 1;
	else if (ft_strncmp(name, "julia", 6) == 0)
		fractal->type = 2;
	else
		exit(1);
}

static void	init_image(t_fractol *fractal)
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, TITLE);
	fractal->palette = ft_calloc(MAX_ITERATIONS + 1, sizeof(int));
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->buffer = mlx_get_data_addr(fractal->image, &bits_per_pixel, &line_length, &endian);
	printf("%d\n", bits_per_pixel);
	printf("%d\n", line_length);
	printf("%d\n", endian);
}

static void	init_position(t_fractol *fractal)
{
	if (fractal->type == 1)
	{
		fractal->min_r = -4.0;
		fractal->max_r = 4.0;
		fractal->min_i = -4.0;
		fractal->max_i = fractal->min_i + (fractal->max_r - fractal->min_r) * HEIGHT / WIDTH;
	}
	if (fractal->type == 2)
	{
		fractal->min_r = -2.0;
		fractal->max_r = 2.0;
		fractal->min_i = -2.0;
		fractal->max_i = fractal->max_i + (fractal->max_r - fractal->min_r) * HEIGHT / WIDTH;
	}
	fractal->zoom = 1.0;
	if (fractal->type == 1)
		fractal->offset_x = -0.5;
	else
		fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
}

static void	init_k_number(t_fractol *fractal, int argc, char **argv)
{
	if (fractal->type == 1 && argc > 2)
	{
		fractal->kr = ft_atoi(argv[2]);
		fractal->ki = ft_atoi(argv[3]);
	}
	else
	{
		//fractal->kr = (double)rand() / (double)RAND_MAX * 2.0 - 1.0;
		//fractal->ki = (double)rand() / (double)RAND_MAX * 2.0 - 1.0;
		fractal->kr = -0.76667;
		fractal->ki = -0.09000;
	}
}

void	init_fractal(t_fractol *fractal, int argc, char **argv)
{
	int	colors[3] = {0x000000, 0x00FFFF, 0xFFFFFF};

	which_fractal(fractal, argv[1]);
	init_image(fractal);
	init_position(fractal);
	init_k_number(fractal, argc, argv);
	set_color_multiple(fractal, colors, 3);
	//set_color_mono(fractal, 0x00FFFF);
}
