/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:46:37 by acami             #+#    #+#             */
/*   Updated: 2021/06/16 18:53:56 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CODES_H
# define KEY_CODES_H

// X11/X.h defines
# define NOEVENTMASK	0L

# define KEYPRESS		2
# define KEYRELEASE		3
# define BUTTONPRESS	4
# define BUTTONRELEASE	5
# define MOTIONNOTIFY	6
# define DESTROYNOTIFY	17

# ifdef BUILD_LINUX
// Key code defines for linux
# else
// Key code defines for macos (default)
#  define MAX_KEYBOARD_CODE	127

#  define M_LMB				1
#  define M_RMB				2
#  define M_SCROLL_UP		4
#  define M_SCROLL_DOWN		5

#  define KEYBOARD_ESC		53

#  define KEYBOARD_A		0
#  define KEYBOARD_S		1
#  define KEYBOARD_D		2
#  define KEYBOARD_W		13

#  define KEYBOARD_R		15

#  define KEYBOARD_LEFT		123
#  define KEYBOARD_RIGHT	124
#  define KEYBOARD_DOWN		125
#  define KEYBOARD_UP		126

# endif

#endif
