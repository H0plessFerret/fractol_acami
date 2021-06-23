/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:57:28 by acami             #+#    #+#             */
/*   Updated: 2021/06/23 16:53:24 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_codes.h"

void	translateFractal(int32_t key, t_fractol *fractol)
{
	double	re_shift;
	double	im_shift;

	re_shift = (fractol->re_max - fractol->re_min) / 128.;
	im_shift = (fractol->im_max - fractol->im_min) / 128.;
	if (key == KEYBOARD_W)
	{
		re_shift = 0;
		im_shift = -im_shift;
	}
	else if (key == KEYBOARD_A)
		im_shift = 0;
	else if (key == KEYBOARD_S)
		re_shift = 0;
	else if (key == KEYBOARD_D)
	{
		re_shift = -re_shift;
		im_shift = 0;
	}
	fractol->re_min += re_shift;
	fractol->re_max += re_shift;
	fractol->im_max += im_shift;
	fractol->im_min += im_shift;
}

void	changeIterations(int32_t key, t_fractol *fractol)
{
	if (key == KEYBOARD_PLUS)
		fractol->max_iterations = fractol->max_iterations * 14 / 10;
	else if (key == KEYBOARD_MINUS)
		fractol->max_iterations = fractol->max_iterations * 10 / 14;
}

void	changeColour(int32_t key, t_fractol *fractol)
{
	if (key == KEYBOARD_UP)
		fractol->colour_scheme = (fractol->colour_scheme
				+ 1) % COLOURS_SUPPORTED;
	else if (key == KEYBOARD_DOWN)
		fractol->colour_scheme = (fractol->colour_scheme
				+ COLOURS_SUPPORTED - 1) % COLOURS_SUPPORTED;
}

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int32_t	zoomFractal(int32_t x, int32_t y, int32_t button, t_fractol *fractol)
{
	t_complex	mouse_pos;
	double		interpolation;

	setComplex(&(mouse_pos),
		(double)x * (fractol->re_max - fractol->re_min) / fractol->width
		+ fractol->re_min,
		(double)y * -1. * (fractol->im_max - fractol->im_min)
		/ fractol->height + fractol->im_max);
	interpolation = 0;
	if (button == M_SCROLL_UP)
		interpolation = 1.0 / 0.8;
	else if (button == M_SCROLL_DOWN)
		interpolation = 1.0 / 1.2;
	fractol->re_min = interpolate(mouse_pos.real, fractol->re_min,
			interpolation);
	fractol->re_max = interpolate(mouse_pos.real, fractol->re_max,
			interpolation);
	fractol->im_min = interpolate(mouse_pos.imaginary, fractol->im_min,
			interpolation);
	fractol->im_max = interpolate(mouse_pos.imaginary, fractol->im_max,
			interpolation);
	fractolDraw(fractol);
	return (0);
}
