/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:14:40 by acami             #+#    #+#             */
/*   Updated: 2021/06/18 13:20:40 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

int32_t	mandelbrotEq(const t_fractol *fractol, t_complex point)
{
	int32_t		iteration;
	t_complex	curr;

	iteration = 0;
	curr.real = 0.;
	curr.imaginary = 0.;
	while (iteration < fractol->max_iterations
		&& pow(curr.real, 2.) + pow(curr.imaginary, 2.) <= 4.)
	{
		setComplex(&curr,
			pow(curr.real, 2.) - pow(curr.imaginary, 2.) + point.real,
			2. * curr.real * curr.imaginary + point.imaginary);
		++iteration;
	}
	return (iteration);
}

int32_t	juliaEq(const t_fractol *fractol, t_complex point)
{
	int32_t		iteration;
	t_complex	curr;

	(void)point;
	iteration = 0;
	curr.real = point.real;
	curr.imaginary = point.imaginary;
	while (iteration < fractol->max_iterations
		&& pow(curr.real, 2.) + pow(curr.imaginary, 2.) <= 4.)
	{
		setComplex(&curr,
			pow(curr.real, 2.) - pow(curr.imaginary, 2.)
			+ fractol->extra_param.real,
			2. * curr.real * curr.imaginary + fractol->extra_param.imaginary);
		++iteration;
	}
	return (iteration);
}
