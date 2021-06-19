/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:25:26 by acami             #+#    #+#             */
/*   Updated: 2021/06/19 20:11:49 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifdef MULTITHREAD_ON
# include <error_messages.h>
# include <pthread.h>
#endif

static void	putPixel(t_fractol *fractol, int32_t x, int32_t y, int32_t colour)
{
	char	*dst;

	dst = fractol->data_addr + (y * fractol->line_len + x * (fractol->bpp / 8));
	*(uint32_t *)dst = colour;
}

#ifdef MULTITHREAD_ON
static void	iterateOverStrip(t_threadInfo *thread_info, t_fractol *fractol,
t_complex *step, t_complex *point)
{
	int32_t		x_curr;
	int32_t		y_curr;

	y_curr = thread_info->start_line;
	while (y_curr < thread_info->end_line)
	{
		x_curr = 0;
		point->real = fractol->re_min;
		while (x_curr < fractol->width)
		{
			putPixel(fractol, x_curr, y_curr, generateColour(
					fractol->fractal_equation(fractol, *point),
					fractol->max_iterations, fractol->colour_scheme,
					thread_info->random_factor));
			point->real += step->real;
			++x_curr;
		}
		point->imaginary += step->imaginary;
		++y_curr;
	}
}

static void	fractolDrawStrip(t_threadInfo *thread_info)
{
	t_complex	step;
	t_fractol	*fractol;
	t_complex	point;

	fractol = thread_info->fractol;
	point.imaginary = -1. *thread_info->start_line * (fractol->im_max
			- fractol->im_min) / fractol->height + fractol->im_max;
	step.real = (fractol->re_max - fractol->re_min) / fractol->width;
	step.imaginary = (fractol->im_min - fractol->im_max) / fractol->height;
	iterateOverStrip(thread_info, fractol, &step, &point);
}

void	fractolDraw(t_fractol *fractol)
{
	t_threadInfo	thread_info[THREADS];
	int32_t			count;
	int32_t			rand_param;
	time_t			t;

	srand((unsigned)time(&t));
	rand_param = rand();
	count = 0;
	while (count < THREADS)
	{
		thread_info[count].fractol = fractol;
		thread_info[count].random_factor = rand_param;
		thread_info[count].start_line = count * (fractol->height / THREADS);
		thread_info[count].end_line = (count + 1) * (fractol->height / THREADS);
		if (pthread_create(&(thread_info[count].thread), NULL,
				(void *(*)(void *))fractolDrawStrip,
			(void *)(thread_info + count)) != 0)
			panic(THREAD_CREATE_ERROR);
		++count;
	}
	while (count > 0)
	{
		--count;
		if (pthread_join(thread_info[count].thread, NULL))
			panic(THREAD_JOIN_ERROR);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img, 0, 0);
}

#else
void	fractolDraw(t_fractol *fractol)
{
	int32_t		x_curr;
	int32_t		y_curr;
	t_complex	step;
	t_complex	point;

	step.real = (fractol->re_max - fractol->re_min) / fractol->width;
	step.imaginary = (fractol->im_min - fractol->im_max) / fractol->height;
	point.imaginary = fractol->im_max;
	y_curr = 0;
	while (y_curr < fractol->height)
	{
		x_curr = 0;
		point.real = fractol->re_min;
		while (x_curr < fractol->width)
		{
			putPixel(fractol, x_curr, y_curr, generateColour(
					fractol->fractal_equation(fractol, point),
					fractol->max_iterations, fractol->colour_scheme, 12345));
			point.real += step.real;
			++x_curr;
		}
		point.imaginary += step.imaginary;
		++y_curr;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img, 0, 0);
}

#endif
