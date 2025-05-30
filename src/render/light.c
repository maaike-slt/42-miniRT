/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:30:55 by adelille          #+#    #+#             */
/*   Updated: 2025/05/30 23:45:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3	apply_ambient_light(t_color color, t_ambient ambient)
{
	return (t_vec3){
		(color.r / 0xff) * (ambient.color.r / 0xff) * ambient.lighting_ratio,
		(color.g / 0xff) * (ambient.color.g / 0xff) * ambient.lighting_ratio,
		(color.b / 0xff) * (ambient.color.b / 0xff) * ambient.lighting_ratio
	};
}

static void	init_light_data(
	t_env *env, const t_light *l, const t_intersect *hit)
{
	t_vec3			to_light;

	to_light = vec3_sub(l->pos, hit->pos);
	env->rd.ray.origin = vec3_add(hit->pos,
			vec3_scale(hit->normal, FLOAT_PRECISION));
	env->rd.ray.direction = vec3_normalize(to_light);
	env->rd.intersect.t = vec3_magnitude(to_light);;
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
	color->x += diffuse * (l->color.r / 0xff) * (hit->color.r / 0xff);
	color->y += diffuse * (l->color.g / 0xff) * (hit->color.g / 0xff);
	color->z += diffuse * (l->color.b / 0xff) * (hit->color.b / 0xff);
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
		.r = (t_color_bit)(fminf(color.x, 1.0f) * 0xff),
		.g = (t_color_bit)(fminf(color.y, 1.0f) * 0xff),
		.b = (t_color_bit)(fminf(color.z, 1.0f) * 0xff),
		.a = 0xff
	});
}
