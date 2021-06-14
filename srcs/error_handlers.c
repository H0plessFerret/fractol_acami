/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:19:48 by acami             #+#    #+#             */
/*   Updated: 2021/06/14 17:39:44 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void	write_msg(char	*errstr)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd(errstr, 2);
	ft_putendl_fd("\033[0m", 2);
}

void	panic(char	*errstr)
{
	write_msg(errstr);
	exit(EXIT_FAILURE);
}
