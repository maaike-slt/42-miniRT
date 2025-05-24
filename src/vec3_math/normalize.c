/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:36:28 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 20:44:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_vec3	vec3_normalize(t_vec3 v)
{
	float	magnitude;

	magnitude = vec3_magnitude(v);
	if (magnitude == 0.0f)
		return ((t_vec3){0.0f, 0.0f, 0.0f});
	return ((t_vec3){
		.x = v.x / magnitude,
		.y = v.y / magnitude,
		.z = v.z / magnitude
	});
}
