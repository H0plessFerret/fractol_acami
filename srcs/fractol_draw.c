/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:25:26 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 21:02:46 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifdef MULTITHREAD_ON
# include <pthread.h>
#endif

static void	putPixel(t_fractol *fractol, int32_t x, int32_t y, int32_t colour)
{
	(void)fractol;
	(void)x;
	(void)y;
	(void)colour;
}

#ifdef MULTITHREAD_ON

static void	fractolDrawStrip(t_fractol *fractol, t_threadInfo *threadInfo)
{
	(void)fractol;
	(void)threadInfo;
}

void	fractolDraw(t_fractol *fractol)
{
	t_threadInfo	threadInfo[THREADS];

	(void)fractol;
	(void)threadInfo;
}

#else
void	fractolDraw(t_fractol *fractol)
{
	int32_t		x_curr;
	int32_t		y_curr;
	double		re_step;
	double		im_step;
	t_complex	point;

	re_step = (fractol->re_max - fractol->re_min) / fractol->width;
	im_step = (fractol->im_min - fractol->im_max) / fractol->height;
	point.imaginary = fractol->im_max;
	y_curr = 0;
	while (y_curr < fractol->height)
	{
		x_curr = 0;
		point.real = fractol->re_min;
		while (x_curr < fractol->width)
		{
			point.real += re_step;
			putPixel(fractol, x_curr, y_curr,
				generateColour(fractol->fractal_equation(fractol, &point)));
			++x_curr;
		}
		point.imaginary += im_step;
		++y_curr;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img, 0, 0);
}

#endif
