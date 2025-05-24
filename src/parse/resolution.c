/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:12:09 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 17:13:15 by adelille         ###   ########.fr       */
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

static size_t	parse_int(const char *str, const t_line_arg *la)
{
	size_t	i;
	
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (puterr_invalid_int(la, str, 1, MAX_RESOLUTION), 0);
		i++;
	}
	if (i > 5)
		return (puterr_invalid_int(la, str, 1, MAX_RESOLUTION), 0);
	i = ft_atoun(str);
	if (i == 0 || i > MAX_RESOLUTION)
		return (puterr_invalid_int(la, str, 1, MAX_RESOLUTION), 0);
	return (i);
}

bool	parse_resolution(t_env *env, const t_line_arg *la)
{
	if (la->split_size != 3)
		return (false); // TODO: @adelille create print error function
	env->win.w = parse_int(la->split[1], la);
	env->win.h = parse_int(la->split[2], la);
	if (env->win.w == 0 || env->win.h == 0)
		return (false);
	return (true);
}
