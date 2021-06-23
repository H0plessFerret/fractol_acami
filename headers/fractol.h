/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:25:22 by acami             #+#    #+#             */
/*   Updated: 2021/06/23 16:54:58 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define FRACTALS_SUPPORTED	3
# define WIN_WIDTH			1200
# define WIN_HEIGHT			1200

// On school iMacs CPU is Core i5-7500, max threads here is 16
# define THREADS			16
# define COLOURS_SUPPORTED	4

# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <stdbool.h>
# include <pthread.h>
# include "mlx.h"
# include "error_messages.h"

typedef enum e_fractalId		t_fractalId;
typedef enum e_colourScheme		t_colourScheme;
typedef struct s_threadInfo		t_threadInfo;
typedef struct s_complex		t_complex;
typedef struct s_fractol		t_fractol;
typedef struct s_fractalInfo	t_fractalInfo;
typedef int32_t					(*t_equation)(const t_fractol *fractol,
								t_complex point);
typedef int32_t					(*t_colourFunc)(int32_t iterations,
								int32_t max_iterations, int32_t extra_param);
typedef int32_t					(*t_handerAction)();
typedef void					(*t_keyAction)(int32_t key, t_fractol *fractol);

enum e_fractalId
{
	Error = -1,
	Mandelbrot,
	Julia,
	BurningShip
};

enum e_colourScheme
{
	DefaultColour = 0,
	RandomAll,
	Drugs,
	RandomDrugs
};

// Fill later, when will be working on multi-threading
// Basically just a placeholder for now
struct s_threadInfo
{
	pthread_t	thread;
	int32_t		start_line;
	int32_t		end_line;
	t_fractol	*fractol;
	int32_t		random_factor;
};

struct s_complex
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
	int32_t			max_iterations_start;
	int32_t			iteration_change;
	t_complex		extra_param_start;
	t_colourScheme	colour_scheme_start;
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
	int32_t			iteration_change;
	t_complex		extra_param;
	t_colourScheme	colour_scheme;
	bool			lmb_pressed;
};

// Parse arguments of the program call and return the correct fractal_id
t_fractalId	parseInput(int argc, char **argv, t_fractol *fractol);

// Initializes default values for the fractol function
void		fractolFunctionInit(t_fractol *fractol);

// Initializes t_fractol struct
void		fractolInit(t_fractol *fractol);

// Draw the fractal currently held in memory
void		fractolDraw(t_fractol *fractol);

// Returns colour value appropriate for the current point
int32_t		generateColour(const t_fractol *fractol, const t_complex *point,
				int32_t random_factor);

// Returns integer (colour) depending on the amount of iterations
// it took to fail the set inclusion rule
int32_t		findPointColour(int32_t iterations, int32_t max_iterations,
				t_colourScheme colour_scheme, int32_t random_factor);

// Prints error message and exits the program
void		panic(const char *errstr);

// Returns true if strings are equal and false if they are not
bool		ft_strequ(const char *str1, const char *str2);

// Sets new values for a complex number
void		setComplex(t_complex *number, double new_re, double new_im);

// ------------------------- EQUATIONS ------------------------- //

// Equation for Mandelbrot set
// eq: zˆ2 + point;
int32_t		mandelbrotEq(const t_fractol *fractol, t_complex point);

// Equation for Julia set
// eq: extra_paramˆ2 + point
int32_t		juliaEq(const t_fractol *fractol, t_complex point);

int32_t		burningShipEq(const t_fractol *fractol, t_complex point);

// ---------------------- EVENT  HANDLING ---------------------- //
/*
		[KEYBOARD_W] = translateFractal,
		[KEYBOARD_A] = translateFractal,
		[KEYBOARD_S] = translateFractal,
		[KEYBOARD_D] = translateFractal,
		[KEYBOARD_R] = resetFractal,
		[KEYBOARD_ESC] = closeWindow,
		[KEYBOARD_PLUS] = changeIterations,
		[KEYBOARD_MINUS] = changeIterations,
		[KEYBOARD_Q] = redrawFractal,
		[KEYBOARD_UP] = changeColour,
		[KEYBOARD_DOWN] = changeColour
*/
// Closes window (both from ESC and pressing the button on the window)
void		closeWindow(int32_t key, t_fractol *fractol);

// Maps key presses to actions
void		keyPressHandler(int32_t key, t_fractol *fractol);

// Maps button presses to actions
void		buttonPressHandler(int32_t button, int x, int y,
				t_fractol *fractol);

// Maps button releases to actions
void		buttonReleaseHandler(int32_t button, int x, int y,
				t_fractol *fractol);

// Handles mouse movements
void		motionHandler(int32_t x, int32_t y, t_fractol *fractol);

// Translates fractal x_shift to the right and im_shift up
void		translateFractal(int32_t key, t_fractol *fractol);

// Reset fractal to default values
void		resetFractal(int32_t key, t_fractol *fractol);

// Redraws fractal
void		updateFractal(int32_t key, t_fractol *fractol);

// Changes max_iteration param in fractol
void		changeIterations(int32_t key, t_fractol *fractol);

// Changes colour_scheme param in fractol
void		changeColour(int32_t key, t_fractol *fractol);

// Zooms in on the point (x, y) with the zoom factor factor
int32_t		zoomFractal(int32_t x, int32_t y, int32_t button,
				t_fractol *fractol);

// Changes parameter for Julia-type of fractals according to the mouse position
int32_t		changeParam(int32_t x, int32_t y, int32_t key, t_fractol *fractol);

#endif