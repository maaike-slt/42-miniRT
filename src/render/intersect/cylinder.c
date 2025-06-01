/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:56:36 by adelille          #+#    #+#             */
/*   Updated: 2025/06/01 23:16:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3	get_cylinder_quadratic(const t_env *env, const t_cylinder *cy)
{
	t_vec3	oc;
	float	dir_dot_axis;
	float	oc_dot_axis;
	t_vec3	d;

	oc = vec3_sub(env->rd.ray.origin, cy->pos);
	dir_dot_axis = vec3_dot(env->rd.ray.direction, cy->normal);
	oc_dot_axis = vec3_dot(oc, cy->normal);
	d.x = 1.0f - dir_dot_axis * dir_dot_axis;
	d.y = 2.0f * (vec3_dot(oc, env->rd.ray.direction)
			- oc_dot_axis * dir_dot_axis);
	d.z = vec3_dot(oc, oc) - oc_dot_axis * oc_dot_axis
		- powf(cy->diameter / 2.0f, 2);
	return (d);
}

static float	solve_cylinder_quadratic(const t_env *env, const t_cylinder *cy)
{
	t_vec3	d;
	float	discriminant;
	t_vec2	t;
	t_vec2	h;

	d = get_cylinder_quadratic(env, cy);
	discriminant = (d.y * d.y) - (4 * d.x * d.z);
	if (discriminant < 0)
		return (-1.0f);
	discriminant = sqrtf(discriminant);
	t.x = (-d.y - discriminant) / (2 * d.x);
	t.y = (-d.y + discriminant) / (2 * d.x);
	h.x = vec3_dot(vec3_sub(
				vec3_add(env->rd.ray.origin,
					vec3_scale(env->rd.ray.direction, t.x)),
				cy->pos), cy->normal);
	h.y = vec3_dot(vec3_sub(
				vec3_add(env->rd.ray.origin,
					vec3_scale(env->rd.ray.direction, t.y)),
				cy->pos), cy->normal);
	if (h.x >= 0 && h.x <= cy->height && t.x > FLOAT_PRECISION)
		return (t.x);
	if (h.y >= 0 && h.y <= cy->height && t.y > FLOAT_PRECISION)
		return (t.y);
	return (-1.0f);
}

void	fill_intersect_cylinder_hit(t_env *env, t_intersect *hit)
{
	t_cylinder	*cy;
	t_vec2		t_cap;
	float		projection;

	hit->t = env->rd.intersect.t;
	hit->type = CYLINDER;
	hit->object = env->rd.intersect.object;
	cy = (t_cylinder *)(hit->object);
	hit->pos = vec3_add(env->rd.ray.origin,
			vec3_scale(env->rd.ray.direction, hit->t));
	t_cap.x = intersect_cylinder_cap_bottom(env, cy);
	t_cap.y = intersect_cylinder_cap_top(env, cy);
	if (t_cap.x != -1.0f && t_cap.x <= hit->t)
		hit->normal = vec3_normalize(vec3_sub(hit->pos, \
vec3_add(vec3_add(cy->pos, vec3_scale(cy->normal, cy->height)), cy->normal)));
	else if (t_cap.y != -1.0f && t_cap.y <= hit->t)
		hit->normal = vec3_normalize(vec3_sub(hit->pos, \
vec3_add(vec3_add(cy->pos, vec3_scale(cy->normal, -cy->height)), cy->normal)));
	else
	{
		projection = vec3_dot(vec3_sub(hit->pos, cy->pos), cy->normal);
		hit->normal = vec3_normalize(vec3_sub(hit->pos, \
vec3_add(cy->pos, vec3_scale(cy->normal, projection))));
	}
	hit->color = cy->color;
}

static bool	intersect_single_cylinder(t_env *env, const t_cylinder *cy)
{
	float	t;
	t_vec2	t_cap;

	t = solve_cylinder_quadratic(env, cy);
	t_cap.x = intersect_cylinder_cap_bottom(env, cy);
	t_cap.y = intersect_cylinder_cap_top(env, cy);
	if (t == -1.0f && t_cap.x == -1.0f && t_cap.y == -1.0f)
		return (false);
	if (t == -1.0f)
		t = INFINITY;
	if (t_cap.x == -1.0f)
		t_cap.x = INFINITY;
	if (t_cap.y == -1.0f)
		t_cap.y = INFINITY;
	return (keep_closest(env, fminf(t, fminf(t_cap.x, t_cap.y))));
}

bool	intersect_cylinder(t_env *env)
{
	size_t	closest;
	size_t	i;

	closest = SIZE_MAX;
	i = 0;
	while (i < env->scene.cy_amt)
	{
		if (intersect_single_cylinder(env, &(env->scene.cy[i])))
			closest = i;
		i++;
	}
	if (closest == SIZE_MAX)
		return (false);
	env->rd.intersect.type = CYLINDER;
	env->rd.intersect.object = &(env->scene.cy[closest]);
	return (true);
}
