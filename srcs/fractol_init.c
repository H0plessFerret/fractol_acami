/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:06:02 by acami             #+#    #+#             */
/*   Updated: 2021/06/23 16:47:03 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_codes.h"

static void	fractolHooksInit(t_fractol *fractol)
{
	mlx_hook(fractol->window, DESTROYNOTIFY, NOEVENTMASK,
		(int (*)())closeWindow, NULL);
	mlx_hook(fractol->window, KEYPRESS, NOEVENTMASK,
		(int (*)())keyPressHandler, fractol);
	mlx_hook(fractol->window, BUTTONPRESS, NOEVENTMASK,
		(int (*)())buttonPressHandler, fractol);
	mlx_hook(fractol->window, BUTTONRELEASE, NOEVENTMASK,
		(int (*)())buttonReleaseHandler, fractol);
	mlx_hook(fractol->window, MOTIONNOTIFY, NOEVENTMASK,
		(int (*)())motionHandler, fractol);
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
		[Mandelbrot] = {-2., 1., -1.5, 1.5, mandelbrotEq, 50, 7, {0., 0.},
			DefaultColour},
		[Julia] = {-2., 2., -2., 2., juliaEq, 50, 6, {-0.89, -0.235000},
			DefaultColour},
		[BurningShip] = {-2., 1., -1., 2., burningShipEq, 50, 7, {0., 0.},
			DefaultColour}
	};
	t_fractalId					curr_id;

	curr_id = (fractol->fract_id) % FRACTALS_SUPPORTED;
	fractol->re_min = frac_info[curr_id].re_min_start;
	fractol->re_max = frac_info[curr_id].re_max_start;
	fractol->im_min = frac_info[curr_id].im_min_start;
	fractol->im_max = frac_info[curr_id].im_max_start;
	fractol->fractal_equation = frac_info[curr_id].fractal_equation;
	fractol->max_iterations = frac_info[curr_id].max_iterations_start;
	fractol->iteration_change = frac_info[curr_id].iteration_change;
	fractol->extra_param = frac_info[curr_id].extra_param_start;
	fractol->colour_scheme = frac_info[curr_id].colour_scheme_start;
}
