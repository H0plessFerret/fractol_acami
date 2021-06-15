/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:14:40 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 22:41:55 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	mandelbrotEq(const t_fractol *fractol, t_complex point)
{
	int32_t		iteration;
	double		re;
	double		im;
	t_complex	start;

	iteration = 0;
	start.real = point.real;
	start.imaginary = point.imaginary;
	while ((iteration < fractol->max_iterations) && (point.real * point.real + point.imaginary * point.imaginary <= 4.))
	{
		re = point.real;
		im = point.imaginary;
		point.real = re * re - im * im + start.real;
		point.imaginary = 2. * re * im + start.imaginary;
		++iteration;
	}
	return (iteration);
}

int32_t	juliaEq(const t_fractol *fractol, t_complex point)
{
	(void)fractol;
	(void)point;
	return (0);
}
