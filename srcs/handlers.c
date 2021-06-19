/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:55:00 by acami             #+#    #+#             */
/*   Updated: 2021/06/19 17:12:27 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_codes.h"

// Need to find a way to get rid of this ugly if else mountain :c
int32_t	keyPressHandler(int32_t key, t_fractol *fractol)
{
	if (key == KEYBOARD_ESC)
		closeWindow();
	if (key == KEYBOARD_A)
		translateFractal(-(fractol->re_max - fractol->re_min) / 128., 0.,
			fractol);
	else if (key == KEYBOARD_S)
		translateFractal(0., -(fractol->im_max - fractol->im_min) / 128.,
			fractol);
	else if (key == KEYBOARD_D)
		translateFractal((fractol->re_max - fractol->re_min) / 128., 0.,
			fractol);
	else if (key == KEYBOARD_W)
		translateFractal(0., (fractol->im_max - fractol->im_min) / 128.,
			fractol);
	else if (key == KEYBOARD_R)
	{
		fractolFunctionInit(fractol);
		fractolDraw(fractol);
	}
	else if (key == KEYBOARD_PLUS)
	{
		fractol->max_iterations = fractol->max_iterations * 14 / 10;
		fractolDraw(fractol);
	}
	else if (key == KEYBOARD_MINUS)
	{
		fractol->max_iterations = fractol->max_iterations * 10 / 14;
		fractolDraw(fractol);
	}
	else if (key == KEYBOARD_UP)
	{
		fractol->colour_scheme = (fractol->colour_scheme + 1) % COLOUR_FUNCS;
		fractolDraw(fractol);
	}
	else if (key == KEYBOARD_DOWN)
	{
		fractol->colour_scheme = (fractol->colour_scheme + COLOUR_FUNCS - 1)
			% COLOUR_FUNCS;
		fractolDraw(fractol);
	}
	return (0);
}

int32_t	buttonPressHandler(int32_t button, int x, int y, t_fractol *fractol)
{
	if (button == M_LMB)
	{
		fractol->lmb_pressed = true;
		setComplex(&(fractol->extra_param),
			(double)x * (fractol->re_max - fractol->re_min) / fractol->width
			+ fractol->re_min,
			(double)y * -1. * (fractol->im_max - fractol->im_min)
			/ fractol->height + fractol->im_max);
		fractolDraw(fractol);
	}
	else if (button == M_SCROLL_UP)
	{
		fractol->max_iterations -= fractol->iteration_change;
		zoomFractal(x, y, 0.8, fractol);
	}
	else if (button == M_SCROLL_DOWN)
	{
		fractol->max_iterations += fractol->iteration_change;
		zoomFractal(x, y, 1.2, fractol);
	}
	return (0);
}

int32_t	buttonReleaseHandler(int32_t button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == M_LMB)
		fractol->lmb_pressed = false;
	return (0);
}

int32_t	motionHandler(int32_t x, int32_t y, t_fractol *fractol)
{
	if (fractol->lmb_pressed)
	{
		setComplex(&(fractol->extra_param),
			(double)x * (fractol->re_max - fractol->re_min) / fractol->width
			+ fractol->re_min,
			(double)y * -1. * (fractol->im_max - fractol->im_min)
			/ fractol->height + fractol->im_max);
		fractolDraw(fractol);
	}
	return (0);
}
