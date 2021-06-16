/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:14:40 by acami             #+#    #+#             */
/*   Updated: 2021/06/16 12:16:40 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

int32_t	mandelbrotEq(const t_fractol *fractol, t_complex start)
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
			pow(curr.real, 2.) - pow(curr.imaginary, 2.) + start.real,
			2. * curr.real * curr.imaginary + start.imaginary);
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
