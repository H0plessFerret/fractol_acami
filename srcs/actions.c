/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:57:28 by acami             #+#    #+#             */
/*   Updated: 2021/06/16 19:06:47 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	closeWindow(void)
{
	exit(0);
}

int32_t	translateFractal(double re_shift, double im_shift, t_fractol *fractol)
{
	fractol->re_min += re_shift;
	fractol->re_max += re_shift;
	fractol->im_max += im_shift;
	fractol->im_min += im_shift;
	fractolDraw(fractol);
	return (0);
}

/*
int32_t	zoomFractal(int32_t x, int32_t y, double factor,
t_fractol *fractol)
{
	return (0);
}
*/