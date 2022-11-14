/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:03:53 by lwee              #+#    #+#             */
/*   Updated: 2022/11/14 15:03:59 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//int	key_event(t_fractol *fractal, int keycode)
int	key_event(int keycode, t_fractol *fractal)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fractal->mlx, fractal->img);
		mlx_destroy_window(fractal->mlx, fractal->window);
		free(fractal->mlx);
		exit(1);
	}
	if (keycode == UP)
		fractal->move_y -= 0.1;
	if (keycode == DOWN)
		fractal->move_y += 0.1;
	if (keycode == LEFT)
		fractal->move_x -= 0.1;
	if (keycode == RIGHT)
		fractal->move_x += 0.1;
	if (keycode == PLUS || keycode == I)
		fractal->zoom *= 1.2;
	if (keycode == MINUS || keycode == O)
		fractal->zoom /= 1.2;
	draw_fractal(fractal, 1);
	return (0);
}
