/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:05:14 by adelille          #+#    #+#             */
/*   Updated: 2025/05/31 11:09:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	apply_ambient_light(t_color color, t_ambient ambient)
{
	return ((t_vec3){
		cr(color.r) * cr(ambient.color.r) * ambient.lighting_ratio,
		cr(color.g) * cr(ambient.color.g) * ambient.lighting_ratio,
		cr(color.b) * cr(ambient.color.b) * ambient.lighting_ratio
	});
}
