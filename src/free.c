/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:43:32 by adelille          #+#    #+#             */
/*   Updated: 2025/05/30 22:35:25 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_scene(t_env *env)
{
	if (env->scene.c)
		free(env->scene.c);
	if (env->scene.l)
		free(env->scene.l);
//	if (env->scene.tr)
//		free(env->scene.tr);
//	if (env->scene.pl)
//		free(env->scene.pl);
	if (env->scene.sp)
		free(env->scene.sp);
//	if (env->scene.cy)
//		free(env->scene.cy);
}

static void	free_pov(t_env *env)
{
	size_t	i;

	if (!env->pov)
		return ;
	i = 0;
	while (i < env->scene.c_amt && env->pov[i].ptr)
	{
		mlx_destroy_image(env->mlx, env->pov[i].ptr);
		i++;
	}
	free(env->pov);
}

int	free_env(t_env *env)
{
	free_pov(env);
	free_scene(env);
	if (env->mlx && env->win.ptr)
		mlx_destroy_window(env->mlx, env->win.ptr);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	return (1);
}
