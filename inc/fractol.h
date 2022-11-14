/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:39:28 by lwee              #+#    #+#             */
/*   Updated: 2022/11/14 22:22:52 by lwee             ###   ########.fr       */
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

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 24
# define MINUS 27
# define I 34
# define O 31

typedef struct s_fractol
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*buffer;
	int			type;
	double		zoom;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		offset_x;
	double		offset_y;
	double		kr;
	double		ki;
	int			*palette;
}	t_fractol;

void	init_fractal(t_fractol *fractal, int argc, char **argv);
int		interpolate_color(int start_color, int end_color, double scale);
void	set_color_mono(t_fractol *fractal, int color);
void	set_color_multiple(t_fractol *fractal, int color[3], int n);
void	set_pixel_color(t_fractol *fractal, int x, int y, int color);
void	render(t_fractol *fractal);
//int	key_event(t_fractol *fractal, int keycode)
int		key_event(int keycode, t_fractol *fractal);
int		mandelbrot(double cr, double ci);
int		julia(t_fractol *fractal, double zr, double zi);
#endif
