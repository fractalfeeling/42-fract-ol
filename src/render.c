/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:22 by lwee              #+#    #+#             */
/*   Updated: 2023/01/19 17:24:38 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	interpolate_color(int start_color, int end_color, double scale)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = (start_color >> 16) & 0xFF;
	start_rgb[1] = (start_color >> 8) & 0xFF;
	start_rgb[2] = (start_color) & 0xFF;
	end_rgb[0] = (end_color >> 16) & 0xFF;
	end_rgb[1] = (end_color >> 8) & 0xFF;
	end_rgb[2] = (end_color) & 0xFF;
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * scale + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * scale + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * scale + start_rgb[2];
	return (0x00 << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}

void	set_color_multiple(t_fractol *fractal, int colors[3], int n)
{
	int		i;
	int		j;
	int		x;
	double	scale;

	i = 0;
	x = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while ((i + j) < MAX_ITERATIONS && j < (MAX_ITERATIONS / (n - 1)))
		{
			scale = (double)j / (MAX_ITERATIONS / (n - 1));
			fractal->palette[i + j] = interpolate_color(colors[x],
					colors[x + 1], scale);
			j++;
		}
		x++;
		i += j;
	}
	fractal->palette[MAX_ITERATIONS - 1] = 0;
}

void	set_pixel_color(t_fractol *fractal, int x, int y, int color)
{
	fractal->buffer[x * 4 + y * WIDTH * 4] = (color);
	fractal->buffer[x * 4 + y * WIDTH * 4 + 1] = (color >> 8);
	fractal->buffer[x * 4 + y * WIDTH * 4 + 2] = (color >> 16);
	fractal->buffer[x * 4 + y * WIDTH * 4 + 3] = (color >> 24);
}

int	count_iterations(t_fractol *fractal, double pr, double pi)
{
	int	iter_count;

	if (fractal->type == 1)
		iter_count = mandelbrot(pr, pi);
	if (fractal->type == 2)
		iter_count = julia(fractal, pr, pi);
	if (fractal->type == 3)
		iter_count = mandelbox(fractal, pr, pi);
	return (iter_count);
}

void	render(t_fractol *fractal)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		iter_count;

	mlx_clear_window(fractal->mlx, fractal->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = (double)WIDTH / HEIGHT * (x - WIDTH / 2.0)
				/ (0.5 * fractal->zoom * WIDTH) + fractal->offset_x;
			pi = (y - HEIGHT / 2.0) / (0.5 * fractal->zoom * HEIGHT)
				+ fractal->offset_y;
			iter_count = count_iterations(fractal, pr, pi);
			set_pixel_color(fractal, x, y, fractal->palette[iter_count]);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
