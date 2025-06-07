/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:05:51 by msloot            #+#    #+#             */
/*   Updated: 2025/06/07 16:23:48 by adelille         ###   ########.fr       */
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

static ssize_t	get_start_x(t_env *env, ssize_t d)
{
	if (d > (ssize_t)env->win.h - 1)
		return (d - ((ssize_t)env->win.h - 1));
	else
		return (0);
}

static ssize_t	get_end_x(t_env *env, ssize_t d)
{
	if (d < (ssize_t)env->win.w - 1)
		return (d);
	else
		return ((ssize_t)env->win.w - 1);
}

static void	render_pov(t_env *env)
{
	ssize_t	x;
	ssize_t	y;
	ssize_t	d;
	ssize_t	start_x;

	init_render_pov(env);
	putpov(env);
	d = 0;
	while (d < (ssize_t)env->win.w + (ssize_t)env->win.h - 1)
	{
		start_x = get_start_x(env, d);
		x = get_end_x(env, d);
		while (x >= start_x)
		{
			y = d - x;
			render_pixel(env, (size_t)x, (size_t)y);
			x--;
		}
		putpov(env);
		d++;
	}
	apply_anti_aliasing(env);
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
