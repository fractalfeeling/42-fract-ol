/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:03:58 by lwee              #+#    #+#             */
/*   Updated: 2022/11/15 22:04:44 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	box_fold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

/* mandelbox:
*	Checks whether a complex number is part of the Mandelbox set or not.
*	Takes as parameters the real and imaginary coordinates of a point,
*	converted previously from a pixel's coordinates.
*	Returns the number of iterations before the number escapes 
*	the Mandelbox set, which can then be used to determine coloring.
*/
int	mandelbox(t_fractol *fractal, double cr, double ci)
{
	int		n;
	double	vr;
	double	vi;
	double	mag;

	vr = cr;
	vi = ci;
	mag = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{		
		vr = fractal->fx * box_fold(vr);
		vi = fractal->fx * box_fold(vi);
		mag = sqrt(vr * vr + vi * vi);
		vr = vr * fractal->sx * ball_fold(fractal->rx, mag) + cr;
		vi = vi * fractal->sx * ball_fold(fractal->rx, mag) + ci;
		if (sqrt(mag) > 2)
			break ;
		n++;
	}
	return (n);
}
