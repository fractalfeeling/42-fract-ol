/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:03:53 by lwee              #+#    #+#             */
/*   Updated: 2022/11/15 20:39:25 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	exit_fractol(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
	exit(1);
}

int	key_event(int keycode, t_fractol *fractal)
{
	if (keycode == ESC)
		exit_fractol(fractal);
	if (keycode == UP || keycode == W)
		fractal->offset_y -= 0.168 / fractal->zoom;
	if (keycode == DOWN || keycode == S)
		fractal->offset_y += 0.168 / fractal->zoom;
	if (keycode == LEFT || keycode == A)
		fractal->offset_x -= 0.168 / fractal->zoom;
	if (keycode == RIGHT || keycode == D)
		fractal->offset_x += 0.168 / fractal->zoom;
	if (keycode == PLUS || keycode == I)
		fractal->zoom *= 1.37;
	if (keycode == MINUS || keycode == O)
		fractal->zoom /= 1.37;
	if (keycode == R)
		init_vars(fractal);
	render(fractal);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *fractal)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	if (keycode == SCROLL_UP)
	{
		fractal->zoom *= 1.37;
		fractal->offset_x += (double)x / WIDTH / fractal->zoom;
		fractal->offset_y += (double)y / HEIGHT / fractal->zoom;
	}
	if (keycode == SCROLL_DOWN)
	{
		fractal->zoom /= 1.37;
		fractal->offset_x += (double)x / WIDTH / fractal->zoom;
		fractal->offset_y += (double)y / HEIGHT / fractal->zoom;
	}
	if (keycode == RIGHT_CLICK)
	{
		fractal->offset_x += (double)x / WIDTH / fractal->zoom * 2.0;
		fractal->offset_y += (double)y / HEIGHT / fractal->zoom * 2.0;
	}
	render(fractal);
	return (0);
}
