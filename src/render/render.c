/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:05:51 by msloot            #+#    #+#             */
/*   Updated: 2025/06/07 00:23:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	render_pixel(t_env *env, size_t x, size_t y)
{
	t_intersect	camera_hit;

	init_render_pixel(env, x, y);
	if (!intersect_all(env))
		return ;
	fill_intersect_hit(env, &camera_hit);
	set_pixel(
		env->rd.pov,
		compute_lighting(env, &camera_hit),
		y * env->win.w + x);
}

static void	render_pov(t_env *env)
{
	size_t	x;
	size_t	y;

	init_render_pov(env);
	putpov(env);
	y = 0;
	while (y < env->win.h)
	{
		x = 0;
		while (x < env->win.w)
		{
			render_pixel(env, x, y);
			x++;
		}
		putpov(env);
		y++;
	}
}

void	render(t_env *env)
{
	init_render(env);
	env->pov_index = 0;
	while (env->pov_index < env->scene.c_amt)
	{
		render_pov(env);
		env->pov_index++;
	}
	env->pov_index = 0;
	putpov(env);
}
