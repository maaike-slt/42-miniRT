/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:05:51 by msloot            #+#    #+#             */
/*   Updated: 2025/05/29 22:32:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	render_pixel(t_env *env, size_t x, size_t y)
{
	init_render_pixel(env, x, y);
	float t = intersect_sphere(env->rd.c->pos, env->rd.ray_dir, env->scene.sp[0]);

	if (t > 0)
		set_pixel(env->rd.pov, env->scene.sp[0].color, y * env->win.w + x);
}

static void	render_pov(t_env *env)
{
	size_t	x;
	size_t	y;

	init_render_pov(env);
	y = 0;
	while (y < env->win.h)
	{
		x = 0;
		while (x < env->win.w)
		{
			render_pixel(env, x, y);
			x++;
		}
		y++;
	}
}

void	render(t_env *env)
{
	// TEMPORARY until sphere parsing is implemented
	env->scene.sp[0].pos = (t_vec3){0.0f, 0.0f, -3.0f};
	env->scene.sp[0].d = 2.0f;
	env->scene.sp[0].color = (t_color){0xff, 0x00, 0x00, 0xff};
	//
	init_render(env);
	env->rd.pov_index = 0;
	while (env->rd.pov_index < env->scene.c_amt)
	{
		render_pov(env);
		env->rd.pov_index++;
	}
}
