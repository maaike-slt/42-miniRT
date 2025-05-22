/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:05:51 by msloot            #+#    #+#             */
/*   Updated: 2025/05/22 21:39:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_pixel(t_img *img, t_pix pix, size_t	index)
{
	img->buf[index] = pix.b;
	img->buf[index + 1] = pix.g;
	img->buf[index + 2] = pix.r;
	img->buf[index + 3] = pix.a;
}

bool	render(t_env *env)
{
	size_t	cam_amt = 1;
	env->pov = (t_img *)malloc(sizeof(t_img) * cam_amt);
	if (!env->pov)
		return (free_env(&env));
	env->pov[0].ptr = mlx_new_image(env->mlx, env->win.w, env->win.h);
	env->pov[0].buf = mlx_get_data_addr(env->pov[0].ptr,
			&(env->pov[0].bpp), &(env->pov[0].size_line), &(env->pov[0].endian));

	t_pix pix;
	pix.r = 0xff;
	pix.g = 0x00;
	pix.b = 0x00;
	pix.a = 1.0;

	set_pixel(&(env->pov[0]), pix, (env->win.w * env->win.h / 2));
}
