/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:48:59 by adelille          #+#    #+#             */
/*   Updated: 2025/06/01 14:11:41 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_scene(t_scene *scene)
{
	scene->a.color.r = 0xff;
	scene->a.color.g = 0xff;
	scene->a.color.b = 0xff;
	scene->a.lighting_ratio = 0.2f;
	scene->c = NULL;
	scene->c_amt = 0;
	scene->l = NULL;
	scene->l_amt = 0;
//	scene->tr = NULL;
	scene->tr_amt = 0;
	scene->pl = NULL;
	scene->pl_amt = 0;
	scene->sp = NULL;
	scene->sp_amt = 0;
	scene->cy = NULL;
	scene->cy_amt = 0;
}

bool	init(t_env *env)
{
	env->mlx = NULL;
	env->win.ptr = NULL;
	env->win.w = 1280;
	env->win.h = 720;
	init_scene(&env->scene);
	env->pov = NULL;
	env->mlx = mlx_init();
	if (!env->mlx)
		return (false);
	return (true);
}
