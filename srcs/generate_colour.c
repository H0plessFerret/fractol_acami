/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_colour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:11:23 by acami             #+#    #+#             */
/*   Updated: 2021/06/20 17:20:46 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

int32_t	generateColour(const t_fractol *fractol, const t_complex *point,
int32_t random_factor)
{
	int32_t	iterations;

	iterations = fractol->fractal_equation(fractol, *point);
	return (findPointColour(iterations, fractol->max_iterations,
			fractol->colour_scheme, random_factor));
}
