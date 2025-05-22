/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:05:51 by msloot            #+#    #+#             */
/*   Updated: 2025/05/22 22:26:58 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_pixel(t_img *img, t_pix pix, size_t	index)
{
	size_t	real_index;

	real_index = index * 4;
	img->buf[real_index] = pix.b;
	img->buf[real_index + 1] = pix.g;
	img->buf[real_index + 2] = pix.r;
	img->buf[real_index + 3] = pix.a;
}

bool	render(t_env *env)
{
	t_pix	pix;
	pix.r = 0xff;
	pix.g = 0x00;
	pix.b = 0x00;
	pix.a = 1.0;

	set_pixel(&(env->pov[0]), pix, (size_t)((env->win.w + 1) * env->win.h / 2));
	return (true);
}
