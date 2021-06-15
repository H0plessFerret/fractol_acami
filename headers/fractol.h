/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:25:22 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 16:12:01 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define	FRACTALS_SUPPORTED	2
# define	WIN_WIDTH			1920
# define	WIN_HEIGHT			1080

# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <stdbool.h>
# include "mlx.h"
# include "error_messages.h"

typedef struct s_complex		t_complex;
typedef struct s_fractol		t_fractol;
typedef struct s_threadInfo		t_threadInfo;
typedef struct s_fractalInfo	t_fractalInfo;
typedef enum e_fractalId		t_fractalId;
typedef int						(*t_equation)(t_fractol *fractol);

enum e_fractalId{
	Error = -1,
	Mandelbrot,
	Julia
};

struct	s_complex
{
	double	real;
	double	imaginary;
};

// Fill later, when will be working on multi-threading
// Basically just a placeholder for now
struct s_threadInfo
{
	int		thread_number;
};

struct s_fractalInfo
{
	double			x_max_start;
	double			x_min_start;
	double			y_max_start;
	double			y_min_start;
	t_equation		fractal_equation;
};

struct s_fractol{
	void			*mlx;
	void			*window;
	int32_t			width;
	int32_t			height;
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_fractalId		fract_id;
	double			x_max;
	double			x_min;
	double			y_max;
	double			y_min;
	t_equation		fractal_equation;
	t_threadInfo	*thread_info;
};

// Parse arguments of the program call and return the correct fractal_id
t_fractalId	parseInput(int argc, char **argv, t_fractol *fractol);

// Initializes t_fractol struct
void		fractolInit(t_fractol *fractol);

// Prints error message and exits the program
void		panic(char	*errstr);

// Returns true if strings are equal and false if they are not
bool		ft_strequ(const char *str1, const char *str2);

// ------------------------- EQUATIONS ------------------------- //

// Equation for Mandelbrot set
int32_t		mandelbrotEq(t_fractol *fractol);

// Equation for Julia set
int32_t		juliaEq(t_fractol *fractol);

#endif