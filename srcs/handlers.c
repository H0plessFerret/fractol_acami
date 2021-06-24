/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:55:00 by acami             #+#    #+#             */
/*   Updated: 2021/06/24 16:51:25 by acami            ###   ########.fr       */
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
	static const t_buttonAction	button_action_func[MAX_BUTTON] = {
		[M_LMB] = changeParam,
		[M_SCROLL_UP] = zoomFractal,
		[M_SCROLL_DOWN] = zoomFractal
	};

	if (button_action_func[button] != NULL)
	{
		button_action_func[button](x, y, button, fractol);
		fractolDraw(fractol);
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
	if (fractol->lmb_pressed == false || x < 0 || y < 0
		|| x > fractol->width || y >fractol->height)
		return ;
	setComplex(&(fractol->extra_param),
		(double)x * (fractol->re_max - fractol->re_min) / fractol->width
		+ fractol->re_min,
		(double)y * -1. * (fractol->im_max - fractol->im_min)
		/ fractol->height + fractol->im_max);
	fractolDraw(fractol);
}
