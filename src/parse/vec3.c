/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:22:11 by msloot            #+#    #+#             */
/*   Updated: 2025/05/28 21:32:40 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_vec3(const char *str, t_vec3 *vec3)
{
	char	**split;
	size_t	len;

	split = ft_split_any_of(str, ",");
	if (!split)
		return (false);
	len = ft_2d_size((const void **)split);
	if (len != 3)
		return (false); // TODO: @adelille put error message
	vec3->x = ft_atof(split[0]);
	vec3->y = ft_atof(split[1]);
	vec3->z = ft_atof(split[2]);
	return (true);
}
