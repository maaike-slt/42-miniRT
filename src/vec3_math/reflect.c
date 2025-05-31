/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:50:51 by adelille          #+#    #+#             */
/*   Updated: 2025/05/31 10:54:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec3_reflect(const t_vec3 incident, const t_vec3 normal)
{
	float	dot;

	dot = vec3_dot(incident, normal);
	return ((t_vec3){
		incident.x - 2.0f * dot * normal.x,
		incident.y - 2.0f * dot * normal.y,
		incident.z - 2.0f * dot * normal.z
	});
}
