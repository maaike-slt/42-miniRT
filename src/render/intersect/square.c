/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:56:36 by adelille          #+#    #+#             */
/*   Updated: 2025/06/03 21:36:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_intersect_square_hit(t_env *env, t_intersect *hit)
{
	t_square	*sq;

	hit->t = env->rd.intersect.t;
	hit->type = SQUARE;
	hit->object = env->rd.intersect.object;
	sq = (t_square *)(hit->object);
	hit->pos = vec3_add(env->rd.ray.origin,
			vec3_scale(env->rd.ray.direction, hit->t));
	hit->normal = sq->normal;
	hit->color = sq->color;
}

static bool	intersect_single_square(t_env *env, const t_square *sq)
{
	float	t;
	float	rad;
	t_vec3	ab;

	t = solve_plane_intersection(env, sq->pos, sq->normal);
	if (t == -1.0f)
		return (false);
	rad = sq->width / 2.0f;
	ab = vec3_sub(vec3_add(env->rd.ray.origin,
				vec3_scale(env->rd.ray.direction, t)), sq->pos);
	if (fabsf(ab.x) > rad || fabsf(ab.y) > rad || fabsf(ab.z) > rad)
		return (false);
	return (keep_closest(env, t));
}

bool	intersect_square(t_env *env)
{
	size_t	closest;
	size_t	i;

	closest = SIZE_MAX;
	i = 0;
	while (i < env->scene.sq_amt)
	{
		if (intersect_single_square(env, &(env->scene.sq[i])))
			closest = i;
		i++;
	}
	if (closest == SIZE_MAX)
		return (false);
	env->rd.intersect.type = SQUARE;
	env->rd.intersect.object = &(env->scene.sq[closest]);
	return (true);
}
