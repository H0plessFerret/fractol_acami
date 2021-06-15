/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:14:40 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 22:17:34 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	mandelbrotEqCool(t_fractol *fractol, double real, double imaginary)
{
	int32_t		iteration;
	double		re;
	double		im;

	iteration = 0;
	while ((iteration <= fractol->max_iterations) && (real * real + imaginary * imaginary <= 4))
	{
		re = real;
		im = imaginary;
		real = re * re - im * im + re;
		imaginary = 2. * re * im + im;
		++iteration;
	}
	return (iteration);
}

int32_t	mandelbrotEq(const t_fractol *fractol, t_complex point)
{
	(void)fractol;
	(void)point;
	return (0);
}

int32_t	juliaEq(const t_fractol *fractol, t_complex point)
{
	(void)fractol;
	(void)point;
	return (0);
}
