/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:56:36 by adelille          #+#    #+#             */
/*   Updated: 2025/05/29 19:05:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	intersect_sphere(t_vec3 ray_ori, t_vec3 ray_dir, t_sphere sp)
{
    t_vec3 oc = vec3_sub(ray_ori, sp.pos);
    float a = vec3_dot(ray_dir, ray_dir);
    float b = 2.0f * vec3_dot(oc, ray_dir);
	float rad = sp.d / 2.0f;
    float c = vec3_dot(oc, oc) - (rad * rad);
    float disc = (b * b) - (4 * a * c);

    if (disc < 0) {
		return -1.0f;
	}

    float sqrt_disc = sqrtf(disc);
    float t0 = (-b - sqrt_disc) / (2 * a);
    float t1 = (-b + sqrt_disc) / (2 * a);

    if (t0 > 0)
		return t0;
    else if (t1 > 0)
		return t1;
    else
		return -1.0f;
}
