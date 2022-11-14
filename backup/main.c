/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:25:16 by lwee              #+#    #+#             */
/*   Updated: 2022/11/14 14:51:42 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractal;
	int			type;	

	if (argc < 2)
		exit(1);
	type = which_fractal(argv[1]);
	init_fractal(&fractal, type, argc, argv);
	draw_fractal(&fractal, type);
	mlx_key_hook(fractal.window, key_event, &fractal);
	mlx_loop(fractal.mlx);
}
