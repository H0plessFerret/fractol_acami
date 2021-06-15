/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:46:37 by acami             #+#    #+#             */
/*   Updated: 2021/06/15 19:51:14 by acami            ###   ########.fr       */
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
#  define M_SCROLL_UP	4
#  define M_SCROLL_DOWN	5
# endif

#endif
