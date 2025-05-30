/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:43:35 by adelille          #+#    #+#             */
/*   Updated: 2025/05/29 22:26:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pov_matrix	pov_matrix(const t_camera *c)
{
	t_pov_matrix	ret;
	float			yaw;
	float			pitch;

	yaw = c->rot.y * M_PI / 180.0f;
	pitch = c->rot.x * M_PI / 180.0f;
	ret.forward = vec3_normalize((t_vec3){
			sinf(yaw) * cosf(pitch),
			sinf(pitch),
			-cosf(yaw) * cosf(pitch)});
	ret.right = vec3_normalize(vec3_cross(
				ret.forward,
				(t_vec3){0.0f, 1.0f, 0.0f}));
	ret.up = vec3_normalize(vec3_cross(
				ret.right,
				ret.forward));
	return (ret);
}
