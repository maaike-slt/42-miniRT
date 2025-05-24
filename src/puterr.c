/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:27:35 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 18:00:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	puterr(void)
{
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
}
