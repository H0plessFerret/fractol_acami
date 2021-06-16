/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:55:00 by acami             #+#    #+#             */
/*   Updated: 2021/06/16 20:00:14 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_codes.h"
#include <stdio.h>

// Need to find a way to get rid of this ugly if else mountain :c
int32_t	keyPressHandler(int32_t key, t_fractol *fractol)
{
	if (key == KEYBOARD_ESC)
		closeWindow();
	if (key == KEYBOARD_A)
		translateFractal(-(fractol->re_max - fractol->re_min) / 32., 0.,
			fractol);
	else if (key == KEYBOARD_S)
		translateFractal(0., -(fractol->im_max - fractol->im_min) / 32.,
			fractol);
	else if (key == KEYBOARD_D)
		translateFractal((fractol->re_max - fractol->re_min) / 32., 0.,
			fractol);
	else if (key == KEYBOARD_W)
		translateFractal(0., (fractol->im_max - fractol->im_min) / 32.,
			fractol);
	else if (key == KEYBOARD_R)
	{
		fractolFunctionInit(fractol);
		fractolDraw(fractol);
	}
	return (0);
}

int32_t	buttonPressHandler(int32_t button, int x, int y, t_fractol *fractol)
{
	if (button == M_LMB)
		fractol->lmb_pressed = true;
	(void)fractol;
	printf("buttonPressHandler was called!\n");
	printf("button code: %d %d %d\n", button, x, y);
	return (0);
}

int32_t	buttonReleaseHandler(int32_t button, int x, int y, t_fractol *fractol)
{
	if (button == M_LMB)
		fractol->lmb_pressed = false;
	(void)fractol;
	printf("buttonReleaseHandler was called!\n");
	printf("button code: %d %d %d\n", button, x, y);
	return (0);
}

int32_t	motionHandler(int32_t x, int32_t y, t_fractol *fractol)
{
	if (fractol->lmb_pressed)
	{
		(void)y;
		printf("%lf\n", x * (fractol->re_max - fractol->re_min) / fractol->width);
	}
	return (0);
}
