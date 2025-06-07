/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:05:14 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 17:57:25 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_ambient_color(const t_env *env)
{
	return ((t_color){
		crr(cr(env->scene.a.color.r) * env->scene.a.lighting_ratio),
		crr(cr(env->scene.a.color.g) * env->scene.a.lighting_ratio),
		crr(cr(env->scene.a.color.b) * env->scene.a.lighting_ratio),
		0x80
	});
}

t_vec3	apply_ambient_light(t_color color, t_ambient ambient)
{
	return ((t_vec3){
		cr(color.r) * cr(ambient.color.r) * ambient.lighting_ratio,
		cr(color.g) * cr(ambient.color.g) * ambient.lighting_ratio,
		cr(color.b) * cr(ambient.color.b) * ambient.lighting_ratio
	});
}
