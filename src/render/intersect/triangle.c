/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:56:36 by adelille          #+#    #+#             */
/*   Updated: 2025/06/05 22:50:41 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static inline void	get_triangle_edges(
	const t_triangle *tr, t_vec3 *edge_ab, t_vec3 *edge_ac)
{
	*edge_ab = vec3_sub(tr->pos_b, tr->pos_a);
	*edge_ac = vec3_sub(tr->pos_c, tr->pos_a);
}

void	fill_intersect_triangle_hit(t_env *env, t_intersect *hit)
{
	t_triangle	*tr;
	t_vec3		edge_ac;
	t_vec3		edge_ab;

	hit->t = env->rd.intersect.t;
	hit->type = TRIANGLE;
	hit->object = env->rd.intersect.object;
	tr = (t_triangle *)(hit->object);
	hit->pos = vec3_add(env->rd.ray.origin,
			vec3_scale(env->rd.ray.direction, hit->t));
	get_triangle_edges(tr, &edge_ab, &edge_ac);
	hit->normal = vec3_normalize(vec3_scale(vec3_cross(edge_ab, edge_ac), -1.0f));
	hit->color = tr->color;
}

static bool	intersect_single_triangle(t_env *env, const t_triangle *tr)
{
	t_triangle_intersect	ti;
	float					t;

	get_triangle_edges(tr, &(ti.edge_ab), &(ti.edge_ac));
	ti.cross_p = vec3_cross(env->rd.ray.direction, ti.edge_ac);
	ti.determinant = vec3_dot(ti.edge_ab, ti.cross_p);
	if (fabsf(ti.determinant) < FLOAT_PRECISION)
		return (false);
	ti.determinant = 1.0f / ti.determinant;
	ti.t_vec = vec3_sub(env->rd.ray.origin, tr->pos_a);
	ti.u = vec3_dot(ti.t_vec, ti.cross_p) * ti.determinant;
	if (ti.u < 0.0f || ti.u > 1.0f)
		return (false);
	ti.cross_q = vec3_cross(ti.t_vec, ti.edge_ab);
	ti.v = vec3_dot(env->rd.ray.direction, ti.cross_q) * ti.determinant;
	if (ti.v < 0.0f || ti.u + ti.v > 1.0f)
		return (false);
	t = vec3_dot(ti.edge_ac, ti.cross_q) * ti.determinant;
	if (t < FLOAT_PRECISION)
		return (false);
	return (keep_closest(env, t));
}

bool	intersect_triangle(t_env *env)
{
	size_t	closest;
	size_t	i;

	closest = SIZE_MAX;
	i = 0;
	while (i < env->scene.tr_amt)
	{
		if (intersect_single_triangle(env, &(env->scene.tr[i])))
			closest = i;
		i++;
	}
	if (closest == SIZE_MAX)
		return (false);
	env->rd.intersect.type = TRIANGLE;
	env->rd.intersect.object = &(env->scene.tr[closest]);
	return (true);
}
