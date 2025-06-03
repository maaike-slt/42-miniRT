/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:50:54 by msloot            #+#    #+#             */
/*   Updated: 2025/06/03 20:51:25 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

/*
Triangle:
tr  0.0,0.0,21.1 0.0,42.2,0.0 -82.3,0.0,0.0 10,0,255
  ∗ identifier: tr
  ∗ x, y, z coordinates of point a
  ∗ x, y, z coordinates of point b
  ∗ x, y, z coordinates of point c
  ∗ R,G,B colors in the range [0-255]: 10, 0, 255
*/

bool	parse_triangle(t_env *env, const t_line_arg *la)
{
	t_triangle	*tr;

	if (la->split_size != 5)
		return (puterr_invalid_token_amount(\
la, 5, "<pos in x,y,z> <pos in x,y,z> <pos in x,y,z> <color in r,g,b>"), false);
	tr = &(env->scene.tr[env->scene.tr_amt]);
	if (!parse_vec3(la, la->split[1], &(tr->pos_a)))
		return (false);
	if (!parse_vec3(la, la->split[2], &(tr->pos_b)))
		return (false);
	if (!parse_vec3(la, la->split[3], &(tr->pos_c)))
		return (false);
	if (!parse_color(la, la->split[4], &(tr->color)))
		return (false);
	env->scene.tr_amt++;
	return (true);
}
