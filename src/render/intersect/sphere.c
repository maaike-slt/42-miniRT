/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:56:36 by adelille          #+#    #+#             */
/*   Updated: 2025/05/30 12:07:16 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static inline bool	keep_closest(t_env *env, float t)
{
	if (t < env->rd.intersect.t)
	{
		env->rd.intersect.t = t;
		return (true);
	}
	return (false);
}

static bool	intersect_single_sphere(const t_env *env, const t_sphere *sp)
{
	t_vec3	oc;
	t_vec3	d;
	float	discriminant;
	float	t0;
	float	t1;

	oc = vec3_sub(env->rd.ray.origin, sp->pos);
	d.a = vec3_dot(env->rd.ray.direction, env->rd.ray.direction);
	d.b = 2.0f * vec3_dot(oc, env->rd.ray.direction);
	d.c = vec3_dot(oc, oc) - sp->rad_sq;
	discriminant = (d.b * d.b) - (4 * d.a * d.c);
	if (discriminant < 0)
		return (false);
	discriminant = sqrtf(discriminant);
	d.a *= 2;
	d.b = -d.b;
	t0 = (d.b - discriminant) / d.a;
	if (t0 > FLOAT_PRECISION)
		return (keep_closest(env, t0));
	t1 = (d.b + discriminant) / d.a;
	if (t1 > FLOAT_PRECISION)
		return (keep_closest(env, t1));
	return (false);
}

void	intersect_sphere(t_env *env)
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
		return ;
	env->rd.intersect.pos = vec3_add(env->rd.ray.origin,
			vec3_scale(env->rd.ray.direction, env->rd.intersect.t));
	env->rd.intersect.normal = vec3_normalize(
			vec3_sub(env->rd.intersect.pos, env->scene.sp[closest].pos));
	env->rd.intersect.color = env->scene.sp[closest].color;
}
