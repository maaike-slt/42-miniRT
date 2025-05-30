/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:01:21 by adelille          #+#    #+#             */
/*   Updated: 2025/05/29 22:08:58 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	calc_ray_direction(t_env *env, size_t x, size_t y)
{
	float	u;
	float	v;

	u = ((float)x + 0.5f) / (float)env->win.w;
	v = ((float)y + 0.5f) / (float)env->win.h;
	u = (u - 0.5f) * env->rd.viewport_w;
	v = (0.5f - v) * env->rd.viewport_h;
	return (vec3_normalize((t_vec3){
			env->rd.pov_matrix.forward.x
			+ env->rd.pov_matrix.right.x * u
			+ env->rd.pov_matrix.up.x * v,
			env->rd.pov_matrix.forward.y
			+ env->rd.pov_matrix.right.y * u
			+ env->rd.pov_matrix.up.y * v,
			env->rd.pov_matrix.forward.z
			+ env->rd.pov_matrix.right.z * u
			+ env->rd.pov_matrix.up.z * v}));
}
