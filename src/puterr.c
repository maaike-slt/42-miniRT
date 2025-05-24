/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:27:35 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 15:28:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	puterr()
{
	ft_putstr_fd(Y_BRED, STDERR_FILENO);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
}
