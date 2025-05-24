/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:48:59 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 16:12:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void init_scene(t_scene *scene)
{
	scene->c = NULL;
	scene->c_amt = 0;
//	scene->a = NULL;
//	scene->a_amt = 0;
//	scene->l = NULL;
//	scene->l_amt = 0;
//	scene->tr = NULL;
//	scene->tr_amt = 0;
//	scene->pl = NULL;
//	scene->pl_amt = 0;
//	scene->sp = NULL;
//	scene->sp_amt = 0;
//	scene->cy = NULL;
//	scene->cy_amt = 0;
}

bool	init(t_env *env)
{
	env->mlx = NULL;
	env->win.ptr = NULL;
	env->pov = NULL;
	init_scene(&env->scene);
	env->mlx = mlx_init();
	if (!env->mlx)
		return (false);
	return (true);
}

bool	init_pov(t_env *env)
{
	size_t	i;

	env->pov = (t_img *)malloc(sizeof(t_img) * env->scene.c_amt);
	if (!env->pov)
		return (false);
	i = 0;
	while (i < env->scene.c_amt)
	{
		env->pov[i].ptr = mlx_new_image(env->mlx, env->win.w, env->win.h);
		if (!env->pov[i].ptr)
			return (false);
		env->pov[i].buf = mlx_get_data_addr(env->pov[i].ptr,
				&(env->pov[i].bpp),
				&(env->pov[i].size_line),
				&(env->pov[i].endian));
		i++;
	}
	return (true);
}

bool	init_objects(t_env *env)
{
	env->scene.c = (t_camera *)malloc(sizeof(t_camera) * env->scene.c_amt);
	if (!env->scene.c)
		return (false);
//	env->scene.a = (t_ambient_light *)malloc(sizeof(t_ambient_light) * env->scene.a_amt);
//	if (!env->scene.a)
//		return (false);
//	env->scene.l = (t_light *)malloc(sizeof(t_light) * env->scene.l_amt);
//	if (!env->scene.l)
//		return (false);
//	env->scene.tr = (t_triangle *)malloc(sizeof(t_triangle) * env->scene.tr_amt);
//	if (!env->scene.tr)
//		return (false);
//	env->scene.pl = (t_plane *)malloc(sizeof(t_plane) * env->scene.pl_amt);
//	if (!env->scene.pl)
//		return (false);
//	env->scene.sp = (t_sphere *)malloc(sizeof(t_sphere) * env->scene.sp_amt);
//	if (!env->scene.sp)
//		return (false);
//	env->scene.cy = (t_cylinder *)malloc(sizeof(t_cylinder) * env->scene.cy_amt);
//	if (!env->scene.cy)
//		return (false);
	return (true);
}
