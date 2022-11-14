/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:22 by lwee              #+#    #+#             */
/*   Updated: 2022/11/14 22:24:29 by lwee             ###   ########.fr       */
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
	return (start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}

void	set_color_mono(t_fractol *fractal, int color)
{
	int		i;
	double	scale;
	int		color1;
	int		color2;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		if (i < MAX_ITERATIONS / 2)
		{
			scale = (double)i / (MAX_ITERATIONS / 2.0);
			color1 = 0x000000;
			color2 = color;
		}
		else
		{
			scale = ((double)i - MAX_ITERATIONS / 2.0) / (MAX_ITERATIONS / 2.0);
			color1 = color2;
			color2 = 0xFFFFFF;
		}
		fractal->palette[i] = interpolate_color(color1, color2, scale);
		i++;
	}
	fractal->palette[MAX_ITERATIONS] = 0;
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
			scale = (double)j / (MAX_ITERATIONS / (n - 1.0));
			fractal->palette[i + j] = interpolate_color(colors[x], colors[x + 1], scale);
			j++;
		}
		x++;
		i += j;
	}
	fractal->palette[MAX_ITERATIONS - 1] = 0;
}
void	set_pixel_color(t_fractol *fractal, int x, int y, int color)
{
	fractal->buffer[x * 4 + y * WIDTH * 4] = (color) & 0xFF;
	fractal->buffer[x * 4 + y * WIDTH * 4 + 1] = (color >> 8) & 0xFF;
	fractal->buffer[x * 4 + y * WIDTH * 4 + 2] = (color >> 16) & 0xFF;
	fractal->buffer[x * 4 + y * WIDTH * 4 + 3] = (color >> 24) & 0xFF;
}

void	render(t_fractol *fractal)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		iter_count;

	mlx_clear_window(fractal->mlx, fractal->window);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = 1.5 * (x - WIDTH / 2.0) / (0.5 * fractal->zoom * WIDTH)
				+ fractal->offset_x;
			pi = (y - HEIGHT / 2.0) / (0.5 * fractal->zoom * HEIGHT)
				+ fractal->offset_y;
			if (fractal->type == 1)
				iter_count = mandelbrot(pr, pi);
			if (fractal->type == 2)
				iter_count = julia(fractal, pr, pi);
			set_pixel_color(fractal, x, y, fractal->palette[iter_count]);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
}
