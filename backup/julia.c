/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:56:19 by lwee              #+#    #+#             */
/*   Updated: 2022/11/14 13:50:38 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *fractal, int x, int y, double zr, double zi)
{
	double	tmp;
	int	i;
	int	in_set;

	i = -1;
	in_set = 1;
	while (++i < MAX_ITERATIONS)
	{
		tmp = zr * zr - zi * zi + fractal->kr;
		zi  = 2 * zr * zi + fractal->ki;
		zr = tmp;
		if ((zr * zr + zi * zi) > 4.0)
		{
			in_set = 0;
			break ;
		}
	}
	if (in_set == 1)
		set_pixel_color(fractal, x, y, 0x000000);
	else
		set_pixel_color(fractal, x, y, 0xFFFFFF);
}
