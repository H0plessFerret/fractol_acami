/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:06:02 by acami             #+#    #+#             */
/*   Updated: 2021/06/18 18:17:37 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_codes.h"

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
			&(fractol->bpp), &(fractol->line_len),
			&(fractol->endian));
	fractol->lmb_pressed = false;
	fractolFunctionInit(fractol);
	fractolHooksInit(fractol);
}

void	fractolFunctionInit(t_fractol *fractol)
{
	static const t_fractalInfo	frac_info[FRACTALS_SUPPORTED] = {
		[Mandelbrot] = {-2., 1., -1.5, 1.5, mandelbrotEq, 50, 7, {0., 0.}},
		[Julia] = {-2., 2., -2., 2., juliaEq, 50, 6, {-0.89, -0.235000}}
	};

	fractol->re_min = frac_info[fractol->fract_id].re_min_start;
	fractol->re_max = frac_info[fractol->fract_id].re_max_start;
	fractol->im_min = frac_info[fractol->fract_id].im_min_start;
	fractol->im_max = frac_info[fractol->fract_id].im_max_start;
	fractol->fractal_equation = frac_info[fractol->fract_id].fractal_equation;
	fractol->max_iterations = frac_info[fractol->fract_id].max_iterations;
	fractol->iteration_change = frac_info[fractol->fract_id].iteration_change;
	fractol->extra_param = frac_info[fractol->fract_id].extra_param_start;
}
