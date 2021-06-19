/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_colour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:27:39 by acami             #+#    #+#             */
/*   Updated: 2021/06/19 17:00:37 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

static int32_t	colourDefaultBlue(int32_t iterations, int32_t max_iterations)
{
	int		colour;
	double	t;

	t = (double)iterations / max_iterations;
	colour = 0;
	colour |= (((int8_t)(9 * (1 - t) * pow(t, 3) * 255)) << 16) & 0xff0000;
	colour |= ((int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255) << 8) & 0xff00;
	colour |= (int8_t)(8.5 * pow((1 - t), 3) * t * 255) & 0xff;
	return (colour);
}

static int32_t	colourDefaultRed(int32_t iterations, int32_t max_iterations)
{
	int		colour;
	double	t;

	t = (double)iterations / max_iterations;
	colour = 0;
	colour |= (((int8_t)(8.5 * pow((1 - t), 3) * t * 255)) << 16) & 0xff0000;
	colour |= (((int8_t)(9 * (1 - t) * pow(t, 3) * 255)) << 8) & 0xff00;
	colour |= ((int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255)) & 0xff;
	return (colour);
}

static int32_t	colourDefaultGreen(int32_t iterations, int32_t max_iterations)
{
	int		colour;
	double	t;

	t = (double)iterations / max_iterations;
	colour = 0;
	colour |= ((int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255) << 16) & 0xff0000;
	colour |= (((int8_t)(8.5 * pow((1 - t), 3) * t * 255)) << 8) & 0xff00;
	colour |= ((int8_t)(9 * (1 - t) * pow(t, 3) * 255)) & 0xff;
	return (colour);
}

int32_t	generateColour(int32_t iterations, int32_t max_iterations,
t_colourScheme colour_scheme)
{
	static const t_colourFunc	colour_funcs[COLOUR_FUNCS] = {
		[DefaultBlue] = colourDefaultBlue,
		[DefaultGreen] = colourDefaultGreen,
		[DefaultRed] = colourDefaultRed
	};

	return (colour_funcs[colour_scheme & COLOUR_FUNCS](iterations,
		max_iterations));
}
