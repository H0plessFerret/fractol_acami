/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:55:00 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 18:59:02 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int32_t	closeWindow(void)
{
	printf("closeWindow was called!\n");
	exit(0);
}

int32_t	keyPressHandler(int32_t key, t_fractol *fractol)
{
	(void)fractol;
	printf("keyPressHandler was called!\n");
	printf("key code: %d\n", key);
	return (0);
}

int32_t	buttonPressHandler(int32_t button, t_fractol *fractol)
{
	(void)fractol;
	printf("buttonPressHandler was called!\n");
	printf("button code: %d\n", button);
	return (0);
}

int32_t	buttonReleaseHandler(int32_t button, t_fractol *fractol)
{
	(void)fractol;
	printf("buttonReleaseHandler was called!\n");
	printf("button code: %d\n", button);
	return (0);
}

int32_t	motionHandler(int32_t x, int32_t y, t_fractol *fractol)
{
	(void)fractol;
	printf("motionHandler was called!\n");
	printf("x: %d, y: %d\n", x, y);
	return (0);
}
