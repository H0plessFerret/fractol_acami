/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:47:44 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 21:10:34 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	fractol.fract_id = parseInput(argc, argv, &fractol);
	fractolInit(&fractol);
	fractolDraw(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}