/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:27:35 by acami             #+#    #+#             */
/*   Updated: 2021/06/14 19:54:55 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

#include <stdio.h>

// Show possible inputs and quit
static void	xShowHelp(void)
{
	write(1, "Error", 5);
	exit(EXIT_FAILURE);
}

static t_fractalId	parseName(char *name)
{
	int					count;
	static const char	*names[FRACTALS_SUPPORTED] = {
		[Mandelbrot] = "Mandelbrot",
		[Julia] = "Julia"
	};

	count = 0;
	while (count < FRACTALS_SUPPORTED)
	{
		if (ft_strncmp(names[count], name, ft_strlen(names[count])) == 0)
			return (count);
		++count;
	}
	return (Error);
}
/*
static int32_t	parseParams(char **argv, t_fractol *fractol, int32_t curr_arg)
{
	int32_t	param_val;

	if (ft_strncmp(argv[curr_arg], "-W", ft_strlen(argv[curr_arg]) == 0))
	{
		param_val = ft_atoi(argv[curr_arg + 1]);
		if (param_val < 1 || param_val > 2160)
			xShowHelp();
		fractol->width = param_val;
		return (2);
	}
	if (ft_strncmp(argv[curr_arg], "-H", ft_strlen(argv[curr_arg]) == 0))
	{
		param_val = ft_atoi(argv[curr_arg + 1]);
		if (param_val < 1 || param_val > 3840)
			xShowHelp();
		fractol->height = param_val;
		return (2);
	}
	xShowHelp();
	return (-1);
}*/

t_fractalId	parseInput(int argc, char **argv, t_fractol *fractol)
{
	t_fractalId	res;
	int32_t		curr_arg;

	if (argc < 2)
		xShowHelp();
	curr_arg = 1;
	printf("%s\n%c\n", argv[curr_arg], argv[curr_arg][0]);
	(void)fractol;
	/*while (argv[curr_arg][0] == '-')
	{
		curr_arg += parseParams(argv, fractol, curr_arg);
	}*/
	res = parseName(argv[curr_arg]);
	if (res == Error)
		xShowHelp();
	return (res);
}
