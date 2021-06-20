/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:27:39 by acami             #+#    #+#             */
/*   Updated: 2021/06/20 17:24:44 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

static int32_t	colourDefault(int32_t iterations, int32_t max_iterations,
int32_t extra_param)
{
	int		colour;
	double	t;

	(void)extra_param;
	t = (double)iterations / max_iterations;
	colour = 0;
	colour |= ((int32_t)(9 * (1 - t) * pow(t, 3) * 255) << 16) & 0xff0000;
	colour |= ((int32_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255) << 8) & 0xff00;
	colour |= (int32_t)(8.5 * pow((1 - t), 3) * t * 255) & 0xff;
	return (colour);
}

static int32_t	colourRandAll(int32_t iterations, int32_t max_iterations,
int32_t extra_param)
{
	int		colour;
	double	t;

	if (iterations == 0)
		++iterations;
	t = (double)iterations / max_iterations;
	colour = 0;
	colour |= ((int32_t)((extra_param % 27) * (1 - t)
				* pow(t, 3) * 255) << 16) & 0xff0000;
	colour |= ((int32_t)((extra_param % 45) * pow((1 - t), 2)
				* pow(t, 2) * 255) << 8) & 0xff00;
	colour |= (int32_t)((extra_param % 12) * pow((1 - t), 3) * t * 255) & 0xff;
	return (colour);
}

static int32_t	colourDrugs(int32_t iterations, int32_t max_iterations,
int32_t extra_param)
{
	int		colour;
	double	t;

	(void)extra_param;
	t = (double)iterations / max_iterations + 3.75;
	colour = 0;
	colour |= ((int32_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255) << 16)
		& 0xff0000;
	colour |= ((int32_t)(8.5 * pow((1 - t), 3) * t * 255) << 8) & 0xff00;
	colour |= ((int32_t)(9 * (1 - t) * pow(t, 3) * 255)) & 0xff;
	return (colour);
}

static int32_t	colourRandDrugs(int32_t iterations, int32_t max_iterations,
int32_t extra_param)
{
	int		colour;
	double	t;

	t = (double)iterations / max_iterations + (extra_param % 20) + 1;
	colour = 0;
	colour |= ((int32_t)(8.5 * pow((1 - t), 3) * t * 255) << 16) & 0xff0000;
	colour |= ((int32_t)(9 * (1 - t) * pow(t, 3) * 255) << 8) & 0xff00;
	colour |= ((int32_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255)) & 0xff;
	return (colour);
}

int32_t	findPointColour(int32_t iterations, int32_t max_iterations,
t_colourScheme colour_scheme, int32_t random_factor)
{
	static const t_colourFunc	colour_funcs[COLOURS_SUPPORTED] = {
		[DefaultColour] = colourDefault,
		[RandomAll] = colourRandAll,
		[Drugs] = colourDrugs,
		[RandomDrugs] = colourRandDrugs
	};

	return (colour_funcs[colour_scheme % COLOURS_SUPPORTED](iterations,
		max_iterations, random_factor));
}
