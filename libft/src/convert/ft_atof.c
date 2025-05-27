/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:43:53 by msloot            #+#    #+#             */
/*   Updated: 2025/05/27 22:47:08 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "unistd.h"

float	handle_dec(const char *nptr, size_t i, float nb)
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

float	ft_atof(const char *nptr)
{
	size_t	i;
	float	sign;
	float	nb;

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

/*
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
*/