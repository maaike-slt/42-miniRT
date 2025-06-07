/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:30:55 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 14:08:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_light_data(t_env *env, const t_light *l, t_intersect *hit)
{
	t_vec3			to_light;

	to_light = vec3_sub(l->pos, hit->pos);
	env->rd.ray.origin = hit->pos;
	if (vec3_dot(to_light, hit->normal) < 0.0f)
		hit->normal = vec3_negate(hit->normal);
	env->rd.ray.direction = vec3_normalize(to_light);
	env->rd.intersect.t = vec3_magnitude(to_light);
}

static void	compute_single_light(
	t_env *env, t_intersect *hit, const t_light *l, t_vec3 *color)
{
	float	diffuse;
	float	specular;

	init_light_data(env, l, hit);
	if (intersect_all(env))
		return ;
	diffuse = fmaxf(vec3_dot(hit->normal, env->rd.ray.direction), 0.0f);
	diffuse *= l->brightness;
	specular = compute_specular(env, hit, l);
	color->x += (diffuse * cr(hit->color.r) + specular) * cr(l->color.r);
	color->y += (diffuse * cr(hit->color.g) + specular) * cr(l->color.g);
	color->z += (diffuse * cr(hit->color.b) + specular) * cr(l->color.b);
}

t_color	compute_lighting(t_env *env, t_intersect *hit)
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
		.r = crr(fminf(color.x, 1.0f)),
		.g = crr(fminf(color.y, 1.0f)),
		.b = crr(fminf(color.z, 1.0f)),
		.a = 0xff
	});
}
