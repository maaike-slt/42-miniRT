/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_basis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:43:35 by adelille          #+#    #+#             */
/*   Updated: 2025/05/29 21:01:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pov_matrix(t_camera *c, t_vec3 *right, t_vec3 *up, t_vec3 *forward)
{
	*forward = vec3_normalize(c->rot);
	*right = vec3_normalize(vec3_cross((t_vec3){0.0f, 1.0f, 0.0f}, *forward));
	*up = vec3_normalize(vec3_cross(*forward, *right));
}
