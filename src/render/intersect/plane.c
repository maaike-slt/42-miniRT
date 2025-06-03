/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:56:36 by adelille          #+#    #+#             */
/*   Updated: 2025/06/01 16:16:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_intersect_plane_hit(t_env *env, t_intersect *hit)
{
	t_plane	*pl;

	hit->t = env->rd.intersect.t;
	hit->type = PLANE;
	hit->object = env->rd.intersect.object;
	pl = (t_plane *)(hit->object);
	hit->pos = vec3_add(env->rd.ray.origin,
			vec3_scale(env->rd.ray.direction, hit->t));
	hit->normal = pl->normal;
	hit->color = pl->color;
}

static bool	intersect_single_plane(t_env *env, const t_plane *pl)
{
	float	denom;
	float	t;

	denom = vec3_dot(pl->normal, env->rd.ray.direction);
	if (fabsf(denom) < FLOAT_PRECISION)
		return (false);
	t = vec3_dot(vec3_sub(pl->pos, env->rd.ray.origin), pl->normal) / denom;
	if (t > FLOAT_PRECISION)
		return (keep_closest(env, t));
	return (false);
}

bool	intersect_plane(t_env *env)
{
	size_t	closest;
	size_t	i;

	closest = SIZE_MAX;
	i = 0;
	while (i < env->scene.pl_amt)
	{
		if (intersect_single_plane(env, &(env->scene.pl[i])))
			closest = i;
		i++;
	}
	if (closest == SIZE_MAX)
		return (false);
	env->rd.intersect.type = PLANE;
	env->rd.intersect.object = &(env->scene.pl[closest]);
	return (true);
}
