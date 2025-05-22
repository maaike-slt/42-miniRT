/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:48:59 by adelille          #+#    #+#             */
/*   Updated: 2025/05/22 22:03:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init(t_env *env)
{
	env->mlx = NULL;
	env->win.ptr = NULL;
	env->pov = NULL;
	env->mlx = mlx_init();
	if (!env->mlx)
		return (false);
	return (true);
}

bool	init_pov(t_env *env)
{
	size_t	i;

	env->pov = (t_img *)malloc(sizeof(t_img) * env->scene.cam_amt);
	if (!env->pov)
		return (false);
	i = 0;
	while (i < env->scene.cam_amt)
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
