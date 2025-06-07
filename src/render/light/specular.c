/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:04:09 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 18:38:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	compute_specular(
	t_env *env, const t_intersect *hit, const t_light *l)
{
	t_vec3	reflect_direction;
	float	specular;

	reflect_direction = \
vec3_reflect(vec3_negate(env->rd.ray.direction), hit->normal);
	specular = fmaxf(vec3_dot(reflect_direction, env->rd.view_direction), 0.0f);
	return (powf(specular, l->shininess)
		* l->brightness
		* fmaxf(l->shininess / DEFAULT_SHININESS, 1.0f));
}
