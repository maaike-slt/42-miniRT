/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:13:10 by msloot            #+#    #+#             */
/*   Updated: 2025/06/03 20:54:37 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

/*
Square:
sq 0,25.5,-79.5 1,0,0 85 255,255,255
  ∗ identifier: sq
  ∗ x, y, z position coordinates
  ∗ 3D normalized vector of square, in the range [-1,1] for each x, y, z axis
  ∗ width
  ∗ R,G,B colors in the range [0-255]
*/

bool	parse_square(t_env *env, const t_line_arg *la)
{
	t_square	*sq;

	if (la->split_size != 5)
		return (puterr_invalid_token_amount(\
la, 5, "<pos in x,y,z> <normal in x,y,x> <width> <color in r,g,b>"), false);
	sq = &(env->scene.sq[env->scene.sq_amt]);
	if (!parse_vec3(la, la->split[1], &(sq->pos)))
		return (false);
	if (!parse_vec3(la, la->split[2], &(sq->normal)))
		return (false);
	sq->width = ft_atof(la->split[3]);
	if (sq->width <= 0)
		return (\
puterr_invalid_float_positive_non_null(la, la->split[3]), false);
	if (!parse_color(la, la->split[4], &(sq->color)))
		return (false);
	env->scene.sq_amt++;
	return (true);
}
