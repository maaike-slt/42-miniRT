
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:30:43 by msloot            #+#    #+#             */
/*   Updated: 2025/05/24 16:16:25 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

/*
Resolution:
R 1920 1080
  ∗ identifier: R
  ∗ width: Width of the image in pixels, in the range [1,65535]: 1920
  ∗ height: Height of the image in pixels, in the range [1,65535]: 1080
*/

static size_t	parse_value(const char *str, const t_line_arg *la)
{
	size_t	i;
	
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0); // TODO: @adelille create print error function
		i++;
	}
	i = ft_atoun(str);
	if (i == 0 || i > 65535)
		return (0); // TODO: @adelille create print error function
	return (i);
}

bool	parse_resolution(t_env *env, const t_line_arg *la)
{
	if (la->split_size != 3)
		return (false); // TODO: @adelille create print error function
	env->win.w = ft_parse_value(la->split[1]);
	env->win.h = ft_parse_value(la->split[2]);
	if (env->win.w == 0 || env->win.h == 0)
		return (false);
	return (true);
}
