/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:06:02 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 20:59:48 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_codes.h"
#include <stdio.h>

static void	fractolFunctionInit(t_fractol *fractol)
{
	static const t_fractalInfo	fractalInfo[FRACTALS_SUPPORTED] = {
		[Mandelbrot] = {1.5, 2., -3., 1.5, mandelbrotEq, {0., 0.}},
		[Julia] = {1.5, 2., -3., 1.5, juliaEq, {0., 0.}}
	};

	fractol->re_max = fractalInfo[fractol->fract_id].re_max_start;
	fractol->re_min = fractalInfo[fractol->fract_id].re_min_start;
	fractol->re_max = fractalInfo[fractol->fract_id].re_max_start;
	fractol->re_min = fractalInfo[fractol->fract_id].re_min_start;
	fractol->fractal_equation = fractalInfo[fractol->fract_id].fractal_equation;
	fractol->extra_param = fractalInfo[fractol->fract_id].extra_param_start;
}

static void	fractolHooksInit(t_fractol *fractol)
{
	mlx_hook(fractol->window, DESTROYNOTIFY, NOEVENTMASK, closeWindow, fractol);
	mlx_hook(fractol->window, KEYPRESS, NOEVENTMASK, keyPressHandler, fractol);
	mlx_hook(fractol->window, BUTTONPRESS, NOEVENTMASK, buttonPressHandler,
		fractol);
	mlx_hook(fractol->window, BUTTONRELEASE, NOEVENTMASK,
		buttonReleaseHandler, fractol);
	mlx_hook(fractol->window, MOTIONNOTIFY, NOEVENTMASK, motionHandler,
		fractol);
}

void	fractolInit(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, fractol->width,
			fractol->height, "Fract-ol");
	if (fractol->window == NULL)
		panic(WINDOW_INIT_ERROR);
	fractol->img = mlx_new_image(fractol->mlx, fractol->width,
			fractol->height);
	if (fractol->img == NULL)
		panic(IMAGE_INIT_ERROR);
	fractol->data_addr = mlx_get_data_addr(fractol->img,
			&(fractol->bits_per_pixel), &(fractol->size_line),
			&(fractol->endian));
	fractolFunctionInit(fractol);
	fractolHooksInit(fractol);
}
