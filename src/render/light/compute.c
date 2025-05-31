/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:30:55 by adelille          #+#    #+#             */
/*   Updated: 2025/05/31 11:05:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_light_data(
	t_env *env, const t_light *l, const t_intersect *hit)
{
	t_vec3			to_light;

	to_light = vec3_sub(l->pos, hit->pos);
	env->rd.ray.origin = vec3_add(hit->pos,
			vec3_scale(hit->normal, FLOAT_PRECISION));
	env->rd.ray.direction = vec3_normalize(to_light);
	env->rd.intersect.t = vec3_magnitude(to_light);
}

static void	compute_single_light(
	t_env *env, const t_intersect *hit, const t_light *l, t_vec3 *color)
{
	float	diffuse;
	float	specular;

	init_light_data(env, l, hit);
	if (intersect_all(env))
		return ;
	diffuse = fmaxf(vec3_dot(hit->normal, env->rd.ray.direction), 0.0f);
	diffuse *= l->brightness;
	specular = compute_specular(env, hit, l);
	color->x += (diffuse * CR(hit->color.r) + specular) * CR(l->color.r);
	color->y += (diffuse * CR(hit->color.g) + specular) * CR(l->color.g);
	color->z += (diffuse * CR(hit->color.b) + specular) * CR(l->color.b);
}

t_color	compute_lighting(t_env *env, const t_intersect *hit)
{
	t_vec3	color;
	size_t	i;

	env->rd.view_direction = vec3_normalize(
			vec3_scale(env->rd.ray.direction, -1.0f));
	color = apply_ambient_light(hit->color, env->scene.a);
	i = 0;
	while (i < env->scene.l_amt)
	{
		compute_single_light(env, hit, &(env->scene.l[i]), &color);
		i++;
	}
	return ((t_color){
		.r = CRR(fminf(color.x, 1.0f)),
		.g = CRR(fminf(color.y, 1.0f)),
		.b = CRR(fminf(color.z, 1.0f)),
		.a = 0xff
	});
}
