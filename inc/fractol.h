/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:39:28 by lwee              #+#    #+#             */
/*   Updated: 2022/11/15 22:08:18 by lwee             ###   ########.fr       */
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
# define MAX_ITERATIONS 42

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 24
# define MINUS 27
# define W 13
# define S 1
# define A 0
# define D 2
# define I 34
# define O 31
# define R 15
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define RIGHT_CLICK 1

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*buffer;
	int			type;
	int			argc;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		kr;
	double		ki;
	double		sx;
	double		rx;
	double		fx;
	int			*palette;
}	t_fractol;

void	init_image(t_fractol *fractal);
void	init_vars(t_fractol *fractal);
int		interpolate_color(int start_color, int end_color, double scale);
void	set_color_mono(t_fractol *fractal, int color);
void	set_color_multiple(t_fractol *fractal, int color[3], int n);
void	set_pixel_color(t_fractol *fractal, int x, int y, int color);
void	render(t_fractol *fractal);
int		key_event(int keycode, t_fractol *fractal);
int		mouse_event(int keycode, int x, int y, t_fractol *fractal);
int		mandelbrot(double cr, double ci);
int		julia(t_fractol *fractal, double zr, double zi);
int		mandelbox(t_fractol *fractal, double cr, double ci);
#endif
