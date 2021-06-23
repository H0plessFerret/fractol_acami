/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:24:37 by acami             #+#    #+#             */
/*   Updated: 2021/06/23 16:56:01 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	ft_strequ(const char *str1, const char *str2)
{
	size_t	count;

	count = 0;
	while (str1[count] != '\0' || str2[count] != '\0')
	{
		if (str1[count] != str2[count])
			return (false);
		++count;
	}
	if (str1[count] != str2[count])
		return (false);
	return (true);
}

void	setComplex(t_complex *number, double new_re, double new_im)
{
	number->real = new_re;
	number->imaginary = new_im;
}

void	closeWindow(int32_t key, t_fractol *fractol)
{
	(void)key;
	(void)fractol;
	exit(0);
}

void	resetFractal(int32_t key, t_fractol *fractol)
{
	(void)key;
	fractolFunctionInit(fractol);
}

void	updateFractal(int32_t key, t_fractol *fractol)
{
	(void)key;
	(void)fractol;
}
