/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:04:13 by msloot            #+#    #+#             */
/*   Updated: 2025/05/27 22:32:54 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_pow(ssize_t	x, size_t y)
{
	ssize_t	n;

	if (y == 0)
		return (1);
	n = x;
	while (y > 1)
	{
		n *= x;
		y--;
	}
	return (n);
}

float	ft_powf(float x, size_t y)
{
	float	n;

	if (y == 0)
		return (1);
	n = x;
	while (y > 1)
	{
		n *= x;
		y--;
	}
	return (n);
}
