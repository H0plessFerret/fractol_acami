/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:25:22 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 22:35:28 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define FRACTALS_SUPPORTED	2
# define WIN_WIDTH			1920
# define WIN_HEIGHT			1080
# define THREADS			8

# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <stdbool.h>
# include <pthread.h>
# include "mlx.h"
# include "error_messages.h"

typedef enum e_fractalId		t_fractalId;
typedef struct s_threadInfo		t_threadInfo;
typedef struct s_complex		t_complex;
typedef struct s_fractol		t_fractol;
typedef struct s_fractalInfo	t_fractalInfo;
typedef int						(*t_equation)(const t_fractol *fractol,
								t_complex point);

enum e_fractalId{
	Error = -1,
	Mandelbrot,
	Julia
};

// Fill later, when will be working on multi-threading
// Basically just a placeholder for now
struct s_threadInfo
{
	pthread_t	thread;
	int32_t		start_line;
	int32_t		end_line;
};

struct	s_complex
{
	double	real;
	double	imaginary;
};

struct s_fractalInfo
{
	double			re_min_start;
	double			re_max_start;
	double			im_min_start;
	double			im_max_start;
	t_equation		fractal_equation;
	int32_t			max_iterations;
	t_complex		extra_param_start;
};

struct s_fractol{
	void			*mlx;
	void			*window;
	int32_t			width;
	int32_t			height;
	void			*img;
	char			*data_addr;
	int32_t			bpp;
	int32_t			line_len;
	int32_t			endian;
	t_fractalId		fract_id;
	double			re_max;
	double			re_min;
	double			im_max;
	double			im_min;
	t_equation		fractal_equation;
	int32_t			max_iterations;
	t_complex		extra_param;
};

// Parse arguments of the program call and return the correct fractal_id
t_fractalId	parseInput(int argc, char **argv, t_fractol *fractol);

// Initializes t_fractol struct
void		fractolInit(t_fractol *fractol);

// Draw the fractal currently held in memory
void		fractolDraw(t_fractol *fractol);

// Returns integer (colour) depending on the amount of iterations
// it took to fail the set inclusion rule
int32_t		generateColour(int32_t iterations, int32_t max_iterations);

// Prints error message and exits the program
void		panic(const char *errstr);

// Returns true if strings are equal and false if they are not
bool		ft_strequ(const char *str1, const char *str2);

// ------------------------- EQUATIONS ------------------------- //

// Equation for Mandelbrot set
int32_t		mandelbrotEq(const t_fractol *fractol, t_complex point);

// Equation for Julia set
int32_t		juliaEq(const t_fractol *fractol, t_complex point);

// ---------------------- EVENT  HANDLING ---------------------- //

// Closes window (both from ESC and pressing the button on the window)
int32_t		closeWindow(void);

// Maps key presses to actions
int32_t		keyPressHandler(int32_t key, t_fractol *fractol);

// Maps button presses to actions
int32_t		buttonPressHandler(int32_t button, t_fractol *fractol);

// Maps button releases to actions
int32_t		buttonReleaseHandler(int32_t button, t_fractol *fractol);

// Handles mouse movements
int32_t		motionHandler(int32_t x, int32_t y, t_fractol *fractol);

// Translates fractal x_shift to the right and y_shift to the left
int32_t		translateFractal(double x_shift, double y_shift,
				t_fractol *fractol);

// Zooms in on the point (x, y) with the zoom factor factor
int32_t		zoomFractal(int32_t x, int32_t y, double factor,
				t_fractol *fractol);

// Changes parameter for Julia-type of fractals according to the mouse position
int32_t		changeParam(int32_t x, int32_t y, t_fractol *fractol);

#endif