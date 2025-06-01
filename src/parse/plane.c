/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:35:34 by msloot            #+#    #+#             */
/*   Updated: 2025/06/01 13:46:28 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
/*
Plane:
pl  0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
  ∗ identifier: pl
  ∗ x, y, z coordinates of  a point in the plane: 0.0,0.0,-10.0
  ∗ 3D normalized normal vector, in the range [-1,1] for each x, y, z axis:
    0.0,1.0,0.0
  ∗ R,G,B colors in the range [0-255]: 0, 0, 255
*/

bool	parse_plane(t_env *env, const t_line_arg *la)
{
	t_plane	*pl;

	if (la->split_size != 4)
		return (puterr_invalid_token_amount(\
la, 4, "<pos in x,y,z> <3D vector> <color in r,g,b>"), false);
	pl = &(env->scene.pl[env->scene.pl_amt]);
	if (!parse_vec3(la, la->split[1], &(pl->pos)))
		return (false);
	pl->vec = ft_atof(la->split[2]);
	if (pl->vec < -1 || pl->vec > 1)
		return (\
puterr_invalid_float(la, la->split[2], 0, 1), false);
	if (!parse_color(la, la->split[3], &(pl->color)))
		return (false);
	env->scene.pl_amt++;
	return (true);
}
