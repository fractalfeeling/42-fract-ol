/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:15:14 by lwee              #+#    #+#             */
/*   Updated: 2022/11/15 23:06:02 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_image(t_fractol *fractal)
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, TITLE);
	fractal->palette = ft_calloc(MAX_ITERATIONS + 1, sizeof(int));
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->buffer = mlx_get_data_addr(fractal->img, &bits_per_pixel,
			&line_length, &endian);
	printf("BPC: %d\n", bits_per_pixel);
	printf("LL: %d\n", line_length);
	printf("EN: %d\n", endian);
}

void	init_vars(t_fractol *fractal)
{
	fractal->zoom = 1.0;
	if (fractal->type == 1)
		fractal->offset_x = -0.5;
	else
		fractal->offset_x = 0;
	fractal->offset_y = 0;
	if (fractal->type == 2 && fractal->argc != 4)
	{
		fractal->kr = (double)rand() / RAND_MAX * 2 - 1;
		fractal->ki = (double)rand() / RAND_MAX * 2 - 1;
	}
	if (fractal->type == 3)
	{
		fractal->sx = 2.0;
		fractal->rx = 0.5;
		fractal->fx = 1.0;
	}
	set_color_multiple(fractal, (int [3]){0x00000000, 0x0000FFFF, 0x00FFFFFF}, 3);
}
