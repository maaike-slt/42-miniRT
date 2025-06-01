/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:54:45 by msloot            #+#    #+#             */
/*   Updated: 2025/06/01 14:20:45 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
/*
Cylinder:
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
  ∗ identifier: pl
  ∗ x, y, z coordinates of  a point in the plane: 0.0,0.0,-10.0
  ∗ 3D normalized vector of cylinder, in the range [-1,1] for each x, y, z axis:
    0.0,1.0,0.0
  ∗ the cylinder diameter: 14.2
  ∗ the cylinder height: 21.42
  ∗ R,G,B colors in the range [0-255]: 0, 0, 255
*/

bool	parse_cylinder(t_env *env, const t_line_arg *la)
{
	t_cylinder	*cy;

	if (la->split_size != 6)
		return (puterr_invalid_token_amount(\
la, 6, "<pos in x,y,z> <3D vector> <diameter> <height> <color in r,g,b>"), \
false);
	cy = &(env->scene.cy[env->scene.cy_amt]);
	if (!parse_vec3(la, la->split[1], &(cy->pos)))
		return (false);
	cy->vec = ft_atof(la->split[2]);
	if (cy->vec < -1 || cy->vec > 1)
		return (\
puterr_invalid_float(la, la->split[2], 0, 1), false);
	cy->diameter = ft_atof(la->split[3]);
	if (cy->diameter <= 0)
		return (\
puterr_invalid_float_positive_non_null(la, la->split[3]), false);
	cy->height = ft_atof(la->split[4]);
	if (cy->height <= 0)
		return (\
puterr_invalid_float_positive_non_null(la, la->split[4]), false);
	if (!parse_color(la, la->split[5], &(cy->color)))
		return (false);
	env->scene.cy_amt++;
	return (true);
}
