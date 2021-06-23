/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:47:44 by acami             #+#    #+#             */
/*   Updated: 2021/06/23 17:12:44 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	parseInput(argc, argv, &fractol);
	fractolInit(&fractol);
	fractolDraw(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
