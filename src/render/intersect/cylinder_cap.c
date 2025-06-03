/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:39:40 by adelille          #+#    #+#             */
/*   Updated: 2025/06/01 22:48:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	solve_cylinder_cap(
	t_env *env, const t_cylinder *cy, float t_cap)
{
	float	k;
	t_vec3	cap_point;
	t_vec3	to_center;
	float	dist_sq;

	k = vec3_dot(cy->normal, env->rd.ray.direction);
	if (k == 0)
		k = FLOAT_PRECISION;
	t_cap /= k;
	if (t_cap < FLOAT_PRECISION)
		return (-1.0f);
	cap_point = vec3_add(env->rd.ray.origin,
			vec3_scale(env->rd.ray.direction, t_cap));
	to_center = vec3_sub(cap_point, cy->pos);
	dist_sq = vec3_dot(to_center, to_center) - vec3_dot(to_center, cy->normal)
		* vec3_dot(to_center, cy->normal);
	if (dist_sq <= powf(cy->diameter / 2.0f, 2))
		return (t_cap);
	return (-1.0f);
}

float	intersect_cylinder_cap_bottom(t_env *env, const t_cylinder *cy)
{
	return (solve_cylinder_cap(env, cy,
			vec3_dot(cy->normal, vec3_sub(cy->pos, env->rd.ray.origin))));
}

float	intersect_cylinder_cap_top(t_env *env, const t_cylinder *cy)
{
	return (solve_cylinder_cap(env, cy,
			vec3_dot(cy->normal,
				vec3_sub(vec3_add(cy->pos, vec3_scale(cy->normal, cy->height)),
					env->rd.ray.origin))));
}
