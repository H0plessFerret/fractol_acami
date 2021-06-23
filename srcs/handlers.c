/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:55:00 by acami             #+#    #+#             */
/*   Updated: 2021/06/23 16:56:33 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_codes.h"

void	keyPressHandler(int32_t key, t_fractol *fractol)
{
	static const t_keyAction	key_action_func[MAX_KEYCODE] = {
		[KEYBOARD_W] = translateFractal,
		[KEYBOARD_A] = translateFractal,
		[KEYBOARD_S] = translateFractal,
		[KEYBOARD_D] = translateFractal,
		[KEYBOARD_R] = resetFractal,
		[KEYBOARD_ESC] = closeWindow,
		[KEYBOARD_PLUS] = changeIterations,
		[KEYBOARD_MINUS] = changeIterations,
		[KEYBOARD_Q] = updateFractal,
		[KEYBOARD_UP] = changeColour,
		[KEYBOARD_DOWN] = changeColour
	};

	if (key_action_func[key] != NULL)
	{
		key_action_func[key](key, fractol);
		fractolDraw(fractol);
	}
}

void	buttonPressHandler(int32_t button, int x, int y, t_fractol *fractol)
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
		zoomFractal(x, y, button, fractol);
	}
	else if (button == M_SCROLL_DOWN)
	{
		fractol->max_iterations += fractol->iteration_change;
		zoomFractal(x, y, button, fractol);
	}
}

void	buttonReleaseHandler(int32_t button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == M_LMB)
		fractol->lmb_pressed = false;
}

void	motionHandler(int32_t x, int32_t y, t_fractol *fractol)
{
	if (fractol->lmb_pressed == false)
		return ;
	setComplex(&(fractol->extra_param),
		(double)x * (fractol->re_max - fractol->re_min) / fractol->width
		+ fractol->re_min,
		(double)y * -1. * (fractol->im_max - fractol->im_min)
		/ fractol->height + fractol->im_max);
	fractolDraw(fractol);
}
