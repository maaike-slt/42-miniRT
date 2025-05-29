/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:51:49 by msloot            #+#    #+#             */
/*   Updated: 2025/05/28 21:35:56 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	handle_dec(const char *nptr, size_t i, double nb)
{
	size_t	pow_cnt;

	if (nptr[i] == '.')
		i++;
	pow_cnt = 1;
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]))
	{
		nb += (nptr[i] - '0') / ft_powf(10, pow_cnt);
		i++;
		pow_cnt++;
	}
	return (nb);
}

double	ft_atod(const char *nptr)
{
	size_t	i;
	double	sign;
	double	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]))
	{
		nb *= 10;
		nb += nptr[i] - '0';
		i++;
	}
	return (sign * handle_dec(nptr, i, nb));
}
