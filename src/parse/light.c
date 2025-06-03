/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:24:29 by msloot            #+#    #+#             */
/*   Updated: 2025/06/03 20:54:37 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

/*
Light:
L -40.0,50.0,0.0 0.6 10,0,255
  ∗ identifier: L
  ∗ x, y, z coordinates of the light point: -40.0,50.0,0.0
  ∗ the light brightness ratio in the range [0.0,1.0]: 0.6
  ∗ (bonus) R,G,B colors in the range [0-255]: 10, 0, 255
*/

bool	parse_light(t_env *env, const t_line_arg *la)
{
	t_light	*l;

	if (la->split_size != 4)
		return (puterr_invalid_token_amount(\
la, 4, "<pos in x,y,z> <brightness> <color in r,g,b>"), false);
	l = &(env->scene.l[env->scene.l_amt]);
	if (!parse_vec3(la, la->split[1], &(l->pos)))
		return (false);
	l->brightness = ft_atof(la->split[2]);
	if (l->brightness < 0 || l->brightness > 1)
		return (\
puterr_invalid_float(la, la->split[2], 0, 1), false);
	if (!parse_color(la, la->split[3], &(l->color)))
		return (false);
	env->scene.l_amt++;
	return (true);
}
