/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:14:02 by lwee              #+#    #+#             */
/*   Updated: 2022/11/14 13:45:43 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *fractal, int x, int y, double cr, double ci)
{
	double	zr;
	double	zi;
	double	tmp;
	int	i;
	int	in_set;

	zr = 0;
	zi = 0;
	i = -1;
	in_set = 1;
	while (++i < MAX_ITERATIONS)
	{
		tmp = zr * zr - zi * zi + cr;
		zi  = 2 * zr * zi + ci;
		zr = tmp;
		if ((zr * zr + zi * zi) > 4.0)
		{
			in_set = 0;
			break ;
		}
	}
	if (in_set == 1)
		set_pixel_color(fractal, x, y, 0x00000000);
		//mlx_pixel_put(fractal->mlx, fractal->window, x, y, 0x000000);
	else
		set_pixel_color(fractal, x, y, 0x00FFFFFF);
		//mlx_pixel_put(fractal->mlx, fractal->window, x, y, 0xFFFFFF);
}
