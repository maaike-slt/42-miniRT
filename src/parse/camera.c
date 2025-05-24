/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:30:43 by msloot            #+#    #+#             */
/*   Updated: 2025/05/24 12:06:31 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Camera:
C -50.0,0,20 0,0,1 70
  ∗ identifier: C
  ∗ x, y, z coordinates of the viewpoint: -50.0,0,20
  ∗ 3D normalized orientation vector, in the range [-1,1]
    for each x, y, z axis: 0.0,0.0,1.0
  ∗ FOV: Horizontal field of view in degrees in the range [0,180]: 70
*/

bool	parse_camera(t_env *env, char **split, size_t size)
{
	t_camera	cam;

	if (size != 4)
		return (false); // TODO: @alex create print error function
	// TODO: create parse_vec()
	// cam.pos = parse_vec(split[1]);
	// cam.rot = parse_vec(split[2]);
	// TODO: create ftoa() + dtoa()
	// cam.fov = ftoa();
	// FIXME: env->schene.cam is not malloc
	env->scene.cam[env->scene.cam_amt] = cam;
	env->scene.cam_amt++;
	return (true);
}
