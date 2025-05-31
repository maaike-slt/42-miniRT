/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:19:37 by adelille          #+#    #+#             */
/*   Updated: 2025/05/31 11:21:39 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO: do not malloc if size is 0
bool	init_object(t_env *env)
{
	env->scene.c = (t_camera *)malloc(sizeof(t_camera) * env->scene.c_amt);
	if (!env->scene.c)
		return (false);
	env->scene.l = (t_light *)malloc(sizeof(t_light) * env->scene.l_amt);
	if (!env->scene.l)
		return (false);
//	env->scene.tr =
// (t_triangle *)malloc(sizeof(t_triangle) * env->scene.tr_amt);
//	if (!env->scene.tr)
//		return (false);
//	env->scene.pl = (t_plane *)malloc(sizeof(t_plane) * env->scene.pl_amt);
//	if (!env->scene.pl)
//		return (false);
	env->scene.sp = (t_sphere *)malloc(sizeof(t_sphere) * env->scene.sp_amt);
	if (!env->scene.sp)
		return (false);
//	env->scene.cy =
//(t_cylinder *)malloc(sizeof(t_cylinder) * env->scene.cy_amt);
//	if (!env->scene.cy)
//		return (false);
	return (true);
}
