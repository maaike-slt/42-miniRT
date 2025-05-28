/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:05:51 by msloot            #+#    #+#             */
/*   Updated: 2025/05/28 23:04:11 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_pixel(t_img *img, t_color color, size_t index)
{
	size_t	real_index;

	real_index = index * 4;
	img->buf[real_index] = color.b;
	img->buf[real_index + 1] = color.g;
	img->buf[real_index + 2] = color.r;
	img->buf[real_index + 3] = color.a;
}

bool	render(t_env *env)
{
	t_color	color;
	color.r = 0xff;
	color.g = 0x00;
	color.b = 0x00;
	color.a = 1.0;

	set_pixel(&(env->pov[0]), color, (size_t)((env->win.w + 1) * env->win.h / 2));
	return (true);
}
