/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:20:42 by lwee              #+#    #+#             */
/*   Updated: 2022/11/14 17:24:35 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol *fractal, double zr, double zi)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = zr * zr - zi * zi + fractal->kr;
		zi = 2 * zr * zi + fractal->ki;
		zr = tmp;
		i++;
	}
	return (i);
}
