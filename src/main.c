/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:22:57 by lwee              #+#    #+#             */
/*   Updated: 2022/11/15 22:09:56 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	which_fractal(t_fractol *fractal, int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		ft_tolower(argv[1][i++]);
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		fractal->type = 1;
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
		fractal->type = 2;
	else if (ft_strncmp(argv[1], "mandelbox", 10) == 0)
		fractal->type = 3;
	else
		exit(1);
	if (argc < 2 || argc == 3 || (argc == 4 && fractal->type != 2) || argc > 4)
	{
		printf("error");
		exit(1);
	}
	fractal->argc = argc;
	if (fractal->type == 2 && argc == 4)
	{
		fractal->kr = ft_atoi(argv[2]);
		fractal->ki = ft_atoi(argv[3]);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	fractal;

	which_fractal(&fractal, argc, argv);
	init_image(&fractal);
	init_vars(&fractal);
	render(&fractal);
	mlx_key_hook(fractal.win, key_event, &fractal);
	mlx_mouse_hook(fractal.win, mouse_event, &fractal);
	mlx_loop(fractal.mlx);
}
