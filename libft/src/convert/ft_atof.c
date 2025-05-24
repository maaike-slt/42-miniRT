/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:43:53 by msloot            #+#    #+#             */
/*   Updated: 2025/05/24 21:25:45 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "unistd.h"

float	ft_atof(const char *nptr)
{
	size_t	i;
	float	sign;
	float	nb;
	float	c_nb;

	i = 0;
	sign = 1;
	nb = 0;
	c_nb = 0;
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
	i++;
	if (nptr[i] == '.')
	{
		while (nptr[i] != '\0' && ft_isdigit(nptr[i]))
		{
			c_nb /= 10;
			c_nb += nptr[i] - '0';
			i++;
		}
	}
	return (sign * (nb + c_nb));
}

#include <stdio.h>

static void	test(const char *str)
{
	printf("'%s':\t'%f'\n", str, ft_atof(str));
}

int	main(void)
{
	test("0");
	test("0.");
	test("0.0");
	test("0.0f");
	test("1");
	test("1.");
	test("1.0");
	test("1.0f");
	test("1.5");
	test("1.5f");
	test("1.50000f");
	test("1.50005");
	test("-1.");
	test("-1.0");
	test("-1.0f");
	test("-1.5");
	test("-1.5f");
	test("-1.50000f");
	test("-1.50005");
	test("42.21");
	test("-42.21");
	test("abc");
	test("0abc");
	test("100000000000000000000000000000000000000.00000000000000000000000000");
	test("-100000000000000000000000000000000000000.0000000000000000000000000");
	test("42..21");
	test("+42.21");
	test(".42");
	test("42.21.81");
}