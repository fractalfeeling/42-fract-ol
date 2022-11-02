/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:39:28 by lwee              #+#    #+#             */
/*   Updated: 2022/11/02 18:20:27 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../inc/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

# define WIDTH 1200
# define HEIGHT 800
# define TITLE "Fract-ol"
# define MAX_ITERATIONS 80

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	double	zoom;
	double	move_x;
	double	move_y;
	double	kr;
	double	ki;
}	t_fractol;

int		which_fractal(char *name);
void	init_fractal(t_fractol *fractal, int type, int argc, char **argv);
void	draw_fractal(t_fractol *fractal, int type);
void	mandelbrot(t_fractol *fractal, int x, int y, double cr, double ci);
void	julia(t_fractol *fractal, int x, int y, double zr, double zi);
#endif
