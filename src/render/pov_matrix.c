/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:43:35 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 12:06:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pov_matrix	pov_matrix(const t_camera *c)
{
	t_pov_matrix	ret;
	t_vec3			world_up;

	world_up = (t_vec3){0.0f, 1.0f, 0.0f};
	ret.forward = vec3_normalize(c->rot);
	if (fabsf(vec3_dot(ret.forward, world_up)) > 1.0f - FLOAT_PRECISION)
		world_up = (t_vec3){0.0f, 0.0f, 1.0f};
	ret.right = vec3_normalize(vec3_cross(ret.forward, world_up));
	ret.up = vec3_normalize(vec3_cross(ret.right, ret.forward));
	return (ret);
}
