/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:56:02 by msloot            #+#    #+#             */
/*   Updated: 2025/06/03 20:54:37 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

/*
Sphere:
sp 0.0,0.0,20.6 12.6 10,0,255
  ∗ identifier: sp
  ∗ x, y, z coordinates of the sphere center: 0.0,0.0,20.6
  ∗ the sphere diameter: 12.6
  ∗ R,G,B colors in the range [0-255]: 10, 0, 255
*/

bool	parse_sphere(t_env *env, const t_line_arg *la)
{
	t_sphere	*sp;
	float		diameter;

	if (la->split_size != 4)
		return (puterr_invalid_token_amount(\
la, 4, "<pos in x,y,z> <diameter> <color in r,g,b>"), false);
	sp = &(env->scene.sp[env->scene.sp_amt]);
	if (!parse_vec3(la, la->split[1], &(sp->pos)))
		return (false);
	diameter = ft_atof(la->split[2]);
	if (diameter <= 0)
		return (\
puterr_invalid_float_positive_non_null(la, la->split[2]), false);
	sp->rad_sq = powf(diameter / 2.0f, 2.0f);
	if (!parse_color(la, la->split[3], &(sp->color)))
		return (false);
	env->scene.sp_amt++;
	return (true);
}
