/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_colour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:27:39 by acami             #+#    #+#             */
/*   Updated: 2021/06/16 15:00:58 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

int32_t	generateColour2(int32_t iterations, int32_t max_iterations)
{
	if (iterations > max_iterations - 10)
		return (0x00000000);
	return (0x00AAAAAA);
}

int32_t	generateColour(int32_t iterations, int32_t max_iterations)
{
	int		colour;
	double	t;

	t = (double)iterations / max_iterations;
	colour = 0;
	colour = ((int8_t)(9 * (1 - t) * pow(t, 3) * 255)) * 65536
		+ (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255) * 256
		+ (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (colour);
}
