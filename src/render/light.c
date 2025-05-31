/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:30:55 by adelille          #+#    #+#             */
/*   Updated: 2025/05/31 00:07:57 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3	apply_ambient_light(t_color color, t_ambient ambient)
{
	return ((t_vec3){
		CR(color.r) * CR(ambient.color.r) * ambient.lighting_ratio,
		CR(color.g) * CR(ambient.color.g) * ambient.lighting_ratio,
		CR(color.b) * CR(ambient.color.b) * ambient.lighting_ratio
	});
}

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

	init_light_data(env, l, hit);
	if (intersect_all(env))
		return ;
	diffuse = fmaxf(vec3_dot(hit->normal, env->rd.ray.direction), 0.0f);
	diffuse *= l->brightness;
	color->x += diffuse * CR(l->color.r) * CR(hit->color.r);
	color->y += diffuse * CR(l->color.g) * CR(hit->color.g);
	color->z += diffuse * CR(l->color.b) * CR(hit->color.b);
}

t_color	compute_lighting(t_env *env, const t_intersect *hit)
{
	t_vec3	color;
	size_t	i;

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
