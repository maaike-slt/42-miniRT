/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:45:35 by msloot            #+#    #+#             */
/*   Updated: 2025/05/30 22:13:45 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
/*
Ambient lighting:
A 0.2 255,255,255
  ∗ identifier: A
  ∗ ambient lighting ratio in the range [0.0,1.0]: 0.2
  ∗ (bonus) R,G,B colors in the range [0-255]: 10, 0, 255
*/

bool	parse_ambient_lighting(t_env *env, const t_line_arg *la)
{
	t_ambient	*a;

	if (la->split_size != 3)
		return (puterr_invalid_token_amount(\
la, 3, "<lighting ratio> <color in r,g,b>"), false);
	a = &(env->scene.a);
	a->lighting_ratio = ft_atof(la->split[1]);
	if (a->lighting_ratio < 0 || a->lighting_ratio > 1)
		return (\
puterr_invalid_float(la, la->split[2], 0, 1), false);
	if (!parse_color(la, la->split[2], &(a->color)))
		return (false);
	return (true);
}
