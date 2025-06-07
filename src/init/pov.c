/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:19:52 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 18:00:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_pov_pixel(t_env *env, t_img *pov)
{
	size_t	pov_size;
	size_t	pix_i;

	env->rd.ambient_color = get_ambient_color(env);
	pov_size = env->win.w * env->win.h;
	pix_i = 0;
	while (pix_i < pov_size)
	{
		set_pixel(pov, env->rd.ambient_color, pix_i);
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
