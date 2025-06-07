/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:56:36 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 14:13:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_intersect_sphere_hit(t_env *env, t_intersect *hit)
{
	t_sphere	*sp;

	hit->t = env->rd.intersect.t;
	hit->type = SPHERE;
	hit->object = env->rd.intersect.object;
	sp = (t_sphere *)(hit->object);
	hit->pos = vec3_add(env->rd.ray.origin,
			vec3_scale(env->rd.ray.direction, hit->t));
	hit->normal = vec3_normalize(vec3_sub(hit->pos, sp->pos));
	hit->color = sp->color;
}

// discriminant = b^2 - 4ac = y^2 - 4xz

static bool	intersect_single_sphere(t_env *env, const t_sphere *sp)
{
	t_vec3	oc;
	t_vec3	d;
	float	discriminant;
	float	t0;
	float	t1;

	oc = vec3_sub(env->rd.ray.origin, sp->pos);
	d.x = vec3_dot(env->rd.ray.direction, env->rd.ray.direction);
	d.y = 2.0f * vec3_dot(oc, env->rd.ray.direction);
	d.z = vec3_dot(oc, oc) - sp->rad_sq;
	discriminant = (d.y * d.y) - (4 * d.x * d.z);
	if (discriminant < 0)
		return (false);
	discriminant = sqrtf(discriminant);
	d.x *= 2;
	d.y = -d.y;
	t0 = (d.y - discriminant) / d.x;
	if (t0 > FLOAT_PRECISION)
		return (keep_closest(env, t0));
	t1 = (d.y + discriminant) / d.x;
	if (t1 > FLOAT_PRECISION)
		return (keep_closest(env, t1));
	return (false);
}

bool	intersect_sphere(t_env *env)
{
	size_t	closest;
	size_t	i;

	closest = SIZE_MAX;
	i = 0;
	while (i < env->scene.sp_amt)
	{
		if (intersect_single_sphere(env, &(env->scene.sp[i])))
			closest = i;
		i++;
	}
	if (closest == SIZE_MAX)
		return (false);
	env->rd.intersect.type = SPHERE;
	env->rd.intersect.object = &(env->scene.sp[closest]);
	return (true);
}
