/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:25:22 by acami             #+#    #+#             */
/*   Updated: 2021/06/14 17:30:27 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define	FRACTALS_SUPPORTED	2
# define	WIN_SIZE_X			1000
# define	WIN_SIZE_Y			1000

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "error_messages.h"

typedef struct s_complex	t_complex;
typedef struct s_image		t_image;
typedef struct s_fractol	t_fractol;
typedef struct s_threadInfo	t_threadInfo;
typedef enum e_fractalId	t_fractalId;
typedef int					(*t_equation)(t_fractol *fractol);

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

struct	s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
};

// Fill later, when will be working on multi-threading
// Basically just a placeholder for now
struct s_threadInfo
{
	int		thread_number;
};

struct s_fractol{
	void			*mlx;
	void			*window;
	t_image			*image;
	double			x_max;
	double			x_min;
	double			y_max;
	double			y_min;
	char			*fract_name;
	t_fractalId		fract_id;
	t_equation		fractal_equation;
	t_threadInfo	*thread_info;
};

// Parse arguments of the program call and return the correct fractal_id
t_fractalId	parseInput(int argc, char **argv);

// Initializes t_fractol struct
void		fractolInit(t_fractol *fractol);

// Prints error message and exits the program
void		panic(char	*errstr);

#endif