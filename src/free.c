/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:43:32 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 15:52:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_scene(t_scene *scene)
{
	if (scene->c)
		free(scene->c);
//	if (scene->a)
//		free(scene->a);
//	if (scene->l)
//		free(scene->l);
//	if (scene->tr)
//		free(scene->tr);
//	if (scene->pl)
//		free(scene->pl);
//	if (scene->sp)
//		free(scene->sp);
//	if (scene->cy)
//		free(scene->cy);
}

static void	free_pov(t_env *env)
{
	size_t	i;

	if (!env->pov)
		return ;
	i = 0;
	while (i < env->scene.cam_amt && env->pov[i].ptr)
	{
		mlx_destroy_image(env->mlx, env->pov[i].ptr);
		i++;
	}
	free(env->pov);
}

int	free_env(t_env *env)
{
	free_pov(env);
	if (env->mlx && env->win.ptr)
		mlx_destroy_window(env->mlx, env->win.ptr);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	return (1);
}
