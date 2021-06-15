/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_colour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:27:39 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 22:41:32 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	generateColour(int32_t iterations, int32_t max_iterations)
{
	if (iterations > max_iterations - 10)
		return (0x00000000);
	return (0x00AAAAAA);
}
