/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:48:59 by adelille          #+#    #+#             */
/*   Updated: 2025/05/31 00:06:51 by adelille         ###   ########.fr       */
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
//	scene->pl = NULL;
	scene->pl_amt = 0;
	scene->sp = NULL;
	scene->sp_amt = 0;
//	scene->cy = NULL;
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

static void	init_pov_pixel(t_env *env, t_img *pov)
{
	t_color	color;
	size_t	pov_size;
	size_t	pix_i;

	color = (t_color){
		CRR(CR(env->scene.a.color.r) * env->scene.a.lighting_ratio),
		CRR(CR(env->scene.a.color.g) * env->scene.a.lighting_ratio),
		CRR(CR(env->scene.a.color.b) * env->scene.a.lighting_ratio),
		0x80
	};
	pov_size = env->win.w * env->win.h;
	pix_i = 0;
	while (pix_i < pov_size)
	{
		set_pixel(pov, color, pix_i);
		pix_i++;
	}
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
		env->pov[i].buf = (t_color_bit *)mlx_get_data_addr(env->pov[i].ptr,
				&(env->pov[i].bpp),
				&(env->pov[i].size_line),
				&(env->pov[i].endian));
		init_pov_pixel(env, &(env->pov[i]));
		i++;
	}
	return (true);
}

// TODO: do not malloc if size is 0
bool	init_objects(t_env *env)
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
