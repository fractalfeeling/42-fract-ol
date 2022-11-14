/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:03:53 by lwee              #+#    #+#             */
/*   Updated: 2022/11/14 17:28:26 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//int	key_event(t_fractol *fractal, int keycode)
int	key_event(int keycode, t_fractol *fractal)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fractal->mlx, fractal->image);
		mlx_destroy_window(fractal->mlx, fractal->window);
		free(fractal->mlx);
		exit(1);
	}
	if (keycode == UP)
		fractal->offset_y -= 0.1;
	if (keycode == DOWN)
		fractal->offset_y += 0.1;
	if (keycode == LEFT)
		fractal->offset_x -= 0.1;
	if (keycode == RIGHT)
		fractal->offset_x += 0.1;
	if (keycode == PLUS || keycode == I)
		fractal->zoom *= 1.2;
	if (keycode == MINUS || keycode == O)
		fractal->zoom /= 1.2;
	render(fractal);
	return (0);
}
