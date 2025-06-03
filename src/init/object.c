/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:19:37 by adelille          #+#    #+#             */
/*   Updated: 2025/06/03 20:01:31 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	malloc_object(void **ptr, size_t size, size_t amt)
{
	if (size == 0 || amt == 0)
	{
		*ptr = NULL;
		return (true);
	}
	*ptr = malloc(size * amt);
	if (!*ptr)
		return (false);
	return (true);
}

bool	init_object(t_env *env)
{
	if (!malloc_object((void **)&env->scene.c,
			sizeof(t_camera), env->scene.c_amt))
		return (false);
	if (!malloc_object((void **)&env->scene.l,
			sizeof(t_light), env->scene.l_amt))
		return (false);
	if (!malloc_object((void **)&env->scene.tr,
			sizeof(t_triangle), env->scene.tr_amt))
		return (false);
	if (!malloc_object((void **)&env->scene.pl,
			sizeof(t_plane), env->scene.pl_amt))
		return (false);
	if (!malloc_object((void **)&env->scene.sp,
			sizeof(t_sphere), env->scene.sp_amt))
		return (false);
	if (!malloc_object((void **)&env->scene.cy,
			sizeof(t_cylinder), env->scene.cy_amt))
		return (false);
	return (true);
}
