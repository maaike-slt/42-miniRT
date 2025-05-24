/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:27:35 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 18:43:45 by adelille         ###   ########.fr       */
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
