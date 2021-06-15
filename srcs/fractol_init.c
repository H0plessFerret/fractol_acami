/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:06:02 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 16:12:05 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractolFunctionInit(t_fractol *fractol)
{
	static const t_fractalInfo	fractalInfo[FRACTALS_SUPPORTED] = {
		[Mandelbrot] = {1.5, 2., -3., 1.5, mandelbrotEq},
		[Julia] = {1.5, 2., -3., 1.5, mandelbrotEq},
	};

	fractol->x_max = fractalInfo[fractol->fract_id].x_max_start;
	fractol->x_min = fractalInfo[fractol->fract_id].x_min_start;
	fractol->y_max = fractalInfo[fractol->fract_id].y_max_start;
	fractol->y_min = fractalInfo[fractol->fract_id].y_min_start;
	fractol->fractal_equation = fractalInfo[fractol->fract_id].fractal_equation;
}

void	fractolInit(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Fract-ol");
	if (fractol->window == NULL)
		panic(WINDOW_INIT_ERROR);
	fractol->image = mlx_new_image(fractol->mlx, fractol->width,
			fractol->height);
	if (fractol->image == NULL)
		panic(IMAGE_INIT_ERROR);
	fractol->data_addr = mlx_get_data_addr(fractol->image,
			&(fractol->bits_per_pixel), &(fractol->size_line),
			&(fractol->endian));
	fractolFunctionInit(fractol);
}
