/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:27:35 by acami             #+#    #+#             */
/*   Updated: 2021/06/19 16:59:34 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

// Show possible inputs and quit
static void	xShowHelp(char *bad_param)
{
	ft_putendl_fd("Error!", 1);
	ft_putstr_fd("Bad input or unknown parameter: ", 1);
	ft_putendl_fd(bad_param, 1);
	ft_putstr_fd("Usage: ./fractol [-W 0 < WIDTH < 3841] ", 1);
	ft_putendl_fd("[-H 0 < HEIGHT < 2161] <FRACTAL_NAME>", 1);
	ft_putendl_fd("Fractals supported:", 1);
	ft_putendl_fd(" --- Mandelbrot", 1);
	ft_putendl_fd(" --- Julia", 1);
	ft_putendl_fd(" --- Burning Ship", 1);
	exit(EXIT_FAILURE);
}

static t_fractalId	parseName(char *name)
{
	int					count;
	static const char	*names[FRACTALS_SUPPORTED] = {
		[Mandelbrot] = "Mandelbrot",
		[Julia] = "Julia",
		[BurningShip] = "Burning Ship"
	};

	count = 0;
	while (count < FRACTALS_SUPPORTED)
	{
		if (ft_strequ(names[count], name))
			return (count);
		++count;
	}
	return (Error);
}

static int32_t	parseParams(char **argv, t_fractol *fractol, int32_t curr_arg)
{
	int32_t	param_val;

	if (ft_strequ(argv[curr_arg], "-W"))
	{
		param_val = ft_atoi(argv[curr_arg + 1]);
		if (param_val < 1 || param_val > 3840)
			xShowHelp(argv[curr_arg + 1]);
		fractol->width = param_val;
		return (2);
	}
	if (ft_strequ(argv[curr_arg], "-H"))
	{
		param_val = ft_atoi(argv[curr_arg + 1]);
		if (param_val < 1 || param_val > 2160)
			xShowHelp(argv[curr_arg + 1]);
		fractol->height = param_val;
		return (2);
	}
	xShowHelp(argv[curr_arg]);
	return (-1);
}

t_fractalId	parseInput(int argc, char **argv, t_fractol *fractol)
{
	t_fractalId	res;
	int32_t		curr_arg;

	if (argc < 2)
		xShowHelp("Too few arguments");
	curr_arg = 1;
	fractol->width = WIN_WIDTH;
	fractol->height = WIN_HEIGHT;
	while (argv[curr_arg][0] == '-')
		curr_arg += parseParams(argv, fractol, curr_arg);
	res = parseName(argv[curr_arg]);
	if (res == Error || curr_arg + 1 < argc)
		xShowHelp(argv[curr_arg]);
	return (res);
}
