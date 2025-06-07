/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:27:35 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 15:21:18 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	puterr(void)
{
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
}

void	puterr_argc(void)
{
	puterr();
	ft_putstr_fd("not the right amount of files, 1 file shall be given\n",
		STDERR_FILENO);
}

void	puterr_filetype(void)
{
	puterr();
	ft_putstr_fd("not the right filetype, a .rt file is needed\n",
		STDERR_FILENO);
}
