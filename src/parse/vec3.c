/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:22:11 by msloot            #+#    #+#             */
/*   Updated: 2025/05/29 21:08:35 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static bool	parse_float(const t_line_arg *la, const char *str, float *f)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.' && str[i] != '-')
			return (puterr_invalid_float_unbound(la, str), false);
		i++;
	}
	*f = ft_atof(str);
	return (true);
}

bool	parse_vec3(const t_line_arg *la, const char *str, t_vec3 *vec3)
{
	char	**split;
	size_t	len;

	split = ft_split_any_of(str, ",");
	if (!split)
		return (false);
	len = ft_2d_size((const void **)split);
	if (len != 3)
	{
		ft_2d_free((void ***)&split, len);
		puterr_invalid_sub_token_amount(
			la, str, (t_expected_got){3, len}, "<x,y,z>");
		return (false);
	}
	if (!parse_float(la, split[0], &(vec3->x))
		|| !parse_float(la, split[1], &(vec3->y))
		|| !parse_float(la, split[2], &(vec3->z)))
		return (ft_2d_free((void ***)&split, len), false);
	ft_2d_free((void ***)&split, len);
	return (true);
}
