/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:27:35 by acami             #+#    #+#             */
/*   Updated: 2021/06/14 17:40:51 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

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

t_fractalId	parseInput(int argc, char **argv)
{
	t_fractalId	res;

	if (argc != 2)
		xShowHelp();
	res = parseName(argv[1]);
	if (res == Error)
		xShowHelp();
	return (res);
}
