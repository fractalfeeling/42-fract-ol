/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:23:28 by lwee              #+#    #+#             */
/*   Updated: 2022/11/14 13:50:54 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	which_fractal(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		ft_tolower(name[i++]);
	if (ft_strncmp(name, "mandelbrot", 11) == 0)
		return (0);
	else if (ft_strncmp(name, "julia", 6) == 0)
		return (1);
	else
		exit(1);
}

void	init_fractal(t_fractol *fractal, int type, int argc, char **argv)
{
	int		bits_per_pixel;
	int		line_bytes;
	int		endian;

	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, TITLE);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->buffer = mlx_get_data_addr(fractal->img, &bits_per_pixel, &line_bytes, &endian);
	fractal->zoom = 1.0;
	if (type == 0)
		fractal->move_x = -0.5;
	else
		fractal->move_x = 0.0;
	fractal->move_y = 0.0;
	if (type == 1 && argc > 2)
	{
		fractal->kr = ft_atoi(argv[1]);
		fractal->ki = ft_atoi(argv[2]);
	}
	else
	{
		//fractal->kr = (double)rand() / (double)RAND_MAX * 2.0 - 1.0;
		//fractal->ki = (double)rand() / (double)RAND_MAX * 2.0 - 1.0;
		fractal->kr = -0.76667;
		fractal->ki = -0.09000;
	}
}

void	set_pixel_color(t_fractol *fractal, int x, int y, int color)
{
	fractal->buffer[x * 4 + y * WIDTH * 4] = color;
	fractal->buffer[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	fractal->buffer[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	fractal->buffer[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

void	draw_fractal(t_fractol *fractal, int type)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	mlx_clear_window(fractal->mlx, fractal->window);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = 1.5 * (x - WIDTH / 2.0) / (0.5 * fractal->zoom * WIDTH) + fractal->move_x;
			pi = (y - HEIGHT / 2.0) / (0.5 * fractal->zoom * HEIGHT) + fractal->move_y;
			if (type == 0)
				mandelbrot(fractal, x, y, pr, pi);
			else if (type == 1)
				julia(fractal, x, y, pr, pi);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img, 0, 0);
}
